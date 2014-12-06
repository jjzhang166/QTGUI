
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


int main(int argc, char *argv[])
{
    //default info
    string savername;
    string modelname;
    string loadername;
    string directory;
    string uifileuri;

    //arguments info
    //-d directory
    //-m modelname
    //-l loadername
    //-s savername
    //-u uifileuri
    int i=0;
    for(;i<argc;i++) {
        if(i+1>=argc) {
           break;

        }
        if(!std::strcmp(argv[i],"-d")) {
            directory=string(argv[++i],sizeof(argv[++i]));

        }else if(!std::strcmp(argv[i],"-m")) {
            modelname=string(argv[++i],sizeof(argv[++i]));

        }else if(!std::strcmp(argv[i],"-l")) {
            loadername=string(argv[++i],sizeof(argv[++i]));

        }else if(!std::strcmp(argv[i],"-s")) {
            savername=string(argv[++i],sizeof(argv[++i]));

        }else if(!std::strcmp(argv[i],"-u")) {
            uifileuri=string(argv[++i],sizeof(argv[++i]));

        }

    }

    //UNCOMMENT THIS PART TO ADD MORE FIELD AND GENERATE THE MODEL.h
    Parser parser(uifileuri);
    map<std::pair<QString,QString>,QString> m;

    parser.parseXML(m);

    qDebug()<<"yes";

    MGen mgen(m,string("../COMP523QTParamCp/"));
    mgen.generateClass();

    LGen load(m,modelname,directory,loadername);
    load.generateClass();

    SGen save(m,modelname,directory,savername);
    save.generateClass();
}





////QApplication main do not remove
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


