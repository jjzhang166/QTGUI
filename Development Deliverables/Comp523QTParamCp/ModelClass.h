#ifndef ModelClass_H
#define ModelClass_H

#include <QString>

class ModelClass {
	bool checkBoxsdf;
	bool swagbox;
	bool swagboxII;
	QString comboBox;
	double doubleSpinBox;
	QString lineEdit;
	bool radioButton;
	bool radioButton_2;
	bool radioButton_3;
	int horizontalScrollBar;
	int verticalScrollBar;
	int spinBox;
	QString textEdit;
	QString textEdit_2;

public: 

	bool getcheckBoxsdf();
	void setcheckBoxsdf(bool a);

	bool getswagbox();
	void setswagbox(bool a);

	bool getswagboxII();
	void setswagboxII(bool a);

	QString getcomboBox();
	void setcomboBox(QString a);

	double getdoubleSpinBox();
	void setdoubleSpinBox(double a);

	QString getlineEdit();
	void setlineEdit(QString a);

	bool getradioButton();
	void setradioButton(bool a);

	bool getradioButton_2();
	void setradioButton_2(bool a);

	bool getradioButton_3();
	void setradioButton_3(bool a);

	int gethorizontalScrollBar();
	void sethorizontalScrollBar(int a);

	int getverticalScrollBar();
	void setverticalScrollBar(int a);

	int getspinBox();
	void setspinBox(int a);

	QString gettextEdit();
	void settextEdit(QString a);

	QString gettextEdit_2();
	void settextEdit_2(QString a);

};

#endif
