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
#include <QTextStream>

std::map<std::pair<QStringRef, QStringRef>, QString> m;

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

    /* We'll parse the XML until we reach end of it.*/
    while(!xml.atEnd() && !xml.hasError()) {

        QXmlStreamReader::TokenType token = xml.readNext();     // Read next element

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

void generateParameters()
{
    QFile data("C:\\Users\\galagali\\Desktop\\Navaneet's Folder\\College stuff\\Senior year\\Software Engineering\\Qt Projects\\parsing\\parameters.cpp");
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
         QDebug out(&data);
         out << "#include <QString>\n"

         typedef std::map<std::pair<QStringRef, QStringRef>, QString> Dict;
         typedef Dict::const_iterator It;

         for (It it= m.begin(); it != m.end(); ++it)
         {
             out << "\nvoid set" << it->first.first << it->first.second << "(QString toSet)";
             out << "\n{\n\n}";
             out << "\nvoid get" << it->first.first << it->first.second << "()";
             out << "\n{\n" << "\treturn m[std::make_pair(" << it->first.first << ", " << it->first.second << ")];\n}";
             //std::cout <<it->second <<' '
             //            <<d[std::make_pair(j, i)] <<'\n';
         }
     }

    data.close();
}

int main(int argc, char *argv[])
{
    parseXML();
    generateParameters();
}
