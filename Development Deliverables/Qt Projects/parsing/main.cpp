#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QFileDevice>
#include <QXmlStreamReader>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QLineEdit>
#include <iostream>
#include <QDebug>
#include <map>

void parseXML() {
    /* We'll parse the example.xml */
    QFile* file = new QFile("C:\\Users\\galagali\\Desktop\\Navaneet's Folder\\College stuff\\Senior year\\Software Engineering\\Qt Projects\\parsing\\mainwindow.ui");

    /* If we can't open it, let's show an error message. */
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "hi";
        QString errMsg = file->errorString();
        QFileDevice::FileError err = QFileDevice::NoError;
        err = file->error();
        qDebug() << err;
    }

    /* QXmlStreamReader takes any QIODevice. */
    QXmlStreamReader xml(file);
    QList< QMap<QString,QString> > persons;

    /* We'll parse the XML until we reach end of it.*/
    while(!xml.atEnd() && !xml.hasError()) {

        QXmlStreamReader::TokenType token = xml.readNext();     // Read next element

        std::map<std::pair<QStringRef, QStringRef>, QString> m;

        if(token == QXmlStreamReader::StartDocument) {      //If token is just StartDocument, we'll go to next
            continue;
        }

        else if (xml.qualifiedName() == "widget" && xml.isEndElement() != true)
        {
            // Store values into the dictionary
            m[std::make_pair(xml.attributes().at(0).value(), xml.attributes().at(1).value())] = "";

            // Print values to the console
            qDebug() << xml.attributes().at(0).value();     // Class type
           // qDebug() << xml.attributes().at(1).value();     // Class name
        }

    }
    /* Error handling. */
    if(xml.hasError()) {

    }
    /* Removes any device() or data from the reader
     * and resets its internal state to the initial state. */
    xml.clear();

    file->close();
}

int main(int argc, char *argv[])
{
    parseXML();
}
