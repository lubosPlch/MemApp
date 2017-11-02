#pragma once

#include "Request.h"
#include "../Model/Token.h"
#include "../Model/Error.h"
#include "HttpClient.h"
#include <QNetworkAccessManager>
#include <QUrl>
#include <QObject>

class LoginClient : public HttpClient
{
	Q_OBJECT
public:
	LoginClient();
	~LoginClient();
public:
	void performLogin(QString name,QString passwd);

	public slots: 
	void sucessResponse(QString response) override;



};
