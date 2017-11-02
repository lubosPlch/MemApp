#pragma once
#include "DataObject.h"
#include <QString>

class QJsonObject;
class User : public DataObject
{
private:
	int id;
	QString firstName;
	QString lastName;
	QString userName;
	QString role;
public :
	bool read(const QJsonObject &json) override;
	bool read(const QJsonDocument &json) override;

	const int& getId() inline const { return id; }
	const QString& getFirstName() inline const { return firstName; }
	const QString& getLastName() inline const { return userName; }
	const QString& getUserName() inline const { return lastName; }
	const QString& getRole() inline const { return role; }

};