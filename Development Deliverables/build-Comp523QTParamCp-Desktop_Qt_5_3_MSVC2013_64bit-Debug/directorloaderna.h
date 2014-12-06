#ifndef LOADER_H
#define LOADER_H

#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <map>
#include <QFile>
#include "model.h"
#include <QXmlStreamReader>


class loaderna{

	QString tmpClassName;
	QString tmpClassType;
public:

	modelfil load(modelfil& model);

};
#endif