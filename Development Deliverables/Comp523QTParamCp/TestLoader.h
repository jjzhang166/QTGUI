#ifndef TestLoader_H
#define TestLoader_H

#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <map>
#include <QFile>
#include "TestModel.h"
#include <QXmlStreamReader>


class TestLoader{

	QString tmpClassName;
	QString tmpClassType;
public:

	TestModel load(TestModel& model);

};
#endif