#include "savename.h"
	void savename::save(modelfil& m){
		//First, address the appropriate instantiate
		QFile file("data.xml");
		if(!file.open(QIODevice::WriteOnly)){
			//handle file open errors here 
			 qDebug()<<file.exists();
		}

		QXmlStreamWriter writer(&file);

		//write each field stored in model into xml
		saveToXML(m,writer);

	}


	void savename::saveToXML(modelfil& m,QXmlStreamWriter& writer){

		writer.setAutoFormatting(true);

		writer.writeStartDocument();


		writer.writeStartElement("m:ModelData");
		writer.writeNamespace("https://github.com/QTGUIFolks/QTGUI","m");
		writer.writeEndElement();

		writer.writeEndDocument();

	}
