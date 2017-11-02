#include "ProjectClient.h"
#include "../Model/Token.h"
#include "../Model/Data.h"
#include "../Model/Error.h"

#include <sstream>
#include <QtNetwork>

ProjectClient::ProjectClient():HttpClient()
{
}
ProjectClient::~ProjectClient()
{
}

void ProjectClient::performGET(QString token)
{
	std::stringstream stream;
	stream << "https://cloud.memsource.com/web/api/v3/project/list?token=" << token.toStdString();
	request.sendRequest(QString::fromStdString(stream.str()));
}
void ProjectClient::sucessResponse(QString response)
{
	if (!Data::getProjects()->readString(response)) {
		emit ActionError("can not perform HTTP reqest");
		return;
	}
	emit actionSuccessful();

}
