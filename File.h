#pragma once
#include<iostream>
#include <fstream>
#include<string>
#include <utility>
#include"Graph.h"
#include"Mapper.h"
#include"NodeMapper.h"
#include"EdgeMapper.h"
using namespace std;

enum { nodeMapping, edgeMapping };

class File
{
private:
	void saveGraphSize();
	void saveGraphEdgeList();
	void saveGraphAdjList();
	void saveMapperSize(int Mappertype);
	void saveMapperfreeIds(int Mappertype);
	void saveMapperList(int Mappertype);
	void saveEdgeDistance();

	void loadGraphSize();
	void loadGraphEdgeList();
	void loadGraphAdjList();
	void loadMapperSize(int Mappertype);
	void loadMapperfreeIds(int Mappertype);
	void loadMapperList(int Mappertype);
	void loadEdgeDistance();


public:
	void load();
	void save();
};

