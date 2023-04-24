#pragma once
#include "Mapper.h"
#include <vector>
#include <utility>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class EdgeMapper : public Mapper
{
private:
	unordered_map<int, int> idToDistance;
public:
	EdgeMapper();
	int getDistance(int id);
	int getId(string name, int distance);
	void remove(int id) override;
	string getName(int id) override;
	bool nameExists(string name) override;
	bool idExists(int id) override;
	~EdgeMapper();
	
};

