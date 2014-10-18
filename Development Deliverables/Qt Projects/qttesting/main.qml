import QtQuick 2.2
import QtQuick.Controls 1.1
#include <QFile>

//void parseXML() {
    /* We'll parse the example.xml */
    QFile* file = new QFile(":/example.xml");
    /* If we can't open it, let's show an error message. */
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this,
                              "QXSRExample::parseXML",
                              "Couldn't open example.xml",
                              QMessageBox::Ok);
        return;
    }
    /* QXmlStreamReader takes any QIODevice. */
    QXmlStreamReader xml(file);
    QList< QMap<QString,QString> > persons;
    /* We'll parse the XML until we reach end of it.*/
    while(!xml.atEnd() &&
            !xml.hasError()) {
        /* Read next element.*/
        QXmlStreamReader::TokenType token = xml.readNext();
        /* If token is just StartDocument, we'll go to next.*/
        if(token == QXmlStreamReader::StartDocument) {
            continue;
        }
        /* If token is StartElement, we'll see if we can read it.*/
        if(token == QXmlStreamReader::StartElement) {
            /* If it's named persons, we'll go to the next.*/
            if(xml.name() == "persons") {
                continue;
            }
            /* If it's named person, we'll dig the information from there.*/
            if(xml.name() == "person") {
                persons.append(this->parsePerson(xml));
            }
        }
    }
    /* Error handling. */
    if(xml.hasError()) {
        QMessageBox::critical(this,
                              "QXSRExample::parseXML",
                              xml.errorString(),
                              QMessageBox::Ok);
    }
    /* Removes any device() or data from the reader
     * and resets its internal state to the initial state. */
    xml.clear();
    this->addPersonsToUI(persons);
}

QMap<QString, QString> QXSRExample::parsePerson(QXmlStreamReader& xml) {
    QMap<QString, QString> person;
    /* Let's check that we're really getting a person. */
    if(xml.tokenType() != QXmlStreamReader::StartElement &&
            xml.name() == "person") {
        return person;
    }
    /* Let's get the attributes for person */
    QXmlStreamAttributes attributes = xml.attributes();
    /* Let's check that person has id attribute. */
    if(attributes.hasAttribute("id")) {
        /* We'll add it to the map. */
        person["id"] = attributes.value("id").toString();
    }
    /* Next element... */
    xml.readNext();
    /*
     * We're going to loop over the things because the order might change.
     * We'll continue the loop until we hit an EndElement named person.
     */
    while(!(xml.tokenType() == QXmlStreamReader::EndElement &&
            xml.name() == "person")) {
        if(xml.tokenType() == QXmlStreamReader::StartElement) {
            /* We've found first name. */
            if(xml.name() == "firstname") {
                this->addElementDataToMap(xml, person);
            }
            /* We've found surname. */
            if(xml.name() == "surname") {
                this->addElementDataToMap(xml, person);
            }
            /* We've found email. */
            if(xml.name() == "email") {
                this->addElementDataToMap(xml, person);
            }
            /* We've found website. */
            if(xml.name() == "website") {
                this->addElementDataToMap(xml, person);
            }
        }
        /* ...and next... */
        xml.readNext();
    }
    return person;
}

void QXSRExample::addElementDataToMap(QXmlStreamReader& xml,
                                      QMap<QString, QString>& map) const {
    /* We need a start element, like <foo> */
    if(xml.tokenType() != QXmlStreamReader::StartElement) {
        return;
    }
    /* Let's read the name... */
    QString elementName = xml.name().toString();
    /* ...go to the next. */
    xml.readNext();
    /*
     * This elements needs to contain Characters so we know it's
     * actually data, if it's not we'll leave.
     */
    if(xml.tokenType() != QXmlStreamReader::Characters) {
        return;
    }
    /* Now we can add it to the map.*/
    map.insert(elementName, xml.text().toString());
}

void QXSRExample::addPersonsToUI(QList< QMap<QString,QString> >& persons) {
    while(!persons.isEmpty()) {
        QGroupBox* personGB = new QGroupBox("Person");
        QFormLayout* layout = new QFormLayout;
        QMap<QString,QString> person = persons.takeFirst();
        layout->addRow("ID", new QLineEdit(person["id"]));
        layout->addRow("First name", new QLineEdit(person["firstname"]));
        layout->addRow("Surname", new QLineEdit(person["surname"]));
        layout->addRow("E-mail", new QLineEdit(person["email"]));
        layout->addRow("Website", new QLineEdit(person["website"]));
        personGB->setLayout(layout);
        this->_layout->addWidget(personGB);
    }
//}
