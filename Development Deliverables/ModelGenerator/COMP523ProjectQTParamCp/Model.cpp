#include <QString>

class Model {
	QString textBoxString1;
	QString textBoxString2;
	QString textBoxString3;
	QString textBoxString4;

public: 

	QString gettextBoxString1(){
		return textBoxString1;
	}
	void settextBoxString1(QString a){
		textBoxString1=a;
	}
	QString gettextBoxString2(){
		return textBoxString2;
	}
	void settextBoxString2(QString a){
		textBoxString2=a;
	}
	QString gettextBoxString3(){
		return textBoxString3;
	}
	void settextBoxString3(QString a){
		textBoxString3=a;
	}
	QString gettextBoxString4(){
		return textBoxString4;
	}
	void settextBoxString4(QString a){
		textBoxString4=a;
	}
}
