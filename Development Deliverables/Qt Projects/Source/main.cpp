
#include <QApplication>
#include <QString>
#include <QObject>
#include <map>
#include "mgen.h"
#include "model.h"
#include <QXmlStreamWriter>
#include <QFile>
#include <QFileDevice>
#include <QDebug>
#include "sgen.h"
#include "saver.h"
//#include "saver.cpp"

#include "loader.h"
#include "lgen.h"
#include "parse.h"
#include "mainwindow.h"

#include <QTextEdit>
#include <QLineEdit>


using namespace std;

//easier to type by defining pair
typedef std::pair<QString,QString> datapair;


int main(int argc, char *argv[])
{

    string savername("saver");
    string modelname("model");
    string loadername("loader");


    //UNCOMMENT THIS PART TO ADD MORE FIELD AND GENERATE THE MODEL.h
    Parser parser;
    map<std::pair<QString,QString>,QString> m;

    parser.parseXML(m);


    MGen mgen(m,string("../COMP523ProjectQTParamCp/"));
    mgen.generateClass();



    LGen<std::pair<QString,QString>,QString> load(m,modelname,string("../COMP523ProjectQTParamCp/"),loadername);
    load.generateClass();

    SGen save(m,modelname,string("../COMP523ProjectQTParamCp/"),savername);
    save.generateClass();
}





//QApplication main do not remove
//int main(int argc, char *argv[])
//{
//    using namespace std;

//    QApplication a(argc, argv);

//    MainWindow w;
//    model m;
//    w.setModel(m);
//    w.show();

//    return a.exec();
//}



//TESTING PURPOSE VOID POINTER DO NOT REMOVE
//    long along(123);
//    //QString s("hello");
//    string s("98");

//    //qDebug()<<QString::fromStdString(to_string(typeid(along)==typeid(int)));

//    void * pointer=&s;
//    //qDebug()<<QString::fromStdString(to_string(typeid(pointer)==typeid(int)));

//    try{
//        long* l=static_cast<long*> (pointer);

//        qDebug()<<QString::fromStdString(to_string(sizeof(s)));

//    } catch(...) {
//        qDebug()<<"OOPS";

//    }

