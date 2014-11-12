#ifndef SGEN_H
#define SGEN_H

//define file name is not already done
#ifndef SAVERFILENAME
#define SAVERFILENAME "../COMP523ProjectQTParamCp/saver.h"
#endif

#ifndef INCLUDEHEADER
#define INCLUDEHEADER "#include"
#endif

//Define the header of the class
#define SAVERCLASSHEADER \
    "class Saver {"

//Termination character
#define SAVERCLASSTERMINATE\
    "};"


//Includes

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <set>

#include <iostream>
#include <QDebug>
#include <QTextEdit>

#include <QXmlStreamWriter>



using namespace std;


//Class used to strip data from the dictionary and streams into a cpp file current in
//the same directory
template <class K, class V>
class SGen{
    const map<K,V> & hmap;
    //file stream to print out to model file
    std::ofstream savestream;
    //headers that have been used
    std::set<QString> usedHeader;

    QString & filename;

public:

    //constructor
    SGen(map<K,V> & hmap, QString & filename=QString("saver.h")):hmap(hmap), filename(filename){


    }

    //destructor
    ~SGen(){


    }

    //METHODS

    //Outputs the hmap into the Saver.h
    void generateClass() {
        savestream.open(SAVERFILENAME,ios::out);

        try{
            if(savestream.is_open()) {
                genMethodLine("#ifndef SAVER_H",0);
                genMethodLine("#define SAVER_H",0);

                //generate the includes
                genIncludes(savestream);

                //print class keyword and the class name
                savestream << SAVERCLASSHEADER<<endl;



                //generate the field
                genField(savestream);



                //make getter and setters public
                savestream <<endl<< "public: "<<endl<<endl;

                //generate save method
                genMethod();


                savestream<<"};"<<endl;

                genMethodLine("#endif",0);

            }
        }catch(...) {
            cout<<"Output to model cpp file failed"<<endl;

        }

        savestream.close();
    }


private:
    void genIncludes(ofstream & savestream) {
        savestream<<INCLUDEHEADER<<" <QXmlStreamWriter>"<<endl;
        savestream<<INCLUDEHEADER<<" <QFile>"<<endl<<endl;
        savestream<<INCLUDEHEADER<<" <QString>"<<endl<<endl;
        savestream<<INCLUDEHEADER<<" <string>"<<endl<<endl;

    }


    //generates fields
    void genField(ofstream & savestream){



    }



    //generate the save method in the saver
    void genMethod() {
        //get iterator from begin
        map<K,V>::const_iterator it=hmap.begin();

        //used to determine amount of tab needed to properly indent this line
        int tab_index=1;

        //generate method signature
        genMethodLine("void save(Model& model) {",tab_index);
        tab_index++;

        //generate the file
        genMethodLine("//First, address the appropriate instantiate",tab_index);
        genMethodLine("QFile file(\"data.xml\");",tab_index);

        //open the file
        genMethodLine("if(!file.open(QIODevice::WriteOnly)){",tab_index);
        //write lines in error handling
        genMethodLine("//handle file open errors here ",tab_index+1);
        genMethodLine(" qDebug()<<file.exists();",tab_index+1);
        genMethodLine("}\n",tab_index);

        //generate the xml writer
        genMethodLine("QXmlStreamWriter writer(&file);\n",tab_index);

        //call method that actually writes each field in model to xml file
        genMethodLine("//write each field stored in model into xml",tab_index);
        genMethodLine("saveToXML(model,writer);\n",tab_index);

        genMethodLine("}\n\n",--tab_index);

        genSavetoXMLMethod(it, savestream,tab_index);
    }

    //generate each line of method, indented. Also, puts ; at end. Default is one tab
    void genMethodLine(string s,int tab_amount=1) {

        for(tab_amount;tab_amount>0;tab_amount--)
            savestream<<"\t";

        savestream<<s<<endl;
    }

    void genSavetoXMLMethod(typename map<K,V>::const_iterator & it, ofstream & savestream, int tab_index) {
        //first generate the method signature
        genMethodLine("void saveToXML(Model& model,QXmlStreamWriter& writer){\n",tab_index);

        tab_index++;
        //generate xml headers
        genMethodLine("writer.setAutoFormatting(true);\n",tab_index);

        //start document
        genMethodLine("writer.writeStartDocument();\n",tab_index);

        bool void_pointer=false;
        //recusively generate the tag for data
        while(it != hmap.end()) {
            //generate
            genMethodLine("writer.writeEmptyElement(\"Data\");",tab_index);

            //Type attribute
            genMethodLine("writer.writeAttribute(\"type\",\""+string(it->second.toUtf8().constData())+"\");",tab_index);

            //convert qstring to string
            genMethodLine("writer.writeAttribute(\"name\",\""+string(it->first.second.toUtf8().constData())+"\");",tab_index);




            //qDebug()<<QString::fromStdString(to_string(it->second.compare(QString("QString"))));

            //value attribute generation

            //saves data, falls under different cases
            if(it->second.compare(QString("string"))==0) {
                //convert to qstring first
                genMethodLine("writer.writeAttribute(\"value\",QString::fromStdString(model.get"+string(it->first.second.toUtf8().constData())+"()));",tab_index);

            } else if(it->second.compare(QString("QString"))==0) {
                //can just output the qstring
                genMethodLine("writer.writeAttribute(\"value\",model.get"+string(it->first.second.toUtf8().constData())+"());",tab_index);


            } else {
                //extremely bad way to do this

                //convert all data type with same size as long or less to a long and print as string
                if(!void_pointer) {
                    genMethodLine("//Enagaging hacky void pointer method of saving",tab_index);

                    //void can be used as an intermediate to convert anything to another type
                    //genMethodLine("void* pointer;",tab_index);

                    //now it exists, don't need to redeclare
                    void_pointer=true;
                }

                //genMethodLine("pointer=reinterpret_cast<void*>(&model.get"+string(it->first.second.toUtf8().constData())+"());",tab_index);

                //check if the value object is less or equal to the long type. We can save it as a long. Else discard
                genMethodLine("if(sizeof(model.get"+string(it->first.second.toUtf8().constData())+"())<=sizeof(long)) {\n",tab_index++);
                genMethodLine("//Don't care about the value, as long as it is less in memory size than an long, we can save it as a long",tab_index);

                //convert to string
                genMethodLine("writer.writeAttribute(\"value\",QString::fromStdString(std::to_string(model.get"+string(it->first.second.toUtf8().constData())+"())));",tab_index--);

                // genMethodLine("writer.writeAttribute(\"value\",QString::fromStdString(std::to_string(*(static_cast<long*>(pointer)))));",tab_index--);
                genMethodLine("} else {",tab_index++);
                //else for error handling
                genMethodLine("//Generate error if the value is too big to fit",tab_index);
                genMethodLine("writer.writeAttribute(\"value\",\"Error: Invalid attribute value\");",tab_index--);
                genMethodLine("}",tab_index);


            }


            //genMethodLine("if(sizeof(model.get"+string(it->first.second.toUtf8().constData())+"))));",tab_index);
            //genMethodLine("writer.writeAttribute(\"value\",QString::fromStdString(to_string(static_cast<long long> (model.get"+string(it->first.second.toUtf8().constData())+"))));",tab_index);



            genMethodLine("writer.writeEndElement();\n",tab_index);

            it++;
        }

        //end document
        genMethodLine("writer.writeEndDocument();\n",tab_index);

        tab_index--;
        //close the method
        genMethodLine("}",tab_index);

    }



};



#endif // SGEN_H
