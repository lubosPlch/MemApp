#pragma once

#include <QtWidgets/QMainWindow>
#include <QPushbutton>
#include <QLineEdit>
#include <memory>
#include "ui_MemApp.h"
#include "../Http/LoginClient.h"
#include "MainWindow.h"

class MemApp : public QMainWindow
{
	Q_OBJECT

public:
	MemApp(QWidget *parent = Q_NULLPTR);

private:
	Ui::MemAppClass ui;
	LoginClient loginClient;
private slots:
	void on_loginButton_released();
	void on_logginSuccesfull();
	void on_logginError(QString ErrorMessage);
	void on_logginError_API(Error error);
private: 
	std::unique_ptr<MainWindow> mainWindow;

};
