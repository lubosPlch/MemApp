#include "Projects.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

Projects::Projects(QObject *parent) : QAbstractTableModel(parent),projects()
{

}

bool Projects::read(const QJsonObject & json)
{
	return false;
}

bool Projects::read(const QJsonDocument & json)
{
	if (!json.isArray())
	{
		return false;
	}
	for (const auto& member : json.array())
	{
		Project p;
		if (!member.isObject() || !p.read(member.toObject()))
		{
			projects.clear();
			return false;
		}
		projects.push_back(p);
	}
	return true;
}

int Projects::rowCount(const QModelIndex & parent) const
{
	return projects.size();
}

int Projects::columnCount(const QModelIndex & parent) const
{
	return 4;
}

QVariant Projects::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	int col = index.column();

	if (role == Qt::DisplayRole)
	{
		switch (col) {
		case 0:
		{
			return projects[row].getName();
			break;
		}
		case 1:
		{
			return projects[row].getSourceLang();
			break;
		}
		case 2:
		{
			QString langs;
			const auto &langsVec = projects[row].getTargetlangs();
			for (auto lang = langsVec.begin(); lang != langsVec.end() ;lang++)
			{
				langs += *lang;
				if (lang + 1 != langsVec.end())
				{
					langs += " || ";
				}
			}
			return langs;
			break;
		}
		case 3:
		{
			QDateTime local = projects[row].getCreated().toLocalTime();
			return local.toString();
			break;
		}
		}
	}
	return QVariant();
}

QVariant Projects::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal) {
			switch (section)
			{
			case 0:
				return QString("Name");
			case 1:
				return QString("Source lang");
			case 2:
				return QString("target langs");
			case 3: 
				return QString("Time created");
			}
		}
	}
	return QVariant();
}
