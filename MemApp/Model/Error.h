#pragma once
#include <QString>
#include "DataObject.h"

class QJsonObject;
class Error : public DataObject {
public: 
	bool read(const QJsonObject &json) override;
	const QString& getErrorCode() inline const { return errorCode; }
	bool read(const QJsonDocument &json) override;
private:
	QString errorCode;
};
