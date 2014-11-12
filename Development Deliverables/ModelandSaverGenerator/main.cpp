#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QObject>
#include <map>
#include "mgen.h"
#include "Model.h"
#include <QXmlStreamWriter>
#include <QFile>
#include <QFileDevice>
#include <QDebug>
#include "sgen.h"
#include "Saver.h"
#include <type_traits>
#include <ostream>
#include <malloc.h>


using namespace std;

//easier to type by defining pair
typedef std::pair<QString,QString> datapair;


int main(int argc, char *argv[])
{


//UNCOMMENT THIS PART TO ADD MORE FIELD AND GENERATE THE MODEL.h

//        map<datapair,QString> m;

//        //Test data in the
//        m.insert(std::pair<datapair,QString>(datapair("QTextBox","textBoxString1"),"string"));
//        m.insert(std::pair<datapair,QString>(datapair("QTextBox","textBoxString2"),"QString"));
//        m.insert(std::pair<datapair,QString>(datapair("QCheckBox","checkBoxBool"),"QString"));
//        m.insert(std::pair<datapair,QString>(datapair("QTextBox","textBoxString4"),"bool"));
//         //m.insert(std::pair<datapair,QString>(datapair("QCheckBox","checkBox"),"QString"));

//    MGen<std::pair<QString,QString>,QString> mgen(m);
//    mgen.generateClass();

//    SGen<std::pair<QString,QString>,QString> save(m);
//    save.generateClass();


    //GENERATE AND INSERT DATA INTO DATA.xml, which is the xml generated form the input model

    //instantiate the saver and model
    Saver saver;
    Model m;

    //put in some fake data
    m.setcheckBoxBool(QString("AQString"));
    m.settextBoxString1("AString");
    m.settextBoxString4(0);

    //saver will write out all the fields into the model file
    saver.save(m);

    return 0;
}




//QApplication main do not remove
//int main(int argc, char *argv[])
//{
//    using namespace std;

//    QApplication a(argc, argv);


//    map<datapair,QString> m;

//    //Test data in the
//    m.insert(std::pair<datapair,QString>(datapair("QTextBox","textBoxString1"),"QString"));
//    m.insert(std::pair<datapair,QString>(datapair("QTextBox","textBoxString2"),"QString"));
//    m.insert(std::pair<datapair,QString>(datapair("QCheckBox","checkBoxBool"),"bool"));
//    m.insert(std::pair<datapair,QString>(datapair("QTextBox","textBoxString4"),"QString"));
//     //m.insert(std::pair<datapair,QString>(datapair("QCheckBox","checkBox"),"bool"));

//    MGen<datapair,QString> ab(m);
//    ab.generateClass();

//    Model model;
//   model.settextBoxString2(QString("This will work"));
//    qDebug()<<model.gettextBoxString2();

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

