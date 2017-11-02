#pragma once
#include "DataObject.h"
#include <QAbstractTableModel>
#include "Project.h"
class Projects : public QAbstractTableModel, public DataObject
{
	Q_OBJECT
	public:
		Projects(QObject *parent = nullptr);
		Projects(Projects&&) = default;
		bool read(const QJsonObject &json) override;
		bool read(const QJsonDocument &json) override;

		int rowCount(const QModelIndex &parent = QModelIndex()) const override;
		int columnCount(const QModelIndex &parent = QModelIndex()) const override;
		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
		QVariant headerData(int section, Qt::Orientation orientation, int role) const;

	private:
		std::vector<Project> projects;
};