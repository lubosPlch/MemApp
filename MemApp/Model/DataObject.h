#pragma once
#include <QString>
class QJsonObject;
class QJsonDocument;
class DataObject {
public : 
	virtual bool read(const QJsonObject &json) = 0;
	virtual bool read(const QJsonDocument &json) = 0;
	bool readString(const QString& data);
};
