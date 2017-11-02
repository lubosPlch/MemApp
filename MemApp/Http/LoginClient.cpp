#include "LoginClient.h"
#include "../Model/Token.h"
#include "../Model/Data.h"
#include "../Model/Error.h"

#include <sstream>
#include <QtNetwork>

LoginClient::LoginClient() :HttpClient()
{

}
LoginClient::~LoginClient()
{
}
void LoginClient::performLogin(QString name, QString passwd)
{
	std::stringstream stream;
	stream << "https://cloud.memsource.com/web/api/v3/auth/login?userName=" << name.toStdString() << "&password=" << passwd.toStdString();
	request.sendRequest(QString::fromStdString(stream.str()));

}
void LoginClient::sucessResponse(QString response)
{
	Token t;
	if (!t.readString(response)) {
		emit ActionError("can not perform HTTP reqest");
		return;
	}
	Data::setToken(t);
	emit actionSuccessful();

}

