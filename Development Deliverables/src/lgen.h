#ifndef LGEN_H
#define LGEN_H

#include <QFile>
#include <QDebug>
#include <QString>
#include <string>

using namespace std;

class LGen{

    map<std::pair<QString,QString>,QString> & m;

    string filename;
    string modelclass;
    string directory;

public:
    //    //constructor
    LGen(map<std::pair<QString,QString>,QString> & hmap, string modelclass, string directory="",string filename="loader");

    void generateClass();


};


#endif // LGEN_H
