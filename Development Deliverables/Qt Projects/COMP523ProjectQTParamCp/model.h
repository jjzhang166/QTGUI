#ifndef MODEL_H
#define MODEL_H

#include <QString>

class Model {
	bool swagbox;
	bool swagboxII;
	QString textEdit;
	QString textEdit_2;

public: 

	bool getswagbox(){
		return swagbox;
	}
	void setswagbox(bool a){
		swagbox=a;
	}
	bool getswagboxII(){
		return swagboxII;
	}
	void setswagboxII(bool a){
		swagboxII=a;
	}
	QString gettextEdit(){
		return textEdit;
	}
	void settextEdit(QString a){
		textEdit=a;
	}
	QString gettextEdit_2(){
		return textEdit_2;
	}
	void settextEdit_2(QString a){
		textEdit_2=a;
	}
};

#endif
