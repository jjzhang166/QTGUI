#include "loader.h"

	model loader::load(model& model)
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

		tmpClassType = "bool";
		tmpClassName = "checkBoxsdf";

		for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
		{
			if((it -> first.second).compare(tmpClassName) == 0) 
			{
					int boolValue = ((QString)(it -> second)).toInt();
					model.setcheckBoxsdf(static_cast<bool>(boolValue));
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
		tmpClassName = "comboBox";

		for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
		{
			if((it -> first.second).compare(tmpClassName) == 0) 
			{
					model.setcomboBox((QString)(it -> second));
			}
		}

		tmpClassType = "double";
		tmpClassName = "doubleSpinBox";

		for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
		{
			if((it -> first.second).compare(tmpClassName) == 0) 
			{
					double doubleValue = ((QString)(it -> second)).toDouble();
					model.setdoubleSpinBox(doubleValue);
			}
		}

		tmpClassType = "QString";
		tmpClassName = "lineEdit";

		for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
		{
			if((it -> first.second).compare(tmpClassName) == 0) 
			{
					model.setlineEdit((QString)(it -> second));
			}
		}

		tmpClassType = "bool";
		tmpClassName = "radioButton";

		for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
		{
			if((it -> first.second).compare(tmpClassName) == 0) 
			{
					int boolValue = ((QString)(it -> second)).toInt();
					model.setradioButton(static_cast<bool>(boolValue));
			}
		}

		tmpClassType = "bool";
		tmpClassName = "radioButton_2";

		for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
		{
			if((it -> first.second).compare(tmpClassName) == 0) 
			{
					int boolValue = ((QString)(it -> second)).toInt();
					model.setradioButton_2(static_cast<bool>(boolValue));
			}
		}

		tmpClassType = "bool";
		tmpClassName = "radioButton_3";

		for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
		{
			if((it -> first.second).compare(tmpClassName) == 0) 
			{
					int boolValue = ((QString)(it -> second)).toInt();
					model.setradioButton_3(static_cast<bool>(boolValue));
			}
		}

		tmpClassType = "int";
		tmpClassName = "horizontalScrollBar";

		for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
		{
			if((it -> first.second).compare(tmpClassName) == 0) 
			{
					int intValue = ((QString)(it -> second)).toInt();
					model.sethorizontalScrollBar(intValue);
			}
		}

		tmpClassType = "int";
		tmpClassName = "verticalScrollBar";

		for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
		{
			if((it -> first.second).compare(tmpClassName) == 0) 
			{
					int intValue = ((QString)(it -> second)).toInt();
					model.setverticalScrollBar(intValue);
			}
		}

		tmpClassType = "int";
		tmpClassName = "spinBox";

		for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
		{
			if((it -> first.second).compare(tmpClassName) == 0) 
			{
					int intValue = ((QString)(it -> second)).toInt();
					model.setspinBox(intValue);
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