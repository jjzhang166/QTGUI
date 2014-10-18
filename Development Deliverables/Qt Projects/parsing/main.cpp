#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QFileDevice>
#include <QXmlStreamReader>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QLineEdit>
#include <iostream>
#include <QDebug>

/*void addPersonsToUI(QList< QMap<QString,QString> >& persons) {
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
}
*/
void addElementDataToMap(QXmlStreamReader& xml,
                                      QMap<QString, QString>& map) {
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

QMap<QString, QString> parsePerson(QXmlStreamReader& xml) {
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
     //           this->addElementDataToMap(xml, person);
            }
            /* We've found surname. */
            if(xml.name() == "surname") {
      //          this->addElementDataToMap(xml, person);
            }
            /* We've found email. */
            if(xml.name() == "email") {
       //         this->addElementDataToMap(xml, person);
            }
            /* We've found website. */
            if(xml.name() == "website") {
       //         this->addElementDataToMap(xml, person);
            }
        }
        /* ...and next... */
        xml.readNext();
    }
    return person;
}

void parseXML() {
    /* We'll parse the example.xml */
    QFile* file = new QFile("C:\\Users\\galagali\\Desktop\\Navaneet's Folder\\College stuff\\Senior year\\Software Engineering\\Qt Projects\\parsing\\mainwindow.ui");

    /* If we can't open it, let's show an error message. */
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "hi";
        QString errMsg = file->errorString();
        QFileDevice::FileError err = QFileDevice::NoError;
        err = file->error();
        qDebug() << err;
    }

    /* QXmlStreamReader takes any QIODevice. */
    QXmlStreamReader xml(file);
    QList< QMap<QString,QString> > persons;

    /* We'll parse the XML until we reach end of it.*/
    while(!xml.atEnd() && !xml.hasError()) {

        QXmlStreamReader::TokenType token = xml.readNext();     // Read next element
        //qDebug() << "   " << xml.qualifiedName() << "    " << xml.tokenString();

        if (xml.qualifiedName() == "widget" && xml.isEndElement() != true)
        {
            qDebug() << xml.attributes().at(0).value();
        }

        if(token == QXmlStreamReader::StartDocument) {      //If token is just StartDocument, we'll go to next
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
                persons.append(parsePerson(xml));
            }
        }
    }
    /* Error handling. */
    if(xml.hasError()) {

    }
    /* Removes any device() or data from the reader
     * and resets its internal state to the initial state. */
    xml.clear();
   // addPersonsToUI(persons);
    file->close();
    qDebug() << persons;
}

int main(int argc, char *argv[])
{
    parseXML();
}
