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
    std::ofstream savestream;
    //headers that have been used
    std::set<QString> usedHeader;

    QString & filename;

public:

    //constructor
    SGen(map<std::pair<QString,QString>,QString> & hmap, QString & filename=QString("saver.h"));

    //destructor
    ~SGen();

    //METHODS

    //Outputs the hmap into the Saver.h
    void generateClass() ;


private:
    //generate the include files the saver needs
    void genIncludes(ofstream & savestream);

    //generates fields
    void genField(ofstream & savestream);

    //generate the save method in the saver
    void genMethod();

    //generate each line of method, indented. Also, puts ; at end. Default is one tab
    void genMethodLine(string s,int tab_amount=1);

    //method to generate the saver method to write out the model values upon save
    void genSavetoXMLMethod(map<std::pair<QString,QString>,QString>::const_iterator & it, int tab_index);



};



#endif // SGEN_H
