#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QObject>
#include <map>
#include "mgen.h"

using namespace std;

//easier to type by defining pair
typedef std::pair<QString,QString> datapair;


int main(int argc, char *argv[])
{
    using namespace std;

    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    map<datapair,QString> m;

    //Test data in the
    m.insert(std::pair<datapair,QString>(datapair("QTextBox","textBoxString1"),"QString"));
    m.insert(std::pair<datapair,QString>(datapair("QTextBox","textBoxString2"),"QString"));
    m.insert(std::pair<datapair,QString>(datapair("QTextBox","textBoxString3"),"QString"));
    m.insert(std::pair<datapair,QString>(datapair("QTextBox","textBoxString4"),"QString"));
    //m.insert(std::pair<datapair,QString>(datapair("QCheckBox","checkBox"),"bool"));

    MGen<datapair,QString> ab(m);
    ab.generateClass();

    //Model m;

    return a.exec();
}
