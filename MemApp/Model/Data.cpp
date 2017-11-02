#include "Data.h"

Token Data::m_token = Token();
std::unique_ptr<Projects>Data::m_projects = std::make_unique<Projects>();

const Token& Data::getToken()
{
	return m_token;
}

void Data::setToken(Token t)
{
	m_token = t;
}

Projects *Data::getProjects()
{
	return m_projects.get();
}

void Data::setProjects(std::unique_ptr<Projects>&& p)
{
	m_projects = std::move(p);
}
