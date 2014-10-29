#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "masterstring.h"

using namespace std;

#include "QDebug"
#include "iostream"
#include <QString>
#include <string>
#include <map>
//#include <masterstring>

// Prepare dictionary functionality
typedef std::map<int, QString> Dict;
typedef std::map<int, MasterString> TestDict;

//typedef std::map<std::pair<QStringRef, QStringRef>, QString> Dict;
typedef Dict::const_iterator It;
// NOTE: For example, look at the following: http://stackoverflow.com/questions/1842941/translating-python-dictionary-to-c

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // TestDict
//    TestDict t1;
//    // CREATE CONSTRUCTOR FOR MasterString
//    // ---------------------
//    string str = "hello";
//    QString qstr = QString("bye");
//    // ---------------------
//    t1[1] = str;
//    t1[2] = qstr;



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

//    qDebug() << "hi";
//    std::cout << "hello" << std::endl;

    // Create new dictionary every time "Print" is clicked (ideal?)
    Dict d;

    // Text Edit
    //-----------------
    QString qtxt = ui->textEdit->toPlainText();
    d[1] = qtxt;
//    qDebug() << qtxt;


    // Radio Buttons
    //-----------------
    // Must identify radio names (or classes?)
    if(ui->radioButton->isChecked()){
        QString qRad1Sel = ui->radioButton->text();
//        qDebug() << qRad1Sel;
        d[2] = qRad1Sel;
    }
    if(ui->radioButton_2->isChecked()){
        QString qRad2Sel = ui->radioButton_2->text();
//        qDebug() << qRad2Sel;
        d[2] = qRad2Sel;
    }
    if(ui->radioButton_3->isChecked()){
        QString qRad3Sel = ui->radioButton_3->text();
//        qDebug() << qRad3Sel;
        d[2] = qRad3Sel;
    }

    qDebug() << d[1];

    // Check Boxes
    //-----------------
    // - Must identify radio names (or classes?)
    // - Find simpler way to extract data
    if(ui->checkBox->isChecked()){
        QString check1 = ui->checkBox->text();
        qDebug() << check1;
    }
    if(ui->checkBox_2->isChecked()){
        QString check2 = ui->checkBox_2->text();
        qDebug() << check2;
    }
    if(ui->checkBox_3->isChecked()){
        QString check3 = ui->checkBox_3->text();
        qDebug() << check3;
    }



    // SRC: STACKOVERFLOW
    // UTILITY: Converts QString to string
    //----------------------
    // Either this if you use UTF-8 anywhere
    //std::string utf8_text = qtxt.toUtf8().constData();

    // or this if you on Windows :-)
    //std::string current_locale_text = qs.toLocal8Bit().constData();
    //----------------------

    //std::cout << utf8_text << std::endl;
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug() << QString("Hi!");
}
