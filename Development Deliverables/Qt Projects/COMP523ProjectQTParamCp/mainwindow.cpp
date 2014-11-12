#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "model.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// set model
void MainWindow::setModel(Model m){
    model = m;
}

// get model
Model MainWindow::getModel(){
    return model;
}

// Save Listener
// - Updates the model with data from GUI
void MainWindow::on_pushButton_clicked()
{
    bool sb1 = ui->swagbox->isChecked();
    model.setswagbox(sb1);

    bool sb2 = ui->swagboxII->isChecked();
    model.setswagboxII(sb2);

    QString txt1 = ui->textEdit->toPlainText();
    model.settextEdit(txt1);

    QString txt2 = ui->textEdit_2->toPlainText();
    model.settextEdit_2();
}

// Load Listener
// - Updates the GUI with data from the model
void MainWindow::on_pushButton_2_clicked()
{
    bool sb1 = model.getswagbox();
    ui->swagbox->setChecked(sb1);

    bool sb2 = model.getswagboxII();
    ui->swagboxII->setChecked(sb2);

    QString txt1 = model.gettextEdit();
    ui->textEdit->setText(txt1);

    QString txt2 = model.gettextEdit_2();
    ui->textEdit_2->setText(txt2);
}
