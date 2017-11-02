#include "Request.h"
#include <Qnetworkreply>
#include <Qerrormessage>

Request::~Request()
{
}

Request::Request():oNetworkAccessManager(this)
{
	QObject::connect(&oNetworkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*)));
	oNetworkAccessManager.setNetworkAccessible(QNetworkAccessManager::Accessible);
}

/*
* Sends a request
*/
QNetworkReply* Request::sendRequest(QString url)
{
	QNetworkRequest request;
	request.setUrl(QUrl(url));
	request.setSslConfiguration(QSslConfiguration::defaultConfiguration()); // Set default ssl config
	QNetworkReply *reply = oNetworkAccessManager.get(request);
	connect(reply, SIGNAL(readyRead()), this, SLOT(readyRead()));


	return reply;
}



void Request::readyRead()
{
	qDebug() << "readyRead()";
	QErrorMessage msg;
	msg.showMessage("too much!");
}

/*
* Runs when the request is finished and has received a response
*/
void Request::finishedSlot(QNetworkReply *reply)
{

	// Reading attributes of the reply
	// e.g. the HTTP status code
	QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	// Or the target URL if it was a redirect:
	QVariant redirectionTargetUrl =	reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
	// see CS001432 on how to handle this
	// no error received?
	if (reply->error() == QNetworkReply::NoError)
	{
		// Reading the data from the response
		QByteArray bytes = reply->readAll();
		 response = QString(bytes); 
		 qDebug() <<"response recieved \n" << response;
		 emit HttpOK(response);
	}
	// Some http error received
	else
	{
		auto error = reply->error();
		QByteArray bytes = reply->readAll();
		response = QString(bytes);
		emit HttpReadError(response);
	}

	// We receive ownership of the reply object
	// and therefore need to handle deletion.
	delete reply;
}



