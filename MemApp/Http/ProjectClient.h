#pragma once

#include "Request.h"
#include "../Model/Token.h"
#include "../Model/Error.h"
#include "HttpClient.h"
#include <QNetworkAccessManager>
#include <QUrl>
#include <QObject>

class ProjectClient : public HttpClient
{
	Q_OBJECT
public:
	ProjectClient();
	~ProjectClient();
public:
	void performGET(QString token);

	public slots:
	void sucessResponse(QString response) override;



};