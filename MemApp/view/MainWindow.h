#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_ProjectsWindow.h"
#include "../Http/ProjectClient.h"

class MemApp;

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(MemApp *login,QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWindow ui;
	MemApp &logginWindow;
	ProjectClient projectClient;

private slots:
	void on_logOutButton_released();
	void on_GETSuccesfull();
	void on_GETError(QString ErrorMessage);
	void on_GETError_API(Error error);


};