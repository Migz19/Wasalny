#include "Mapper.h"

Mapper::Mapper()
{
	maxId = 1;
}

int Mapper::getId(string name)
{
	if (nameExists(name))
		return stringToId[name];

	if (!freeIds.empty())  // when a name is removed its Id can be reused so the all the ids of deleted names are stored in freeIds
	{
		int lastAvailable = freeIds.size() - 1;
		stringToId[name] = freeIds[lastAvailable];
		idToString[stringToId[name]] = name;
		freeIds.pop_back();
	}
	else
	{
		stringToId[name] = maxId;
		idToString[stringToId[name]] = name;
		maxId++;
	}

	return stringToId[name];
}

string Mapper::getName(int id)
{
	if (!idExists(id))
		throw GraphException("node doesn't exist");

	return idToString[id];
}

void Mapper::remove(int id)
{
	if (!idExists(id))
		throw GraphException("node doesn't exist");

    freeIds.push_back(id);
	string name = idToString[id];

	idToString.erase(id);
	stringToId.erase(name);

}

bool Mapper::nameExists(string name)
{
	return stringToId.find(name) != stringToId.end();
}

bool Mapper::idExists(int id)
{
	return idToString.find(id) != idToString.end();
}

Mapper::~Mapper()
{
    maxId = 0;
	freeIds.clear();
	stringToId.clear();
	idToString.clear();
}
