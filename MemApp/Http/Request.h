#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>
class Request :public QObject
{
	Q_OBJECT
public:
	Request();
	~Request();
	QNetworkReply* sendRequest(QString url);
signals:
	void HttpReadError(QString reponse);
	void HttpOK(QString reponse);
public slots: 
	void finishedSlot(QNetworkReply *reply);
	void readyRead();
private: 
	QNetworkAccessManager oNetworkAccessManager;
	QString response;
};

