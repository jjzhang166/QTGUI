
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


void runFirstWorkFlow(int argc, char* argv[]) {
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
            i++;
            directory=string(argv[i],strlen(argv[i]));

        }else if(!std::strcmp(argv[i],"-m")) {
            i++;
            modelname=string(argv[i],strlen(argv[i]));

        }else if(!std::strcmp(argv[i],"-l")) {
            i++;
            loadername=string(argv[i],strlen(argv[i]));

        }else if(!std::strcmp(argv[i],"-s")) {
            i++;
            savername=string(argv[i],strlen(argv[i]));

        }else if(!std::strcmp(argv[i],"-u")) {
            i++;
            uifileuri=string(argv[i],strlen(argv[i]));

        }

    }

    //UNCOMMENT THIS PART TO ADD MORE FIELD AND GENERATE THE MODEL.h
    Parser parser(uifileuri);
    map<std::pair<QString,QString>,QString> m;

    parser.parseXML(m);

    qDebug()<<"yes";

    MGen mgen(m,directory,modelname);
    mgen.generateClass();

    LGen load(m,modelname,directory,loadername);
    load.generateClass();

    SGen save(m,modelname,directory,savername);
    save.generateClass();



}



////QApplication main do not remove
int runSecondWorkFlow(int argc, char* argv[])
{
    using namespace std;

    QApplication a(argc, argv);

    MainWindow w;
    model m;
    w.setModel(m);
    w.show();

    return a.exec();
}

int main(int argc, char *argv[])
{
    //runFirstWorkFlow(argc,argv);

    return runSecondWorkFlow(argc,argv);

}


