#include "GraphException.h"

GraphException::GraphException(const string& msg)
{
	this->message = msg;
}

const char* GraphException::what()
{
	return (this->message).c_str();
}