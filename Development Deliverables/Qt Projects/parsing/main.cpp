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
#include "parameters.h"
#include "loader.h"

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
    QFile data("C:\\Users\\galagali\\Desktop\\Navaneet's Folder\\College stuff\\Senior year\\Software Engineering\\Qt Projects\\parsing\\parameters.h");
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
         QDebug out(&data);

        // typedef std::map<std::pair<QString, QString>, QString> Dict;
        // typedef Dict::const_iterator It;

         out.nospace() << "#include <QCoreApplication>\n#include <QString>\n";

         out << "\n" << "class parameters\n{\n\n";
         out.nospace() << "public:\n\n";

         for (It it= m.begin(); it != m.end(); ++it)
         {
             if ((it -> first.first).compare("QTextEdit") == 0)
             {
                 out.nospace() << "\tQString " << (it-> first.second).toUtf8().constData() << ";\n";
             }

             else if ((it -> first.first).compare("QCheckBox") == 0)
             {
                 out.nospace() << "\tbool " << (it-> first.second).toUtf8().constData() << ";\n";
             }
         }

         for (It it= m.begin(); it != m.end(); ++it)
         {
            // QByteArray className = it -> first.first;
             if ((it -> first.first).compare("QTextEdit") == 0)
             {
                out.nospace() << "\n\tvoid set" << (it->first.second).toUtf8().constData() << "(QString toSet)";
                out.nospace() << "\n\t{\n" << "\t\t" << (it -> first.second).toUtf8().constData() << " = " << "toSet" << ";\n\t}\n";

                out.nospace() << "\n\t" << "QString get" << (it->first.second).toUtf8().constData() << "()";
                out.nospace() << "\n\t{\n" << "\t\treturn " << (it -> first.second).toUtf8().constData() << ";\n\t}\n";
             }

             else if ((it -> first.first).compare("QCheckBox") == 0)
             {
                 out.nospace() << "\n\tvoid set" << (it->first.second).toUtf8().constData() << "(bool toSet)";
                 out.nospace() << "\n\t{\n" << "\t\t" << (it -> first.second).toUtf8().constData() << " = " << "toSet" << ";\n\t}\n";

                 out.nospace() << "\n\t" << "bool get" << (it->first.second).toUtf8().constData() << "()";
                 out.nospace() << "\n\t{\n" << "\t\treturn " << (it -> first.second).toUtf8().constData() << ";\n\t}\n";
             }

             else
             {
                 continue;
             }

         }

         out << "\n};";
     }

    data.close();
}

void generateLoader()
{
    QFile loader("C:\\\\Users\\\\galagali\\\\Desktop\\\\Navaneet's Folder\\\\College stuff\\\\Senior year\\\\Software Engineering\\\\Qt Projects\\\\parsing\\\\loader.h");
    if (loader.open(QFile::WriteOnly | QFile::Truncate)) {
         QDebug out(&loader);

         out.nospace() << "#include <QCoreApplication>\n#include <QString>\n";
         out.nospace() << "#include <QDebug>\n#include <map>\n#include <QFile>\n\n";

         out.nospace() << "class loader\n{\n\n";
         out.nospace() << "public:\n\n";
         out.nospace() << "\tQString tmpClassName;\n";
         out.nospace() << "\tQString tmpClassType;\n";

         out.nospace() << "\n\tparameters loadXML(parameters model)\n\t{\n";

         out.nospace() << "\t\tstd::map<std::pair<QString, QString>, QString> xmlTokens;\n";
         out.nospace() << "\t\ttypedef std::map<std::pair<QString, QString>, QString> Dict;\n";
         out.nospace() << "\t\ttypedef Dict::const_iterator It;\n\n";



         out.nospace() << "\t\tQFile* data = new QFile(\"C:\\\\Users\\\\galagali\\\\Desktop\\\\Navaneet's Folder\\\\College stuff\\\\Senior year\\\\Software Engineering\\\\Qt Projects\\\\parsing\\\\data.xml\");\n";
         out.nospace() << "\t\tif (!data->open(QIODevice::ReadOnly | QIODevice::Text)) \n\t\t{\n";
         out.nospace() << "\t\t\tqDebug() << \"Not read only\";\n";
         out.nospace() << "\t\t}\n\n";
         out.nospace() << "\t\tQXmlStreamReader readXML(data);\n";
         out.nospace() << "\t\twhile(!readXML.atEnd() && !readXML.hasError()) \n\t\t{\n";
         out.nospace() << "\t\t\tQXmlStreamReader::TokenType token = readXML.readNext();\n";
         out.nospace() << "\t\t\tif(token == QXmlStreamReader::StartDocument) \n\t\t\t{\n";
         out.nospace() << "\t\t\t\tcontinue;\n";
         out.nospace() << "\t\t\t}\n";
         out.nospace() << "\t\t\telse if (readXML.isEndElement() != true) \n\t\t\t{\n";

         out.nospace() << "\t\t\t\txmlTokens[std::make_pair(readXML.attributes()[0].value().toString(), readXML.attributes()[1].value().toString())] = readXML.attributes()[2].value().toString();\n";
         out.nospace() << "\t\t\t}\n";
         out.nospace() << "\t\t}\n\n";

         for (It it= m.begin(); it != m.end(); ++it)
         {
            if ((it -> first.first).compare("QTextEdit") == 0)
            {
                out.nospace() << "\t\ttmpClassType = " << QString::fromStdString("QString") << ";\n";
            }

            else if ((it -> first.first).compare("QCheckBox") == 0)
            {
                out.nospace() << "\t\ttmpClassType = " << QString::fromStdString("bool") << ";\n";
            }

            else
            {
                continue;
            }

            out.nospace() << "\t\ttmpClassName = " << it -> first.second << ";\n\n";

            out.nospace() << "\t\tfor (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) \n\t\t{\n";

            out.nospace() << "\t\t\tif((it -> first.second).compare(tmpClassName) == 0) \n\t\t\t{\n";

            out.nospace() << "\t\t\t\tif(tmpClassType.compare(\"QString\") == 0) \n\t\t\t\t{\n";
            out.nospace() << "\t\t\t\t\tmodel.set" << (it -> first.second).toUtf8().constData();
            out.nospace() << "((QString)(it -> second));\n";
            out.nospace() << "\t\t\t\t}\n";

            out.nospace() << "\t\t\t\telse if(tmpClassType.compare(\"QCheckBox\") == 0) \n\t\t\t\t{\n";
            out.nospace() << "\t\t\t\t\tint boolValue = ((QString)(it -> second)).toInt();\n";
            out.nospace() << "\t\t\t\t\tmodel.set" << (it -> first.second).toUtf8().constData();
            out.nospace() << "(static_cast<bool>(boolValue));\n";
            out.nospace() << "\t\t\t\t}\n";
            out.nospace() << "\t\t\t}\n\t\t}";
            out.nospace() << "\n\n";
         }

         out.nospace() << "\t\treturn model;";
         out.nospace() << "\n\t}";
         out.nospace() << "\n};";
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
//   parseXML();
//   generateParameters();
//   generateLoader();

   parameters b;
   loader a;
   b = a.loadXML(b);
   qDebug() << b.gettextEdit() << "  " << b.getcheckBox();
}
