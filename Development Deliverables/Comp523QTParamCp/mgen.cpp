#include "mgen.h"

//constructor
MGen::MGen(map<std::pair<QString,QString>,QString> & hmap,string directory,string filename)
    :hmap(hmap),filename(filename),directory(directory){
}

//destructor
MGen::~MGen(){


}

//METHODS

//Outputs the hmap into the Model.cpp
void MGen::generateClass() {
    std::ofstream headerstream;
    headerstream.open(directory+filename+".h",ios::out);

    qDebug()<<QString::fromStdString(directory+filename+".h");

    try{
        if(headerstream.is_open()) {
            genHeader(headerstream);

        }
    }catch(...) {
        cout<<"Output to model cpp file failed"<<endl;

    }

    headerstream.close();

    std::ofstream sourcestream;
    sourcestream.open(directory+filename+".cpp",ios::out);

    try{
        if(sourcestream.is_open()) {
            genSource(sourcestream);

        }
    }catch(...) {
        cout<<"Output to model cpp file failed"<<endl;

    }

    sourcestream.close();

}

void MGen::genHeader(ofstream & headerstream) {
    headerstream<<"#ifndef "+this->filename+"_H"<<endl;
    headerstream<<"#define "+this->filename+"_H"<<endl<<endl;

    //generate the includes
    genIncludes(headerstream);

    //print class keyword and the class name
    headerstream << "class "<<this->filename<<" {"<<endl;

    //generate the field
    genField(headerstream);

    //make getter and setters public
    headerstream <<endl<< "public: "<<endl<<endl;

    genGetSet(headerstream,true);

    headerstream<<"};"<<endl<<endl;
    headerstream<<"#endif"<<endl;

}

void MGen::genSource(ofstream & sourcestream){
    sourcestream<<"#include \""+this->filename+".h\";"<<endl<<endl;

    genGetSet(sourcestream,false);

}


void MGen::genIncludes(ofstream & headerstream) {
    //get iterator from begin
    map<std::pair<QString,QString>,QString>::const_iterator it=hmap.begin();


    while(it != hmap.end()) {


        //compare the value type to the header QString for now, see if both are same string, aka when compare returns 0
        if(string("QString").compare(it->second.toUtf8().constData())==0 &&

                //try to find the header first
                (usedHeader.find(it->second.toUtf8().constData()) == usedHeader.end())) {

            headerstream<<"#include <"<<it->second.toUtf8().constData()
                      <<">"<<endl<<endl;

            //put into set
            usedHeader.insert(it->second.toUtf8().constData());
        }

        it++;
    }

}


//generates fields
void MGen::genField(ofstream & headerstream){
    //get iterator from begin
    map<std::pair<QString,QString>,QString>::const_iterator it=hmap.begin();


    while(it != hmap.end()) {

        headerstream<<"\t"<<it->second.toUtf8().constData()<<" "
                  <<it->first.second.toUtf8().constData()<<";"<<endl;



        it++;
    }


}


void MGen::genGetSet(ofstream & headerstream,bool headeronly) {
    //get iterator from begin
    map<std::pair<QString,QString>,QString>::const_iterator it=hmap.begin();

    //while the point did not hit the end of the map
    while(it != hmap.end()) {

        //getter
        genGet(it,headerstream,headeronly);



        //setter
        genSet(it,headerstream,headeronly);

        it++;
    }

}

void MGen::genGet(map<std::pair<QString,QString>,QString>::const_iterator & it, ofstream & stream,bool headeronly) {
    //generate Type getVarName();
   stream<<"\t"<<it->second.toUtf8().constData()<<" "<<(headeronly?"":this->filename+"::")
              <<"get"
             <<it->first.second.toUtf8().constData()<<"()";

    //Now depending on whether we are generating header or not
    if(headeronly) {
        stream<<";"<<endl;
        //exit, cause no need to generate the rest unless we are messing with source
        return;
    } else {
        stream<<"{"<<endl;

    }

    //generate body of getter
    stream<<"\t\treturn "<<
                 it->first.second.toUtf8().constData()<<";"<<endl;

    //end it
    stream<<"\t}"<<endl;

}

void MGen::genSet(map<std::pair<QString,QString>,QString>::const_iterator & it, ofstream & stream, bool headeronly) {
    //generate Type setVarName(Type a);
    stream<<"\tvoid "<<(headeronly?"":this->filename+"::")
              <<"set"
             <<it->first.second.toUtf8().constData()<<"("
            <<it->second.toUtf8().constData()
           <<" a"
          <<")";

    //Now depending on whether we are generating header or not
    if(headeronly) {
        stream<<";"<<endl<<endl;
        return;

    } else {
        stream<<"{"<<endl;

    }

    //generate body of setter
    stream<<"\t\t"<<
                 it->first.second.toUtf8().constData()<<"=a;"
              <<endl;

    //end it
    stream<<"\t}"<<endl;

}








