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
class SGen{

    const map<std::pair<QString,QString>,QString> & hmap;
    //file stream to print out to model file

    //headers that have been used
    std::set<QString> usedHeader;

    string filename;
    string directory;
    string modelclass;

public:

    //constructor
    SGen(map<std::pair<QString,QString>,QString> & hmap,string modelclass,string directory=string("")
            ,string filename=string("saver"));

    //destructor
    ~SGen();

    //METHODS

    //Outputs the hmap into the Saver.h
    void generateClass() ;


private:
    //generate the include files the saver needs
    void genIncludes(ofstream & savehstream);

    //generates fields
    void genField(ofstream & savehstream);

    //generate the save method in the saver
    void genMethod(ofstream & savehstream,bool isHeader);

    //generate each line of method, indented. Also, puts ; at end. Default is one tab
    void genMethodLine(ofstream & savestream,string s,int tab_amount=1);

    //method to generate the saver method to write out the model values upon save
    void genSavetoXMLMethod(ofstream & savestream,map<std::pair<QString,QString>,QString>::const_iterator & it, int tab_index, bool isHeader);



};



#endif // SGEN_H
