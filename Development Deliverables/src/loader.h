#ifndef loader_H
#define loader_H

#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <map>
#include <QFile>
#include "model.h"
#include <QXmlStreamReader>


class loader{

	QString tmpClassName;
	QString tmpClassType;
public:

	model load(model& model);

};
#endif