#ifndef PARSE_H
#define PARSE_H

#include <QXmlStreamReader>
#include <QString>
#include <QFile>
#include <QDebug>
#include <map>
#include <QIODevice>


class Parser{
public:

    map<std::pair<QString,QString>,QString> parseXML(map<std::pair<QString,QString>,QString>& m) {
        /* We'll parse the example.xml */
        QFile* file = new QFile("../COMP523ProjectQTParamCp/mainwindow.ui");

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
                if (xml.attributes().at(0).value().toString().compare("QTextEdit") == 0)
                {
                    m[std::make_pair(xml.attributes().at(0).value().toString(), xml.attributes().at(1).value().toString())] = "QString";
                    qDebug() << xml.attributes().at(0).value();     // Class type
                    qDebug() << xml.attributes().at(1).value();     // Class name
                }

                else if (xml.attributes().at(0).value().toString().compare("QCheckBox") == 0)
                {
                    m[std::make_pair(xml.attributes().at(0).value().toString(), xml.attributes().at(1).value().toString())] = "bool";
                    qDebug() << xml.attributes().at(0).value();     // Class type
                    qDebug() << xml.attributes().at(1).value();     // Class name
                }
                // Store values into the dictionary
    //            m[std::make_pair(xml.attributes().at(0).value().toString(), xml.attributes().at(1).value().toString())] = "";

                // Print values to the console

            }

        }
        /* Error handling. */
        if(xml.hasError()) {

        }
        /* Removes any device() or data from the reader
         * and resets its internal state to the initial state. */
        xml.clear();

        file->close();
        delete file;

        return m;
    }

};


#endif // PARSE_H
