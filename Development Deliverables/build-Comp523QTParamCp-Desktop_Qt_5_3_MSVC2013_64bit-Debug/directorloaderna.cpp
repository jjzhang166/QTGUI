#include "loaderna.h"

	modelfil loaderna::load(modelfil& model)
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
				if(readXML.attributes().length()>2)
					xmlTokens[std::make_pair(readXML.attributes()[0].value().toString(), readXML.attributes()[1].value().toString())] = readXML.attributes()[2].value().toString();
			}
		}

		return model;
	}