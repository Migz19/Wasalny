#pragma once
#include "Mapper.h"
#include <vector>
#include <utility>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
class NodeMapper : public Mapper
{

public:
	NodeMapper();
	int getId(string name) override;
	string getName(int id) override;
	bool nameExists(string name) override;
	bool idExists(int id) override;
	void remove(int id) override;
	~NodeMapper();

};

