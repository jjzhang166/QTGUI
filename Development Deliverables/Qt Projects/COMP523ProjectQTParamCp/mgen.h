#ifndef MGEN_H
#define MGEN_H

//define file name is not already done
#ifndef MODELFILENAME
#define MODELFILENAME "../COMP523ProjectQTParamCp/model.h"
#endif



//Define the header of the class
#define CLASSHEADER \
    "class Model {"

//Termination character
#define TERMINATECHAR\
    "}"

//Head for the setters
#define SETTERHEAD\
    "void set"


//Includes

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <set>

#include <iostream>
#include <QDebug>
#include <QTextEdit>



using namespace std;


//Class used to strip data from the dictionary and streams into a cpp file current in
//the same directory
template <class K, class V>
class MGen{
    const map<K,V> & hmap;
    //file stream to print out to model file
    std::ofstream modelstream;
    //headers that have been used
    std::set<QString> usedHeader;

public:

    //constructor
    MGen(map<K,V> & hmap):hmap(hmap){


    }

    //destructor
    ~MGen(){


    }

    //METHODS

    //Outputs the hmap into the Model.cpp
    void generateClass() {
        modelstream.open(MODELFILENAME,ios::out);
        try{
            if(modelstream.is_open()) {

                modelstream<<"#ifndef MODEL_H"<<endl;
                modelstream<<"#define MODEL_H"<<endl<<endl;

                //generate the includes
                genIncludes(modelstream);

                //print class keyword and the class name
                modelstream << CLASSHEADER<<endl;



                //generate the field
                genField(modelstream);



                //make getter and setters public
                modelstream <<endl<< "public: "<<endl<<endl;

                genGetSet(modelstream);


                modelstream<<"};"<<endl<<endl;
                modelstream<<"#endif"<<endl;
            }
        }catch(...) {
            cout<<"Output to model cpp file failed"<<endl;

        }

        modelstream.close();
    }


private:
    void genIncludes(ofstream & modelstream) {
        //get iterator from begin
        map<K,V>::const_iterator it=hmap.begin();


        while(it != hmap.end()) {

            qDebug()<<string("QString").compare(it->second.toUtf8().constData());

            //compare the value type to the header QString for now, see if both are same string, aka when compare returns 0
            if(string("QString").compare(it->second.toUtf8().constData())==0 &&

                    //try to find the header first
                    (usedHeader.find(it->second.toUtf8().constData()) == usedHeader.end())) {

                modelstream<<"#include <"<<it->second.toUtf8().constData()
                         <<">"<<endl<<endl;

                //put into set
                usedHeader.insert(it->second.toUtf8().constData());
            }

            it++;
        }

    }


    //generates fields
    void genField(ofstream & modelstream){
        //get iterator from begin
        map<K,V>::const_iterator it=hmap.begin();


        while(it != hmap.end()) {

            modelstream<<"\t"<<it->second.toUtf8().constData()<<" "
                     <<it->first.second.toUtf8().constData()<<";"<<endl;



            it++;
        }


    }


    void genGetSet(ofstream & modelstream) {
        //get iterator from begin
        map<K,V>::const_iterator it=hmap.begin();

        //while the point did not hit the end of the map
        while(it != hmap.end()) {

            //getter
            genGet(it,modelstream);



            //setter
            genSet(it,modelstream);

            it++;
        }

    }

    void genGet(typename map<K,V>::const_iterator & it, ofstream & modelstream) {
        //generate Type getVarName();
        modelstream<<"\t"<<it->second.toUtf8().constData()<<" "
                 <<"get"
                <<it->first.second.toUtf8().constData()<<"(){"<<endl;

        //generate body of getter
        modelstream<<"\t\treturn "<<
                    it->first.second.toUtf8().constData()<<";"<<endl;

        //end it
        modelstream<<"\t}"<<endl;

    }

    void genSet(typename map<K,V>::const_iterator & it, ofstream & modelstream) {
        //generate Type setVarName(Type a);
        modelstream<<"\tvoid "
                 <<"set"
                <<it->first.second.toUtf8().constData()<<"("
               <<it->second.toUtf8().constData()
              <<" a"
             <<"){"<<endl;

        //generate body of setter
        modelstream<<"\t\t"<<
                    it->first.second.toUtf8().constData()<<"=a;"
                 <<endl;

        //end it
        modelstream<<"\t}"<<endl;

    }



};


#endif // MGEN_H
