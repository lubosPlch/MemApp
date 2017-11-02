#include "Error.h"
#include <QJsonObject>
#include <QJsonDocument>

bool Error::read(const QJsonObject & json)
{
	if (!json["errorCode"].isString())
	{
		return false;
	}
	errorCode = json["errorCode"].toString();
	return true;
}

bool Error::read(const QJsonDocument & json)
{
	return read(json.object());
}

