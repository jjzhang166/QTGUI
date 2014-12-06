
#include <QApplication>
#include <QString>
#include <QObject>
#include "mgen.h"
#include "model.h"
#include <QXmlStreamWriter>
#include <QFile>
#include <QFileDevice>
#include <QDebug>
#include "sgen.h"
#include "saver.h"

#include "lgen.h"
#include "loader.h"

#include "parse.h"
#include "mainwindow.h"

#include <QTextEdit>
#include <QLineEdit>


using namespace std;

//easier to type by defining pair
typedef std::pair<QString,QString> datapair;


//int main(int argc, char *argv[])
//{

//    string savername("saver");
//    string modelname("model");
//    string loadername("loader");


//    //UNCOMMENT THIS PART TO ADD MORE FIELD AND GENERATE THE MODEL.h
//    Parser parser;
//    map<std::pair<QString,QString>,QString> m;

//    parser.parseXML(m);


//    MGen mgen(m,string("../COMP523ProjectQTParamCp/"));
//    mgen.generateClass();



//    LGen load(m,modelname,string("../COMP523ProjectQTParamCp/"),loadername);
//    load.generateClass();

//    SGen save(m,modelname,string("../COMP523ProjectQTParamCp/"),savername);
//    save.generateClass();
//}





//QApplication main do not remove
int main(int argc, char *argv[])
{
    using namespace std;

    QApplication a(argc, argv);

    MainWindow w;
    model m;
    w.setModel(m);
    w.show();

    return a.exec();
}


