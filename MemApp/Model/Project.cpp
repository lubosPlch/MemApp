#include "Project.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>
#include <QJsonDocument>

bool Project::read(const QJsonObject & json)
{
	if (!json["name"].isString() || !json["sourceLang"].isString() || !json["targetLangs"].isArray() || !json["dateCreated"].isString())
	{
		return false;
	}
	name = json["name"].toString();
	sourceLang = json["sourceLang"].toString();
	created = QDateTime::fromString(json["dateCreated"].toString(), "yyyy-MM-ddTHH:mm:ss+zzzz");
	created.setTimeSpec(Qt::UTC);
	if (!created.isValid())
	{
		return false;
	}
	QJsonArray targets = json["targetLangs"].toArray();
	for (const auto& target : targets)
	{
		if (!target.isString())
		{
			return false;
		}
		targetlangs.push_back(target.toString());
	}
	return true;

}

bool Project::read(const QJsonDocument & json)
{
	return read(json.object());
}
