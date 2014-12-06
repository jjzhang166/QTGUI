#ifndef SAVER_H
#define SAVER_H
#include <QXmlStreamWriter>
#include <QFile>

#include <QString>

#include <string>

#include "model.h"

#include <QDebug>

class saver{ 

public: 

	void save(model& m);
	void saveToXML(model& m,QXmlStreamWriter& writer);
};
#endif
