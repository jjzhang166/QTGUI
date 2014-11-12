#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <map>
#include <QFile>

class loader
{

public:

	QString tmpClassName;
	QString tmpClassType;

	parameters loadXML(parameters model)
	{
		std::map<std::pair<QString, QString>, QString> xmlTokens;
		typedef std::map<std::pair<QString, QString>, QString> Dict;
		typedef Dict::const_iterator It;

		QFile* data = new QFile("C:\\Users\\galagali\\Desktop\\Navaneet's Folder\\College stuff\\Senior year\\Software Engineering\\Qt Projects\\parsing\\data.xml");
		if (!data->open(QIODevice::ReadOnly | QIODevice::Text)) 
		{
			qDebug() << "Not read only";
		}

		QXmlStreamReader readXML(data);
		while(!readXML.atEnd() && !readXML.hasError()) 
		{
			QXmlStreamReader::TokenType token = readXML.readNext();
			if(token == QXmlStreamReader::StartDocument) 
			{
				continue;
			}
			else if (readXML.isEndElement() != true) 
			{
				xmlTokens[std::make_pair(readXML.attributes()[0].value().toString(), readXML.attributes()[1].value().toString())] = readXML.attributes()[2].value().toString();
			}
		}

		tmpClassType = "bool";
		tmpClassName = "checkBox";

		for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
		{
			if((it -> first.second).compare(tmpClassName) == 0) 
			{
				if(tmpClassType.compare("QString") == 0) 
				{
    //				model.setcheckBox((QString)(it -> second));
				}
				else if(tmpClassType.compare("QCheckBox") == 0) 
				{
					int boolValue = ((QString)(it -> second)).toInt();
					model.setcheckBox(static_cast<bool>(boolValue));
				}
			}
		}

		tmpClassType = "QString";
		tmpClassName = "textEdit";

		for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
		{
			if((it -> first.second).compare(tmpClassName) == 0) 
			{
				if(tmpClassType.compare("QString") == 0) 
				{
					model.settextEdit((QString)(it -> second));
				}
				else if(tmpClassType.compare("QCheckBox") == 0) 
				{
					int boolValue = ((QString)(it -> second)).toInt();
    //				model.settextEdit(static_cast<bool>(boolValue));
				}
			}
		}

		return model;
	}
};
