
#include <QApplication>
#include <QString>
#include <QObject>
#include <map>
#include "mgen.h"
#include "model.h"
#include "sgen.h"
#include <QXmlStreamWriter>
#include <QFile>
#include <QFileDevice>
#include <QDebug>
#include "sgen.h"
#include "saver.h"
#include "loader.h"
#include "lgen.h"
#include "parse.h"
#include "mainwindow.h"

#include <QTextEdit>
#include <QLineEdit>


using namespace std;

//easier to type by defining pair
typedef std::pair<QString,QString> datapair;


//int main(int argc, char *argv[])
//{


//    //UNCOMMENT THIS PART TO ADD MORE FIELD AND GENERATE THE MODEL.h
//    Parser parser;
//    map<std::pair<QString,QString>,QString> m;

//    parser.parseXML(m);


//    MGen mgen(m);
//    mgen.generateClass();



//    //LGen<std::pair<QString,QString>,QString> load(m);
//    //load.generateClass();

//    //SGen save(m);
//    //save.generateClass();
//}

//    //GENERATE AND INSERT DATA INTO DATA.xml, which is the xml generated form the input model

//    //instantiate the saver and model
//    //    Saver saver;
//    //    Loader loader;
//    //    Model m;

//    //    //put in some fake data
//    //    m.setcheckBoxBool(QString("AQString"));
//    //    m.settextBoxString1("AString");
//    //    m.settextBoxString4(0);

//    //    //saver will write out all the fields into the model file
//    //    saver.save(m);
//    //    loader.load(m);

//    //    qDebug()<<m.getcheckBoxBool();
//    //    qDebug()<<QString::fromStdString(m.gettextBoxString1());
//    //    qDebug()<<m.gettextBoxString2();
//    //    qDebug()<<QString::fromStdString(to_string(m.gettextBoxString4()));


//    return 0;
//}




//QApplication main do not remove
int main(int argc, char *argv[])
{
    using namespace std;

    QApplication a(argc, argv);

    MainWindow w;
    Model model;
    w.setModel(model);
    w.show();

    return a.exec();
}



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

