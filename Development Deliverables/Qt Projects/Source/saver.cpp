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
    writer.writeAttribute("name","swagbox");
    //Enagaging hacky void pointer method of saving
    if(sizeof(m.getswagbox())<=sizeof(long)) {

        //Don't care about the value, as long as it is less in memory size than an long, we can save it as a long
        writer.writeAttribute("value",QString::fromStdString(std::to_string(m.getswagbox())));
    } else {
        //Generate error if the value is too big to fit
        writer.writeAttribute("value","Error: Invalid attribute value");
    }
    writer.writeEmptyElement("m:Data");
    writer.writeAttribute("type","bool");
    writer.writeAttribute("name","swagboxII");
    if(sizeof(m.getswagboxII())<=sizeof(long)) {

        //Don't care about the value, as long as it is less in memory size than an long, we can save it as a long
        writer.writeAttribute("value",QString::fromStdString(std::to_string(m.getswagboxII())));
    } else {
        //Generate error if the value is too big to fit
        writer.writeAttribute("value","Error: Invalid attribute value");
    }
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
