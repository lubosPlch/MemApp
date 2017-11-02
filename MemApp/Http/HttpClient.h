#pragma once
#include "../Model/Token.h"
#include "../Model/Error.h"
#include "Request.h"
#include <QNetworkAccessManager>
#include <QUrl>
#include <QObject>

class HttpClient : public QObject
{
	Q_OBJECT

public:
	HttpClient();
public slots:
	virtual void sucessResponse(QString response) = 0;
	void errorResponse(QString response);
public:
	signals :
		void actionSuccessful();
		void ActionError(QString errorMessage);
		void Error_API(Error error);
protected:
	Request request;

};
