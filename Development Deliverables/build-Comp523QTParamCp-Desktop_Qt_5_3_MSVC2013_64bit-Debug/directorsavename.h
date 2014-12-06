#ifndef SAVER_H
#define SAVER_H
#include <QXmlStreamWriter>
#include <QFile>

#include <QString>

#include <string>

#include "modelfil.h"

#include <QDebug>

class savename{ 

public: 

	void save(modelfil& m);
	void saveToXML(modelfil& m,QXmlStreamWriter& writer);
};
#endif
