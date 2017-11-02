#include "DataObject.h"
#include <memory>
#include <QJsonObject>
#include <QJsonDocument>


bool DataObject::readString(const QString & data)
{
	std::unique_ptr<QJsonParseError> error = nullptr;
	QJsonDocument loadedData(QJsonDocument::fromJson(QByteArray(data.toUtf8()), error.get()));
	if (loadedData.isNull() || error)
	{
		return false;
	}
	if (loadedData.isObject())
		return read(loadedData.object());
	else
		return read(loadedData);
}