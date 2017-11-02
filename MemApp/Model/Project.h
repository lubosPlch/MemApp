#pragma once
#include "DataObject.h"
#include <vector>
#include <QDateTime>

class Project : public DataObject
{
	public: 
		Project() = default;

		bool read(const QJsonObject &json) override;
		bool read(const QJsonDocument &json) override;
		const QString& getName() inline const { return name; }
		const QString& getSourceLang() inline const { return sourceLang; }
		const std::vector<QString>& getTargetlangs() inline const { return targetlangs; }
		const QDateTime& getCreated() inline const { return created; }
	private:
		QString name;
		QString sourceLang;
		std::vector<QString> targetlangs;
		QDateTime created;

};