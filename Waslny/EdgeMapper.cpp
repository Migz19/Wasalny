#include "EdgeMapper.h"

EdgeMapper::EdgeMapper() {}

int EdgeMapper::getDistance(int id)
{
	return idToDistance[id];
}

int EdgeMapper::getId(string name, int distance)
{
	if (nameExists(name))
		return stringToId[name];

	int id = Mapper::getId(name);
	idToDistance[id] = distance;
	return id;
}

string EdgeMapper::getName(int id)
{
	return Mapper::getName(id);
}

bool EdgeMapper::nameExists(string name)
{
	return Mapper::nameExists(name);
}

bool EdgeMapper::idExists(int id)
{
	return Mapper::idExists(id);
}

EdgeMapper::~EdgeMapper()
{
	Mapper::~Mapper();
	idToDistance.clear();
}

void EdgeMapper::remove(int id)
{
	Mapper::remove(id);
	idToDistance.erase(id);
}
