#ifndef LGEN_H
#define LGEN_H

#include <map>
#include <QFile>
#include <QDebug>

template<class K, class V>
class LGen{
    map<K,V> & m;


public:
    //constructor
    LGen(map<K,V> & hmap):m(hmap) {


    }

    void generateClass()
    {



        QFile loader("../COMP523ProjectQTParamCp/loader.h");
        if (loader.open(QFile::WriteOnly | QFile::Truncate)) {
            QDebug out(&loader);

            out.nospace() << "#include <QCoreApplication>\n#include <QString>\n";
            out.nospace() << "#include <QDebug>\n#include <map>\n#include <QFile>\n\n";

            out.nospace() << "class Loader\n{\n\n";
            out.nospace() << "public:\n\n";
            out.nospace() << "\tQString tmpClassName;\n";
            out.nospace() << "\tQString tmpClassType;\n";

            out.nospace() << "\n\tModel load(Model& model)\n\t{\n";

            out.nospace() << "\t\tstd::map<std::pair<QString, QString>, QString> xmlTokens;\n";
            out.nospace() << "\t\ttypedef std::map<std::pair<QString, QString>, QString> Dict;\n";
            out.nospace() << "\t\ttypedef Dict::const_iterator It;\n\n";



            out.nospace() << "\t\tQFile* data = new QFile(\"data.xml\");\n";
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

            for (map<K,V>::const_iterator it= m.begin(); it != m.end(); ++it)
            {


                out.nospace() << "\t\ttmpClassType = " << it -> second << ";\n";

                out.nospace() << "\t\ttmpClassName = " << it -> first.second << ";\n\n";

                out.nospace() << "\t\tfor (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) \n\t\t{\n";

                out.nospace() << "\t\t\tif((it -> first.second).compare(tmpClassName) == 0) \n\t\t\t{\n";

                if (((QString)(it -> second)).compare("QString") == 0)
                {
                    out.nospace() << "\t\t\t\t\tmodel.set" << (it -> first.second).toUtf8().constData();
                    out.nospace() << "((QString)(it -> second));\n";
                }

                else if (((QString)(it -> second)).compare("bool") == 0)
                {
                    out.nospace() << "\t\t\t\t\tint boolValue = ((QString)(it -> second)).toInt();\n";
                    out.nospace() << "\t\t\t\t\tmodel.set" << (it -> first.second).toUtf8().constData();
                    out.nospace() << "(static_cast<bool>(boolValue));\n";
                }

                out.nospace() << "\t\t\t}\n\t\t}";
                out.nospace() << "\n\n";
            }

            out.nospace() << "\t\treturn model;";
            out.nospace() << "\n\t}";
            out.nospace() << "\n};";
        }

        loader.close();

    }

};
#endif // LGEN_H
