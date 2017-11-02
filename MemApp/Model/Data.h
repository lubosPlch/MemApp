#pragma once
#include "Token.h"
#include "Projects.h"
#include <memory>

class Data {
public:
	Data() = delete;
	Data(Data&) = delete;
	Data(Data&&) = delete;

	static const Token& getToken();
	static void setToken(Token t);

	static Projects* getProjects();
	static void setProjects(std::unique_ptr<Projects>&& p);
private:
	static Token m_token;
	static std::unique_ptr<Projects> m_projects;
};