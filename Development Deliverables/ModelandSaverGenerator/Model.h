#include <QString>

class Model {
	QString checkBoxBool;
	string textBoxString1;
	QString textBoxString2;
	bool textBoxString4;

public: 

	QString getcheckBoxBool(){
		return checkBoxBool;
	}
	void setcheckBoxBool(QString a){
		checkBoxBool=a;
	}
	string gettextBoxString1(){
		return textBoxString1;
	}
	void settextBoxString1(string a){
		textBoxString1=a;
	}
	QString gettextBoxString2(){
		return textBoxString2;
	}
	void settextBoxString2(QString a){
		textBoxString2=a;
	}
	bool gettextBoxString4(){
		return textBoxString4;
	}
	void settextBoxString4(bool a){
		textBoxString4=a;
	}
};
