#include "sgen.h"


//constructor
SGen:: SGen(map<std::pair<QString,QString>,QString> & hmap,string modelclass, string directory,string filename)
    :hmap(hmap),directory(directory), filename(filename),modelclass(modelclass){


}

//destructor
SGen::~SGen(){


}

//METHODS

//Outputs the hmap into the Saver.h
void SGen::generateClass() {
    std::ofstream savehstream;
    savehstream.open(this->directory+this->filename+".h",ios::out);



    qDebug()<<QString::fromStdString(this->directory+this->filename+".h");

    try{
        if(savehstream.is_open()) {
            genMethodLine(savehstream,"#ifndef SAVER_H",0);
            genMethodLine(savehstream,"#define SAVER_H",0);

            //generate the includes
            genIncludes(savehstream);

            //print class keyword and the class name
            savehstream << "class "<<filename<<"{ "<<endl;



            //generate the field
            genField(savehstream);



            //make getter and setters public
            savehstream <<endl<< "public: "<<endl<<endl;

            //generate save method
            genMethod(savehstream, true);


            savehstream<<"};"<<endl;

            genMethodLine(savehstream,"#endif",0);

        }
    }catch(...) {
        cout<<"Output to model cpp file failed"<<endl;

    }

    savehstream.close();


    std::ofstream savesstream;
    savesstream.open(this->directory+this->filename+".cpp",ios::out);

    try{
        if(savesstream.is_open()) {
            genMethodLine(savesstream,"#include \""+this->filename+".h\"",0);

            //generate save method
            genMethod(savesstream, false);

        }
    }catch(...) {
        cout<<"Output to model cpp file failed"<<endl;

    }

    savesstream.close();
}



void SGen::genIncludes(ofstream & savehstream) {
    savehstream<<INCLUDEHEADER<<" <QXmlStreamWriter>"<<endl;
    savehstream<<INCLUDEHEADER<<" <QFile>"<<endl<<endl;
    savehstream<<INCLUDEHEADER<<" <QString>"<<endl<<endl;
    savehstream<<INCLUDEHEADER<<" <string>"<<endl<<endl;
    savehstream<<INCLUDEHEADER<<" \""+this->modelclass+".h\";"<<endl<<endl;

}


//generates fields
void SGen::genField(ofstream & savehstream){



}



//generate the save method in the saver
void SGen::genMethod(ofstream & savestream, bool isHeader) {
    //get iterator from begin
    map<std::pair<QString,QString>,QString>::const_iterator it=hmap.begin();

    //used to determine amount of tab needed to properly indent this line
    int tab_index=1;

    //generate method signature
    genMethodLine(savestream,"void "+(isHeader? ("save("+this->modelclass+"& m);")
                                             :(filename+"::save("+this->modelclass+"& m){")),tab_index);


    //do not generate the rest if not header
    if(isHeader) {
        genSavetoXMLMethod(savestream,it, tab_index, isHeader);
        return;

    }

    tab_index++;

    //generate the file
    genMethodLine(savestream,"//First, address the appropriate instantiate",tab_index);
    genMethodLine( savestream,"QFile file(\"data.xml\");",tab_index);

    //open the file
    genMethodLine(savestream,"if(!file.open(QIODevice::WriteOnly)){",tab_index);
    //write lines in error handling
    genMethodLine(savestream,"//handle file open errors here ",tab_index+1);
    genMethodLine(savestream," qDebug()<<file.exists();",tab_index+1);
    genMethodLine(savestream,"}\n",tab_index);

    //generate the xml writer
    genMethodLine(savestream,"QXmlStreamWriter writer(&file);\n",tab_index);

    //call method that actually writes each field in model to xml file
    genMethodLine(savestream,"//write each field stored in model into xml",tab_index);
    genMethodLine(savestream,"saveToXML(m,writer);\n",tab_index);

    genMethodLine(savestream,"}\n\n",--tab_index);

    genSavetoXMLMethod(savestream,it, tab_index, isHeader);
}

//generate each line of method, indented. Also, puts ; at end. Default is one tab
void SGen::genMethodLine(ofstream & savestream,string s,int tab_amount) {

    for(tab_amount;tab_amount>0;tab_amount--)
        savestream<<"\t";

    savestream<<s<<endl;
}

void SGen::genSavetoXMLMethod(ofstream & savestream,map<std::pair<QString,QString>,QString>::const_iterator & it, int tab_index, bool isHeader) {


    //first generate the method signature
    genMethodLine(savestream,"void "+(isHeader? ("saveToXML("+this->modelclass+"& m,QXmlStreamWriter& writer);"
                                       ):(filename+string("::saveToXML("+this->modelclass+"& m,QXmlStreamWriter& writer){\n"))),tab_index);

    if(isHeader) {
            return;

    }

    tab_index++;
    //generate xml headers
    genMethodLine(savestream,"writer.setAutoFormatting(true);\n",tab_index);

    //start document
    genMethodLine(savestream,"writer.writeStartDocument();\n\n",tab_index);

    //parent namespace and
    genMethodLine(savestream,"writer.writeStartElement(\"m:ModelData\");",tab_index);
    genMethodLine(savestream,"writer.writeNamespace(\"https://github.com/QTGUIFolks/QTGUI\",\"m\");",tab_index);



    bool void_pointer=false;
    //recusively generate the tag for data
    while(it != hmap.end()) {

        //generate
        genMethodLine(savestream,"writer.writeEmptyElement(\"m:Data\");",tab_index);

        //Type attribute
        genMethodLine(savestream,"writer.writeAttribute(\"type\",\""+string(it->second.toUtf8().constData())+"\");",tab_index);

        //convert qstring to string
        genMethodLine(savestream,"writer.writeAttribute(\"name\",\""+string(it->first.second.toUtf8().constData())+"\");",tab_index);




        //qDebug()<<QString::fromStdString(to_string(it->second.compare(QString("QString"))));

        //value attribute generation

        //saves data, falls under different cases
        if(it->second.compare(QString("string"))==0) {
            //convert to qstring first
            genMethodLine(savestream,"writer.writeAttribute(\"value\",QString::fromStdString(m.get"+string(it->first.second.toUtf8().constData())+"()));",tab_index);

        } else if(it->second.compare(QString("QString"))==0) {
            //can just output the qstring
            genMethodLine(savestream,"writer.writeAttribute(\"value\",m.get"+string(it->first.second.toUtf8().constData())+"());",tab_index);


        } else {
            //extremely bad way to do this

            //convert all data type with same size as long or less to a long and print as string
            if(!void_pointer) {
                genMethodLine(savestream,"//Enagaging hacky void pointer method of saving",tab_index);

                //void can be used as an intermediate to convert anything to another type
                //genMethodLine("void* pointer;",tab_index);

                //now it exists, don't need to redeclare
                void_pointer=true;
            }

            //genMethodLine("pointer=reinterpret_cast<void*>(&m.get"+string(it->first.second.toUtf8().constData())+"());",tab_index);

            //check if the value object is less or equal to the long type. We can save it as a long. Else discard
            genMethodLine(savestream,"if(sizeof(m.get"+string(it->first.second.toUtf8().constData())+"())<=sizeof(long)) {\n",tab_index++);
            genMethodLine(savestream,"//Don't care about the value, as long as it is less in memory size than an long, we can save it as a long",tab_index);

            //convert to string
            genMethodLine(savestream,"writer.writeAttribute(\"value\",QString::fromStdString(std::to_string(m.get"+string(it->first.second.toUtf8().constData())+"())));",tab_index--);

            // genMethodLine("writer.writeAttribute(\"value\",QString::fromStdString(std::to_string(*(static_cast<long*>(pointer)))));",tab_index--);
            genMethodLine(savestream,"} else {",tab_index++);
            //else for error handling
            genMethodLine(savestream,"//Generate error if the value is too big to fit",tab_index);
            genMethodLine(savestream,"writer.writeAttribute(\"value\",\"Error: Invalid attribute value\");",tab_index--);
            genMethodLine(savestream,"}",tab_index);


        }


        //genMethodLine("if(sizeof(m.get"+string(it->first.second.toUtf8().constData())+"))));",tab_index);
        //genMethodLine("writer.writeAttribute(\"value\",QString::fromStdString(to_string(static_cast<long long> (m.get"+string(it->first.second.toUtf8().constData())+"))));",tab_index);


        it++;
    }

    genMethodLine(savestream,"writer.writeEndElement();\n",tab_index);

    //end document
    genMethodLine(savestream,"writer.writeEndDocument();\n",tab_index);

    tab_index--;
    //close the method
    genMethodLine(savestream,"}",tab_index);

}


