#include "User.h"

#include <cmath>

#include <QJsonObject>
#include <QJsonDocument>


bool User::read(const QJsonObject & json)
{
	if (!json["id"].isDouble()||!json["firstName"].isString() || !json["lastName"].isString() || !json["userName"].isString() || !json["role"].isString())
	{
		return false;
	}
	double tmp = json["id"].toDouble();
	if (tmp <= std::numeric_limits<int>::min() || tmp >= std::numeric_limits<int>::max() || std::floor(tmp) != tmp)
	{
		return false;
	}
	id = std::floor(tmp);
	firstName = json["firstName"].toString();
	lastName = json["lastName"].toString();
	userName = json["userName"].toString();
	role = json["role"].toString();
	return true;
}

bool User::read(const QJsonDocument & json)
{
	return read(json.object());
}
