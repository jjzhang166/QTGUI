#ifndef MODEL_H
#define MODEL_H

#include <QString>

class model {
	bool checkBoxsdf;
	bool swagbox;
	bool swagboxII;
	QString textEdit;
	QString textEdit_2;

public: 

	bool getcheckBoxsdf();
	void setcheckBoxsdf(bool a);

	bool getswagbox();
	void setswagbox(bool a);

	bool getswagboxII();
	void setswagboxII(bool a);

	QString gettextEdit();
	void settextEdit(QString a);

	QString gettextEdit_2();
	void settextEdit_2(QString a);

};

#endif
