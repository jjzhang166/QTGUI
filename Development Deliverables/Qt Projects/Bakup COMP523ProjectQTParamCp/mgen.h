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
#include <QString>

using namespace std;


//Class used to strip data from the dictionary and streams into a cpp file current in
//the same directory
class MGen{
    const map<std::pair<QString,QString>,QString> & hmap;

    //headers that have been used
    std::set<QString> usedHeader;

    //name of the header file to be generated
    QString & filename;

public:

    //constructor
    MGen(map<std::pair<QString,QString>,QString> & hmap,QString & filename=QString("model.h"));

    //destructor
    ~MGen();

    //METHODS

    //called to generate the whole class
    void generateClass();

private:

    //generate the apprpriate includes, used by genHeader
    void genIncludes(ofstream& headerstream);

    //generate the associated header file
    void genHeader(ofstream& headerstream);

    //generate the source file
    void genSource(ofstream& sourcestream);


    //generates fields
    void genField(ofstream & headerstream);

    void genGetSet(ofstream & stream,bool headeronly);

    void genGet(map<std::pair<QString,QString>,QString>::const_iterator & it, ofstream & stream,bool headeronly);

    void genSet(map<std::pair<QString,QString>,QString>::const_iterator & it, ofstream & stream,bool headeronly);



};


#endif // MGEN_H
