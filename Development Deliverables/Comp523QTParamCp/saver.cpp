#include "saver.h"
	void saver::save(model& m){
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


	void saver::saveToXML(model& m,QXmlStreamWriter& writer){

		writer.setAutoFormatting(true);

		writer.writeStartDocument();


		writer.writeStartElement("m:ModelData");
		writer.writeNamespace("https://github.com/QTGUIFolks/QTGUI","m");
		writer.writeEmptyElement("m:Data");
		writer.writeAttribute("type","bool");
		writer.writeAttribute("name","checkBoxsdf");
		writer.writeAttribute("value",QString::number(m.getcheckBoxsdf()));
		writer.writeEmptyElement("m:Data");
		writer.writeAttribute("type","bool");
		writer.writeAttribute("name","swagbox");
		writer.writeAttribute("value",QString::number(m.getswagbox()));
		writer.writeEmptyElement("m:Data");
		writer.writeAttribute("type","bool");
		writer.writeAttribute("name","swagboxII");
		writer.writeAttribute("value",QString::number(m.getswagboxII()));
		writer.writeEmptyElement("m:Data");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","comboBox");
		writer.writeAttribute("value",m.getcomboBox());
		writer.writeEmptyElement("m:Data");
		writer.writeAttribute("type","double");
		writer.writeAttribute("name","doubleSpinBox");
		writer.writeAttribute("value",QString::number(m.getdoubleSpinBox()));
		writer.writeEmptyElement("m:Data");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","lineEdit");
		writer.writeAttribute("value",m.getlineEdit());
		writer.writeEmptyElement("m:Data");
		writer.writeAttribute("type","bool");
		writer.writeAttribute("name","radioButton");
		writer.writeAttribute("value",QString::number(m.getradioButton()));
		writer.writeEmptyElement("m:Data");
		writer.writeAttribute("type","bool");
		writer.writeAttribute("name","radioButton_2");
		writer.writeAttribute("value",QString::number(m.getradioButton_2()));
		writer.writeEmptyElement("m:Data");
		writer.writeAttribute("type","bool");
		writer.writeAttribute("name","radioButton_3");
		writer.writeAttribute("value",QString::number(m.getradioButton_3()));
		writer.writeEmptyElement("m:Data");
		writer.writeAttribute("type","int");
		writer.writeAttribute("name","horizontalScrollBar");
		writer.writeAttribute("value",QString::number(m.gethorizontalScrollBar()));
		writer.writeEmptyElement("m:Data");
		writer.writeAttribute("type","int");
		writer.writeAttribute("name","verticalScrollBar");
		writer.writeAttribute("value",QString::number(m.getverticalScrollBar()));
		writer.writeEmptyElement("m:Data");
		writer.writeAttribute("type","int");
		writer.writeAttribute("name","spinBox");
		writer.writeAttribute("value",QString::number(m.getspinBox()));
		writer.writeEmptyElement("m:Data");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","textEdit");
		writer.writeAttribute("value",m.gettextEdit());
		writer.writeEmptyElement("m:Data");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","textEdit_2");
		writer.writeAttribute("value",m.gettextEdit_2());
		writer.writeEndElement();

		writer.writeEndDocument();

	}
