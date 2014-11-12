#ifndef SAVER_H
#define SAVER_H
#include <QXmlStreamWriter>
#include <QFile>

class Saver {

public: 

	void save(Model& model) {
		//First, address the appropriate instantiate
		QFile file("data.xml");
		if(!file.open(QIODevice::WriteOnly)){
			//handle file open errors here 
			 qDebug()<<file.exists();
		}

		QXmlStreamWriter writer(&file);

		//write each field stored in model into xml
		saveToXML(model,writer);

	}


	void saveToXML(Model& model,QXmlStreamWriter& writer){

		writer.setAutoFormatting(true);

		writer.writeStartDocument();

		writer.writeEmptyElement("Data");
		writer.writeAttribute("type","bool");
		writer.writeAttribute("name","swagbox");
		//Enagaging hacky void pointer method of saving
		if(sizeof(model.getswagbox())<=sizeof(long)) {

			//Don't care about the value, as long as it is less in memory size than an long, we can save it as a long
			writer.writeAttribute("value",QString::fromStdString(to_string(model.getswagbox())));
		} else {
			//Generate error if the value is too big to fit
			writer.writeAttribute("value","Error: Invalid attribute value");
		}
		writer.writeEndElement();

		writer.writeEmptyElement("Data");
		writer.writeAttribute("type","bool");
		writer.writeAttribute("name","swagboxII");
		if(sizeof(model.getswagboxII())<=sizeof(long)) {

			//Don't care about the value, as long as it is less in memory size than an long, we can save it as a long
			writer.writeAttribute("value",QString::fromStdString(to_string(model.getswagboxII())));
		} else {
			//Generate error if the value is too big to fit
			writer.writeAttribute("value","Error: Invalid attribute value");
		}
		writer.writeEndElement();

		writer.writeEmptyElement("Data");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","textEdit");
		writer.writeAttribute("value",model.gettextEdit());
		writer.writeEndElement();

		writer.writeEmptyElement("Data");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","textEdit_2");
		writer.writeAttribute("value",model.gettextEdit_2());
		writer.writeEndElement();

		writer.writeEndDocument();

	}
};
#endif
