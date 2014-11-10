QString tmpClassName;
QString tmpClassType;

void loadXML(parameters model)
{
	std::map<<QString, QString>, QString> xmlTokens;
	typedef std::map<std::pair<QString, QString>, QString> Dict;
	typedef Dict::const_iterator It;

	QFile* data = new QFile("C:\Users\galagali\Desktop\Navaneet's Folder\College stuff\Senior year\Software Engineering\Qt Projects\parsing\data.xml");
	if (!data->open(QIODevice::ReadOnly | QIODevice::Text)) 
	{
		qDebug() << "Not read only";
	}

	QXmlStreamReader readXML(data);
	while(!readXML.atEnd() && !readXML.hasError()) 
	{
		QXmlStreamReader::TokenType token = readXML.readNext();
		if(token == QXmlStreamReader::StartDocument) 
		{
			continue;
		}
		else if (readXML.isEndElement() != true) 
		{
			xmlTokens[std::make_pair(readXML.attributes()[0].value(), readXML.attributes()[1].value())] = readXML.attributes()[2].value();
		}
	}

	tmpClassType = QCheckBox;
	tmpClassName = checkBox;

	for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
	{
		if((it -> first.second).compare(tmpClassName) == 0) 
		{
			if((it -> first.first).compare("QString") == 0) 
			{
				model.setcheckBox((QString)(it -> second));
			}
			else if((it -> first.first).compare("QCheckBox") == 0) 
			{
				model.setcheckBox(static_cast<bool>(it -> second));
			}
		}
	}

	tmpClassType = QDoubleSpinBox;
	tmpClassName = doubleSpinBox;

	for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
	{
		if((it -> first.second).compare(tmpClassName) == 0) 
		{
			if((it -> first.first).compare("QString") == 0) 
			{
				model.setdoubleSpinBox((QString)(it -> second));
			}
			else if((it -> first.first).compare("QCheckBox") == 0) 
			{
				model.setdoubleSpinBox(static_cast<bool>(it -> second));
			}
		}
	}

	tmpClassType = QMainWindow;
	tmpClassName = MainWindow;

	for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
	{
		if((it -> first.second).compare(tmpClassName) == 0) 
		{
			if((it -> first.first).compare("QString") == 0) 
			{
				model.setMainWindow((QString)(it -> second));
			}
			else if((it -> first.first).compare("QCheckBox") == 0) 
			{
				model.setMainWindow(static_cast<bool>(it -> second));
			}
		}
	}

	tmpClassType = QMenu;
	tmpClassName = menuAMenu;

	for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
	{
		if((it -> first.second).compare(tmpClassName) == 0) 
		{
			if((it -> first.first).compare("QString") == 0) 
			{
				model.setmenuAMenu((QString)(it -> second));
			}
			else if((it -> first.first).compare("QCheckBox") == 0) 
			{
				model.setmenuAMenu(static_cast<bool>(it -> second));
			}
		}
	}

	tmpClassType = QMenuBar;
	tmpClassName = menuBar;

	for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
	{
		if((it -> first.second).compare(tmpClassName) == 0) 
		{
			if((it -> first.first).compare("QString") == 0) 
			{
				model.setmenuBar((QString)(it -> second));
			}
			else if((it -> first.first).compare("QCheckBox") == 0) 
			{
				model.setmenuBar(static_cast<bool>(it -> second));
			}
		}
	}

	tmpClassType = QPushButton;
	tmpClassName = pushButton;

	for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
	{
		if((it -> first.second).compare(tmpClassName) == 0) 
		{
			if((it -> first.first).compare("QString") == 0) 
			{
				model.setpushButton((QString)(it -> second));
			}
			else if((it -> first.first).compare("QCheckBox") == 0) 
			{
				model.setpushButton(static_cast<bool>(it -> second));
			}
		}
	}

	tmpClassType = QPushButton;
	tmpClassName = pushButton_2;

	for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
	{
		if((it -> first.second).compare(tmpClassName) == 0) 
		{
			if((it -> first.first).compare("QString") == 0) 
			{
				model.setpushButton_2((QString)(it -> second));
			}
			else if((it -> first.first).compare("QCheckBox") == 0) 
			{
				model.setpushButton_2(static_cast<bool>(it -> second));
			}
		}
	}

	tmpClassType = QRadioButton;
	tmpClassName = radioButton;

	for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
	{
		if((it -> first.second).compare(tmpClassName) == 0) 
		{
			if((it -> first.first).compare("QString") == 0) 
			{
				model.setradioButton((QString)(it -> second));
			}
			else if((it -> first.first).compare("QCheckBox") == 0) 
			{
				model.setradioButton(static_cast<bool>(it -> second));
			}
		}
	}

	tmpClassType = QStatusBar;
	tmpClassName = statusBar;

	for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
	{
		if((it -> first.second).compare(tmpClassName) == 0) 
		{
			if((it -> first.first).compare("QString") == 0) 
			{
				model.setstatusBar((QString)(it -> second));
			}
			else if((it -> first.first).compare("QCheckBox") == 0) 
			{
				model.setstatusBar(static_cast<bool>(it -> second));
			}
		}
	}

	tmpClassType = QTextEdit;
	tmpClassName = textEdit;

	for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
	{
		if((it -> first.second).compare(tmpClassName) == 0) 
		{
			if((it -> first.first).compare("QString") == 0) 
			{
				model.settextEdit((QString)(it -> second));
			}
			else if((it -> first.first).compare("QCheckBox") == 0) 
			{
				model.settextEdit(static_cast<bool>(it -> second));
			}
		}
	}

	tmpClassType = QToolBar;
	tmpClassName = mainToolBar;

	for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
	{
		if((it -> first.second).compare(tmpClassName) == 0) 
		{
			if((it -> first.first).compare("QString") == 0) 
			{
				model.setmainToolBar((QString)(it -> second));
			}
			else if((it -> first.first).compare("QCheckBox") == 0) 
			{
				model.setmainToolBar(static_cast<bool>(it -> second));
			}
		}
	}

	tmpClassType = QWidget;
	tmpClassName = centralWidget;

	for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
	{
		if((it -> first.second).compare(tmpClassName) == 0) 
		{
			if((it -> first.first).compare("QString") == 0) 
			{
				model.setcentralWidget((QString)(it -> second));
			}
			else if((it -> first.first).compare("QCheckBox") == 0) 
			{
				model.setcentralWidget(static_cast<bool>(it -> second));
			}
		}
	}

	tmpClassType = QWidget;
	tmpClassName = horizontalLayoutWidget;

	for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
	{
		if((it -> first.second).compare(tmpClassName) == 0) 
		{
			if((it -> first.first).compare("QString") == 0) 
			{
				model.sethorizontalLayoutWidget((QString)(it -> second));
			}
			else if((it -> first.first).compare("QCheckBox") == 0) 
			{
				model.sethorizontalLayoutWidget(static_cast<bool>(it -> second));
			}
		}
	}

	tmpClassType = QWidget;
	tmpClassName = horizontalLayoutWidget_2;

	for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
	{
		if((it -> first.second).compare(tmpClassName) == 0) 
		{
			if((it -> first.first).compare("QString") == 0) 
			{
				model.sethorizontalLayoutWidget_2((QString)(it -> second));
			}
			else if((it -> first.first).compare("QCheckBox") == 0) 
			{
				model.sethorizontalLayoutWidget_2(static_cast<bool>(it -> second));
			}
		}
	}


}