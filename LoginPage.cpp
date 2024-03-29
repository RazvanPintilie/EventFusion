﻿#include "LoginPage.h"
#include <QMessageBox>
#include "WorkPage.h"
#include "User.h"

LoginPage::LoginPage(QWidget* parent) : QWidget(parent)
{
	setWindowTitle("Login Page");

	QVBoxLayout* layout = new QVBoxLayout(this);
	database.Connection();
	usernameEdit = new QLineEdit(this);
	layout->addWidget(usernameEdit);

	passwordEdit = new QLineEdit(this);
	passwordEdit->setEchoMode(QLineEdit::Password);
	layout->addWidget(passwordEdit);

	QPushButton* loginButton = new QPushButton("Login", this);
	layout->addWidget(loginButton);

	connect(loginButton, &QPushButton::clicked, this, &LoginPage::onLoginClicked);
}

void LoginPage::onLoginClicked()
{
	QString username = usernameEdit->text();
	QString password = passwordEdit->text();
	bool ok = database.searchUser(username.toStdString());
	if (ok)
	{
		User::getInstance().setUsername(username);
		QMessageBox::information(this, "Login", "Logare reușită");

		createUserDirectories(username);
		
		// Show a dialog to choose between opening an existing project or creating a new one
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, "Choose an Option", "Do you want to open an existing project?",
			QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

		// Emit the loginSuccessWithOption signal based on the user's choice
		if (reply == QMessageBox::Yes)
			emit loginSuccessWithOption(false); // Open existing project
		else if (reply == QMessageBox::No)
			emit loginSuccessWithOption(true); // Create a new project

	}
	else
	{
		QMessageBox::warning(this, "Login", "Logare eșuată");
	}
}

void LoginPage::createUserDirectories(const QString& username)
{
	QString projectFolderPath = QDir::currentPath() + "/project";
	QString userFolderPath = projectFolderPath + "/" + username;

	QDir projectDir(projectFolderPath);
	QDir userDir(userFolderPath);

	if (!projectDir.exists()) {
		if (projectDir.mkdir(projectFolderPath))
		{
			QMessageBox::information(this, "Folder", "Folderul 'project' a fost creat.");
		}
		else
		{
			QMessageBox::warning(this, "Folder", "Nu s-a putut crea folderul 'project'.");
		}
	}

	if (!userDir.exists()) {
		if (userDir.mkpath(userFolderPath))
		{
			QMessageBox::information(this, "Folder", QString("Folderul utilizatorului '%1' a fost creat.").arg(username));
		}
		else
		{
			QMessageBox::warning(this, "Folder", QString("Nu s-a putut crea folderul pentru utilizatorul '%1'.").arg(username));
		}
	}
}