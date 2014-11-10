#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QFileDevice>
#include <QXmlStreamReader>
//#include <QtWidgets/QMessageBox>
//#include <QtWidgets/QLineEdit>
#include <iostream>
#include <ostream>
#include <fstream>
#include <QDebug>
#include <map>
#include <QTextStream>

std::map<std::pair<QString, QString>, QString> m;
typedef std::map<std::pair<QString, QString>, QString> Dict;
typedef Dict::const_iterator It;

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
            m[std::make_pair(xml.attributes().at(0).value().toString(), xml.attributes().at(1).value().toString())] = "";

            // Print values to the console
            qDebug() << xml.attributes().at(0).value();     // Class type
            qDebug() << xml.attributes().at(1).value();     // Class name
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
  //  filebuf fb;
 //   fb.open ("C:\\Users\\galagali\\Desktop\\Navaneet's Folder\\College stuff\\Senior year\\Software Engineering\\Qt Projects\\parsing\\parameters.cpp",ios::out);
    QFile data("C:\\Users\\galagali\\Desktop\\Navaneet's Folder\\College stuff\\Senior year\\Software Engineering\\Qt Projects\\parsing\\parameters.cpp");
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
         QDebug out(&data);

        // typedef std::map<std::pair<QString, QString>, QString> Dict;
        // typedef Dict::const_iterator It;

         out.nospace() << "#include <QCoreApplication>\n#include <QString>\n";

        /* for (It it= m.begin(); it != m.end(); ++it)
         {
            out.nospace() << "#include <" << (it -> first.first).toUtf8().constData() << ">\n";
         }*/

         out << "\n";

         for (It it= m.begin(); it != m.end(); ++it)
         {
             if ((it -> first.first).compare("QTextEdit") == 0)
             {
                 out.nospace() << "QString " << (it-> first.second).toUtf8().constData() << ";\n";
             }

             else if ((it -> first.first).compare("QCheckBox") == 0)
             {
                 out.nospace() << "bool " << (it-> first.second).toUtf8().constData() << ";\n";
             }
         }

         for (It it= m.begin(); it != m.end(); ++it)
         {
            // QByteArray className = it -> first.first;
             if ((it -> first.first).compare("QTextEdit") == 0)
             {
                out.nospace() << "\nvoid set" << (it->first.second).toUtf8().constData() << "(QString toSet)";
                out.nospace() << "\n{\n" << "\t" << (it -> first.second).toUtf8().constData() << " = " << "toSet" << ";\n}";
             }

             else if ((it -> first.first).compare("QCheckBox") == 0)
             {
                 out.nospace() << "\nvoid set" << (it->first.second).toUtf8().constData() << "(bool toSet)";
                 out.nospace() << "\n{\n" << "\t" << (it -> first.second).toUtf8().constData() << " = " << "toSet" << ";\n}";
             }

             else
             {
                 continue;
             }

             out.nospace() << "\nvoid get" << (it->first.second).toUtf8().constData() << "()";
             out.nospace() << "\n{\n" << "\treturn " << (it -> first.second).toUtf8().constData() << ";\n}";
         }
     }

    data.close();
}

void generateLoader()
{
    QFile loader("C:\\Users\\galagali\\Desktop\\Navaneet's Folder\\College stuff\\Senior year\\Software Engineering\\Qt Projects\\parsing\\loader.cpp");
    if (loader.open(QFile::WriteOnly | QFile::Truncate)) {
         QDebug out(&loader);

         out.nospace() << "QString tmpClassName;\n";
         out.nospace() << "QString tmpClassType;\n";

         out.nospace() << "\nvoid loadXML(parameters model)\n{\n";

         out.nospace() << "\tstd::map<<QString, QString>, QString> xmlTokens;\n";
         out.nospace() << "\ttypedef std::map<std::pair<QString, QString>, QString> Dict;\n";
         out.nospace() << "\ttypedef Dict::const_iterator It;\n\n";



         out.nospace() << "\tQFile* data = new QFile(\"C:\\Users\\galagali\\Desktop\\Navaneet's Folder\\College stuff\\Senior year\\Software Engineering\\Qt Projects\\parsing\\data.xml\");\n";
         out.nospace() << "\tif (!data->open(QIODevice::ReadOnly | QIODevice::Text)) \n\t{\n";
         out.nospace() << "\t\tqDebug() << \"Not read only\";\n";
         out.nospace() << "\t}\n\n";
         out.nospace() << "\tQXmlStreamReader readXML(data);\n";
         out.nospace() << "\twhile(!readXML.atEnd() && !readXML.hasError()) \n\t{\n";
         out.nospace() << "\t\tQXmlStreamReader::TokenType token = readXML.readNext();\n";
         out.nospace() << "\t\tif(token == QXmlStreamReader::StartDocument) \n\t\t{\n";
         out.nospace() << "\t\t\tcontinue;\n";
         out.nospace() << "\t\t}\n";
         out.nospace() << "\t\telse if (readXML.isEndElement() != true) \n\t\t{\n";

         out.nospace() << "\t\t\txmlTokens[std::make_pair(readXML.attributes()[0].value(), readXML.attributes()[1].value())] = readXML.attributes()[2].value();\n";
         out.nospace() << "\t\t}\n";
         out.nospace() << "\t}\n\n";

         for (It it= m.begin(); it != m.end(); ++it)
         {

            out.nospace() << "\ttmpClassType = " << (it -> first.first).toUtf8().constData() << ";\n";
            out.nospace() << "\ttmpClassName = " << (it -> first.second).toUtf8().constData() << ";\n\n";

            out.nospace() << "\tfor (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) \n\t{\n";

            out.nospace() << "\t\tif((it -> first.second).compare(tmpClassName) == 0) \n\t\t{\n";

            out.nospace() << "\t\t\tif((it -> first.first).compare(\"QString\") == 0) \n\t\t\t{\n";
            out.nospace() << "\t\t\t\tmodel.set" << (it -> first.second).toUtf8().constData();
            out.nospace() << "((QString)(it -> second));\n";
            out.nospace() << "\t\t\t}\n";

            out.nospace() << "\t\t\telse if((it -> first.first).compare(\"QCheckBox\") == 0) \n\t\t\t{\n";
            out.nospace() << "\t\t\t\tmodel.set" << (it -> first.second).toUtf8().constData();
            out.nospace() << "(static_cast<bool>(it -> second));\n";
            out.nospace() << "\t\t\t}\n";
            out.nospace() << "\t\t}\n\t}";
            out.nospace() << "\n\n";
         }

         out.nospace() << "\n}";
    }

    loader.close();
    /*QFile* data = new QFile("C:\\Users\\galagali\\Desktop\\Navaneet's Folder\\College stuff\\Senior year\\Software Engineering\\Qt Projects\\parsing\\data.xml");


    if (!data->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Not read only";
    }

    QXmlStreamReader readXML(data);

    while(!readXML.atEnd() && !readXML.hasError()) {

        QXmlStreamReader::TokenType token = readXML.readNext();

        if(token == QXmlStreamReader::StartDocument) {      //If token is just StartDocument, we'll go to next
            continue;
        }

        else if (readXML.isEndElement() != true)
        {

            for (It it= m.begin(); it != m.end(); ++it)
            {
                if (readXML.attributes()[1].value().compare(it -> first.second) == 0)
                {

                }
                qDebug() << readXML.attributes()[2].value();
            }
        }
    }*/
    /*if (data.open(QFile::WriteOnly | QFile::Truncate)) {
         QDebug out(&data);

         out.nospace() << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
                       <<  "<Data type = \"QTextEdit\" name = \"textedit\" value = \"hi\" />";
    }*/
}

int main()
{
    parseXML();
    generateParameters();
    generateLoader();
}
