#include "MainWindow.h"
#include "Model/Data.h"
#include "MemApp.h"
#include <QMessageBox>

MainWindow::MainWindow(MemApp *login, QWidget *parent) : QMainWindow(parent), logginWindow(*login), projectClient()
{
	ui.setupUi(this);
	connect(&projectClient, SIGNAL(actionSuccessful()), this, SLOT(on_GETSuccesfull()));
	connect(&projectClient, SIGNAL(ActionError(QString)), this, SLOT(on_GETError(QString)));
	connect(&projectClient, SIGNAL(Error_API(Error)), this, SLOT(on_GETError_API(Error)));
	projectClient.performGET(Data::getToken().getToken());
}

void MainWindow::on_logOutButton_released()
{
	Data::setToken(Token());
	Data::setProjects(std::make_unique<Projects>());
	logginWindow.show();
	this->hide();
}

void MainWindow::on_GETSuccesfull()
{
	ui.ProjectView->setModel(Data::getProjects());
	ui.ProjectView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

}

void MainWindow::on_GETError(QString ErrorMessage)
{
	QMessageBox::information(this, tr("can not GET data "),
		ErrorMessage);
}

void MainWindow::on_GETError_API(Error error)
{
	QMessageBox::information(this, tr("can not GET data"),
		error.getErrorCode());
}
