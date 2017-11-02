#pragma once
#include "User.h"
#include "DataObject.h"

class QJsonObject;
class Token : public DataObject
{
public:
	Token();
private:
	User user;
	QString token;
	QString expires;
	bool valid;
public:
	bool read(const QJsonObject &json) override;
	bool read(const QJsonDocument &json) override;

	const User& getUser() inline const { return user; } 
	const QString& getToken() inline const { return token; }
	const QString& getExpiration() inline const { return expires; }
	const bool isValid() inline const {return valid; }


};