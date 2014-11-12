#include <QCoreApplication>
#include <QString>

class parameters
{

public:

	bool checkBox;
	QString textEdit;

	void setcheckBox(bool toSet)
	{
		checkBox = toSet;
	}

	bool getcheckBox()
	{
		return checkBox;
	}

	void settextEdit(QString toSet)
	{
		textEdit = toSet;
	}

	QString gettextEdit()
	{
		return textEdit;
	}

};