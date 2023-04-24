#include "NodeMapper.h"

NodeMapper::NodeMapper() {}

int NodeMapper::getId(string name)
{
	return Mapper::getId(name);
}

string NodeMapper::getName(int id)
{
	return Mapper::getName(id);
}

bool NodeMapper::nameExists(string name)
{
	return Mapper::nameExists(name);
}

bool NodeMapper::idExists(int id)
{
	return Mapper::idExists(id);
}

void NodeMapper::remove(int id)
{
	Mapper::remove(id);
}

NodeMapper::~NodeMapper()
{
	Mapper::~Mapper();
}
