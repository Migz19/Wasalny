#pragma once
#include <vector>
#include <utility>
#include <iostream>
#include <unordered_map>
#include <string>
#include "GraphException.h"

using namespace std;

class Mapper
{
	friend class File;

protected:

	int maxId;
	vector<int> freeIds; //id of removed nodes or edges 
	unordered_map<string, int> stringToId;
	unordered_map<int, string> idToString;

public:

	Mapper();
	virtual int getId(string name);
	virtual string getName(int id);
	virtual void remove(int id);
	virtual bool nameExists(string name);
	virtual bool idExists(int id);
	~Mapper();

};

