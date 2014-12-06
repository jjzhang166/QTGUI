#ifndef TestSaver_H
#define TestSaver_H
#include <QXmlStreamWriter>
#include <QFile>

#include <QString>

#include <string>

#include "TestModel.h"

#include <QDebug>

class TestSaver{ 

public: 

	void save(TestModel& m);
	void saveToXML(TestModel& m,QXmlStreamWriter& writer);
};
#endif
