#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "saver.h"
#include "model.h"
#include <QDebug>

#include "loader.h"

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
void MainWindow::setModel(model m){
    this->m = m;
}

// get model
model MainWindow::getModel(){
    return m;
}

// Save Listener
// - Updates the model with data from GUI
void MainWindow::on_pushButton_clicked()
{

    bool sb1 = ui->swagbox->isChecked();
    m.setswagbox(sb1);

    bool sb2 = ui->swagboxII->isChecked();
    m.setswagboxII(sb2);

    QString txt1 = ui->textEdit->toPlainText();
    m.settextEdit(txt1);

    QString txt2 = ui->textEdit_2->toPlainText();
    m.settextEdit_2(txt2);

    m.setcheckBoxsdf(ui->checkBoxsdf->isChecked());

    m.setcomboBox(ui->comboBox->currentText());

    m.setdoubleSpinBox(ui->doubleSpinBox->value());

    m.sethorizontalScrollBar(ui->horizontalScrollBar->value());

    m.setverticalScrollBar(ui->verticalScrollBar->value());

    m.setlineEdit(ui->lineEdit->text());

    m.setradioButton(ui->radioButton->isChecked());

    m.setradioButton_2(ui->radioButton_2->isChecked());

    m.setradioButton_3(ui->radioButton_3->isChecked());

    m.setspinBox(ui->spinBox->value());

    saver save;
    save.save(m);

}

// Load Listener
// - Updates the GUI with data from the model
void MainWindow::on_pushButton_2_clicked()
{
    loader loader;
    loader.load(m);


    ui->checkBoxsdf->setChecked(m.getcheckBoxsdf());

    ui->comboBox->setCurrentText(m.getcomboBox());

    ui->doubleSpinBox->setValue(m.getdoubleSpinBox());

    ui->horizontalScrollBar->setValue(m.gethorizontalScrollBar());

    ui->verticalScrollBar->setValue(m.getverticalScrollBar());

    ui->lineEdit->setText(m.getlineEdit());

    ui->radioButton->setChecked( m.getradioButton());

    ui->radioButton_2->setChecked(m.getradioButton_2());

    ui->radioButton_3->setChecked( m.getradioButton_3());

    ui->spinBox->setValue(m.getspinBox());



    bool sb1 = m.getswagbox();
    ui->swagbox->setChecked(sb1);

    bool sb2 = m.getswagboxII();
    ui->swagboxII->setChecked(sb2);

    QString txt1 = m.gettextEdit();
    ui->textEdit->setText(txt1);

    QString txt2 = m.gettextEdit_2();
    ui->textEdit_2->setText(txt2);
}
