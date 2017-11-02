#include "Token.h"
#include <QJsonObject>
#include <QJsonDocument>

Token::Token() : user(),token(),expires(),valid(false)
{
}

bool Token::read(const QJsonObject & json)
{
	if (!json["user"].isObject()||!json["token"].isString() || !json["expires"].isString())
	{
		return false;
	}
	
	token = json["token"].toString();
	expires = json["expires"].toString();
	valid = user.read(json["user"].toObject());
	return valid;


}

bool Token::read(const QJsonDocument & json)
{
	return read(json.object());
}


