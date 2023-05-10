#pragma once
#include <exception>
#include <string>

using namespace std;
class GraphException : public exception
{
private:
	string message;

public:
	GraphException(const string& msg = "");
	const char* what();
};

