#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <map>
#include <QFile>

class loader{

public:
	QString tmpClassName;
	QString tmpClassType;

	model load(model& model)
	{
		std::map<std::pair<QString, QString>, QString> xmlTokens;
		typedef std::map<std::pair<QString, QString>, QString> Dict;
		typedef Dict::const_iterator It;

		QFile* data = new QFile("data.xml");
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
				if(readXML.attributes().length()>2)					xmlTokens[std::make_pair(readXML.attributes()[0].value().toString(), readXML.attributes()[1].value().toString())] = readXML.attributes()[2].value().toString();
			}
		}

		tmpClassType = "bool";
		tmpClassName = "swagbox";

		for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
		{
			if((it -> first.second).compare(tmpClassName) == 0) 
			{
					int boolValue = ((QString)(it -> second)).toInt();
					model.setswagbox(static_cast<bool>(boolValue));
			}
		}

		tmpClassType = "bool";
		tmpClassName = "swagboxII";

		for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
		{
			if((it -> first.second).compare(tmpClassName) == 0) 
			{
					int boolValue = ((QString)(it -> second)).toInt();
					model.setswagboxII(static_cast<bool>(boolValue));
			}
		}

		tmpClassType = "QString";
		tmpClassName = "textEdit";

		for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
		{
			if((it -> first.second).compare(tmpClassName) == 0) 
			{
					model.settextEdit((QString)(it -> second));
			}
		}

		tmpClassType = "QString";
		tmpClassName = "textEdit_2";

		for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
		{
			if((it -> first.second).compare(tmpClassName) == 0) 
			{
					model.settextEdit_2((QString)(it -> second));
			}
		}

		return model;
	}
};