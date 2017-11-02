#include "MemApp.h"
#include "../Http/LoginClient.h"
#include "Model/Data.h"
#include <QMessageBox>

MemApp::MemApp(QWidget *parent)
	: QMainWindow(parent), loginClient(), mainWindow(nullptr)
{
	ui.setupUi(this);
	ui.passwordLine->setEchoMode(QLineEdit::Password);
	ui.passwordLine->setInputMethodHints(Qt::ImhHiddenText | Qt::ImhNoPredictiveText | Qt::ImhNoAutoUppercase);
	connect(&loginClient, SIGNAL(actionSuccessful()), this, SLOT(on_logginSuccesfull()));
	connect(&loginClient, SIGNAL(ActionError(QString)), this, SLOT(on_logginError(QString)));
	connect(&loginClient, SIGNAL(Error_API(Error)), this, SLOT(on_logginError_API(Error)));
}

void MemApp::on_loginButton_released(){
	QString name = ui.loginLine->text();
	QString psswd = ui.passwordLine->text();
	if (psswd.isEmpty() || name.isEmpty())
	{
		QMessageBox::information(this, tr("Empty login or password"),
			"The login or password field is empty. Please enter login and password and click Login.");
		return;
	}
	loginClient.performLogin(name, psswd);
}

void MemApp::on_logginSuccesfull()
{
	if (!Data::getToken().isValid())
	{
		QMessageBox::information(this, tr("can not loggin "),tr("unknown error"));
		return;
	}
	mainWindow = std::make_unique<MainWindow>(this);
	mainWindow->show();
	this->hide();
	ui.passwordLine->clear();

}

void MemApp::on_logginError(QString ErrorMessage)
{
	QMessageBox::information(this, tr("can not loggin "),
		ErrorMessage);
}

void MemApp::on_logginError_API(Error error)
{
	QMessageBox::information(this,tr("can not login") ,
		error.getErrorCode());
}
