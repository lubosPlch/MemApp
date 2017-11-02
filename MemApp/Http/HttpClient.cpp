#include "HttpClient.h"
#include "Model/Data.h"

HttpClient::HttpClient():request() {
	connect(&request, SIGNAL(HttpOK(QString)), this, SLOT(sucessResponse(QString)));
	connect(&request, SIGNAL(HttpReadError(QString)), this, SLOT(errorResponse(QString)));
}
void HttpClient::errorResponse(QString response)
{
	Error e;
	if (!e.readString(response))
	{
		emit ActionError("can not perform HTTP reqest");
		return;
	}
	Error_API(e);
}
