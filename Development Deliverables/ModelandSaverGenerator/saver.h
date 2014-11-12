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
		writer.writeAttribute("value",model.getcheckBoxBool());
		writer.writeAttribute("Name","checkBoxBool");
		writer.writeAttribute("Type","QString");
		writer.writeEndElement();

		writer.writeEmptyElement("Data");
		writer.writeAttribute("value",QString::fromStdString(model.gettextBoxString1()));
		writer.writeAttribute("Name","textBoxString1");
		writer.writeAttribute("Type","string");
		writer.writeEndElement();

		writer.writeEmptyElement("Data");
		writer.writeAttribute("value",model.gettextBoxString2());
		writer.writeAttribute("Name","textBoxString2");
		writer.writeAttribute("Type","QString");
		writer.writeEndElement();

		writer.writeEmptyElement("Data");
		//Enagaging hacky void pointer method of saving
		if(sizeof(model.gettextBoxString4())<=sizeof(long)) {

			//Don't care about the value, as long as it is less in memory size than an long, we can save it as a long
			writer.writeAttribute("value",QString::fromStdString(to_string(model.gettextBoxString4())));
		} else {
			//Generate error if the value is too big to fit
			writer.writeAttribute("value","Error: Invalid attribute value");
		}
		writer.writeAttribute("Name","textBoxString4");
		writer.writeAttribute("Type","bool");
		writer.writeEndElement();

		writer.writeEndDocument();

	}
};
#endif
