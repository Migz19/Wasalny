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
protected:
	friend class File;
	int maxId;
	vector<int> freeIds;
	unordered_map<string, int> stringToId;
	unordered_map<int, string> idToString;

	/*vector<int> freeNodeMappingIds;
	int maxNodeMappingId;
	unordered_map<string, int> nodeToId;
	unordered_map<int, string> idToNode;

	vector<int> freeEdgeMappingIds;
	int maxEdgeMappingId;
	unordered_map<string, int> edgeToId;
	unordered_map<int, string> idtoEdge;
	unordered_map<int, int> idToDistance;  */

public:

	Mapper();
	virtual int getId(string name);
	virtual string getName(int id);
	virtual void remove(int id);
	virtual bool nameExists(string name);
	virtual bool idExists(int id);
	~Mapper();

};

