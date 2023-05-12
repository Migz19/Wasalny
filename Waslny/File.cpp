#include "File.h"

void File::saveGraphSize()
{
	Graph* graph = Graph::getInstance();

	fstream graphSizeFile;
	graphSizeFile.open("graphsize.txt", std::ofstream::out | std::ofstream::trunc);
	graphSizeFile.close();

	graphSizeFile.open("graphsize.txt", ios::out);
	if (graphSizeFile.is_open())
	{
		graphSizeFile << to_string(graph->adjList.size());
		graphSizeFile << "\n";
		graphSizeFile << to_string(graph->edgeDirections.size());
	}

	graphSizeFile.close();

}

void File::saveGraphEdgeList()
{
	Graph* graph = Graph::getInstance();

	fstream listFile;
	listFile.open("edgedirections.txt", std::ofstream::out | std::ofstream::trunc);
	listFile.close();

	listFile.open("edgedirections.txt", ios::out);
	if (listFile.is_open())
	{
		for (int i = 0; i < graph->edgeDirections.size(); i++)
		{
			listFile << to_string(i);
			listFile << "\n";

			if (graph->edgeDirections[i].first)
				listFile << "1\n";
			else
				listFile << "0\n";

			if (graph->edgeDirections[i].second)
				listFile << "1\n";
			else
				listFile << "0\n";

		}
	}
	listFile.close();
}

void File::saveGraphAdjList()
{
	Graph* graph = Graph::getInstance();

	fstream listFile;
	listFile.open("adjlist.txt", std::ofstream::out | std::ofstream::trunc);
	listFile.close();

	listFile.open("adjlist.txt", ios::out);
	if (listFile.is_open())
	{
		for (int i = 0; i < graph->adjList.size(); i++)
		{
			listFile << "#\n";
			listFile << to_string(i);
			listFile << "\n";

			for (pair<int, int> p : graph->adjList[i])
			{
				listFile << to_string(p.first);
				listFile << "\n";
				listFile << to_string(p.second);
				listFile << "\n";
			}
		}
	}
	listFile.close();
}

void File::saveMapperSize(int Mappertype)
{
	Graph* graph = Graph::getInstance();
	Mapper mapper;
	fstream MapperSizeFile;

	if (Mappertype == nodeMapping)
	{
		mapper = graph->nodeMapper;

		MapperSizeFile.open("nodemappersize.txt", std::ofstream::out | std::ofstream::trunc);
		MapperSizeFile.close();

		MapperSizeFile.open("nodemappersize.txt", ios::out);
	}
	else
	{
		mapper = graph->edgeMapper;

		MapperSizeFile.open("edgemappersize.txt", std::ofstream::out | std::ofstream::trunc);
		MapperSizeFile.close();

		MapperSizeFile.open("edgemappersize.txt", ios::out);
	}

	if (MapperSizeFile.is_open())
	{
		MapperSizeFile << to_string(mapper.maxId);
	}

	MapperSizeFile.close();
}

void File::saveMapperfreeIds(int Mappertype)
{
	Graph* graph = Graph::getInstance();
	Mapper mapper;
	fstream MapperFreeIdsFile;

	if (Mappertype == nodeMapping)
	{
		mapper = graph->nodeMapper;

		MapperFreeIdsFile.open("nodemapperfreeids.txt", std::ofstream::out | std::ofstream::trunc);
		MapperFreeIdsFile.close();

		MapperFreeIdsFile.open("nodemapperfreeids.txt", ios::out);
	}
	else
	{
		mapper = graph->edgeMapper;

		MapperFreeIdsFile.open("edgemapperfreeids.txt", std::ofstream::out | std::ofstream::trunc);
		MapperFreeIdsFile.close();

		MapperFreeIdsFile.open("edgemapperfreeids.txt", ios::out);
	}

	if (MapperFreeIdsFile.is_open())
	{
		for (int i : mapper.freeIds)
			MapperFreeIdsFile << to_string(i) << "\n";
	}

	MapperFreeIdsFile.close();
}

void File::saveMapperList(int Mappertype)
{
	Graph* graph = Graph::getInstance();
	Mapper mapper;
	fstream MapperListFile;

	if (Mappertype == nodeMapping)
	{
		mapper = graph->nodeMapper;

		MapperListFile.open("nodemapperlist.txt", std::ofstream::out | std::ofstream::trunc);
		MapperListFile.close();

		MapperListFile.open("nodemapperlist.txt", ios::out);
	}
	else
	{
		mapper = graph->edgeMapper;

		MapperListFile.open("edgemapperlist.txt", std::ofstream::out | std::ofstream::trunc);
		MapperListFile.close();

		MapperListFile.open("edgemapperlist.txt", ios::out);
	}

	if (MapperListFile.is_open())
	{
		for (auto i : mapper.stringToId)
			MapperListFile << i.first << "\n" << to_string(i.second) << "\n";
	}

	MapperListFile.close();
}

void File::saveEdgeDistance()
{
	Graph* graph = Graph::getInstance();
	EdgeMapper* mapper = &graph->edgeMapper;
	fstream edgeDistanceFile;

	edgeDistanceFile.open("edgedistance.txt", std::ofstream::out | std::ofstream::trunc);
	edgeDistanceFile.close();

	edgeDistanceFile.open("edgedistance.txt", ios::out);
	if (edgeDistanceFile.is_open())
	{
		for (auto i : mapper->idToDistance)
			edgeDistanceFile << to_string(i.first) << "\n" << to_string(i.second) << "\n";
	}

	edgeDistanceFile.close();
}

void File::loadGraphSize()
{
	Graph* graph = Graph::getInstance();

	fstream graphSizeFile;
	graphSizeFile.open("graphsize.txt", ios::in);

	if (graphSizeFile.is_open())
	{
		string sz;
		int cnt = 0;
		while (getline(graphSizeFile, sz))
		{
			if (cnt == 0)
				graph->adjList.resize(stoi(sz));
			else
				graph->edgeDirections.resize(stoi(sz));
		}
	}

	graphSizeFile.close();
}

void File::loadGraphEdgeList()
{
	Graph* graph = Graph::getInstance();

	fstream listFile;
	listFile.open("edgedirections.txt", ios::in);

	if (listFile.is_open())
	{
		string curr;
		int cnt = 0;

		int idx;
		bool direction1, direction2;

		while (getline(listFile, curr))
		{
			if (cnt == 0)
			{
				idx = stoi(curr);
				cnt++;
			}
			else if (cnt == 1)
			{
				direction1 = stoi(curr);
				cnt++;

			}
			else if (cnt == 2)
			{
				direction2 = stoi(curr);
				cnt = 0;
				graph->edgeDirections[idx] = { direction1, direction2 };
			}

		}
	}
	listFile.close();
}

void File::loadGraphAdjList()
{
	Graph* graph = Graph::getInstance();

	fstream listFile;
	listFile.open("adjlist.txt", ios::in);

	if (listFile.is_open())
	{
		string curr;
		int cnt = 0;

		int node1, node2, edge;
		bool takeNode1 = 0;

		while (getline(listFile, curr))
		{
			if (curr == "#")
			{
				takeNode1 = 1;
			}
			else if (takeNode1)
			{
				node1 = stoi(curr);
				takeNode1 = 0;
			}
			else if (cnt == 0)
			{
				node2 = stoi(curr);
				cnt++;
			}
			else if (cnt == 1)
			{
				edge = stoi(curr);;
				cnt = 0;

				graph->adjList[node1].push_back({ node2, edge });
			}
		}
	}
	listFile.close();
}

void File::loadMapperSize(int Mappertype)
{
	Graph* graph = Graph::getInstance();
	Mapper* mapper;
	fstream MapperSizeFile;

	if (Mappertype == nodeMapping)
	{
		mapper = &graph->nodeMapper;
		MapperSizeFile.open("nodemappersize.txt", ios::in);
	}
	else
	{
		mapper = &graph->edgeMapper;
		MapperSizeFile.open("edgemappersize.txt", ios::in);
	}

	if (MapperSizeFile.is_open())
	{
		string sz;
		getline(MapperSizeFile, sz);
		mapper->maxId = stoi(sz);
	}

	MapperSizeFile.close();
}

void File::loadMapperfreeIds(int Mappertype)
{
	Graph* graph = Graph::getInstance();
	Mapper* mapper;
	fstream MapperFreeIdsFile;

	if (Mappertype == nodeMapping)
	{
		mapper = &graph->nodeMapper;
		MapperFreeIdsFile.open("nodemapperfreeids.txt", ios::in);
	}
	else
	{
		mapper = &graph->edgeMapper;
		MapperFreeIdsFile.open("edgemapperfreeids.txt", ios::in);
	}

	if (MapperFreeIdsFile.is_open())
	{
		string curr;
		while (getline(MapperFreeIdsFile, curr))
		{
			mapper->freeIds.push_back(stoi(curr));
		}

	}

	MapperFreeIdsFile.close();
}

void File::loadMapperList(int Mappertype)
{
	Graph* graph = Graph::getInstance();
	Mapper* mapper;
	fstream MapperListFile;

	if (Mappertype == nodeMapping)
	{
		mapper = &graph->nodeMapper;
		MapperListFile.open("nodemapperlist.txt", ios::in);
	}
	else
	{
		mapper = &graph->edgeMapper;
		MapperListFile.open("edgemapperlist.txt", ios::in);
	}

	if (MapperListFile.is_open())
	{
		string name;
		int id;

		string curr;
		int cnt = 0;
		while (getline(MapperListFile, curr))
		{
			if (cnt == 0)
			{
				name = curr;
				cnt++;
			}
			else if (cnt == 1)
			{
				id = stoi(curr);
				cnt = 0;

				mapper->stringToId[name] = id;
				mapper->idToString[id] = name;

			}
		}
	}

	MapperListFile.close();
}

void File::loadEdgeDistance()
{
	Graph* graph = Graph::getInstance();
	EdgeMapper* mapper = &graph->edgeMapper;
	fstream edgeDistanceFile;


	edgeDistanceFile.open("edgedistance.txt", ios::in);
	if (edgeDistanceFile.is_open())
	{
		int id, dis;

		string curr;
		int cnt = 0;

		while (getline(edgeDistanceFile, curr))
		{
			if (cnt == 0)
			{
				id = stoi(curr);
				cnt++;
			}
			else
			{
				dis = stoi(curr);
				cnt = 0;

				mapper->idToDistance[id] = dis;
			}
		}
	}

	edgeDistanceFile.close();
}


void File::load()
{
	loadGraphSize();
	loadGraphEdgeList();
	loadGraphAdjList();
	loadMapperSize(nodeMapping);
	loadMapperSize(edgeMapping);
	loadMapperfreeIds(nodeMapping);
	loadMapperfreeIds(edgeMapping);
	loadMapperList(nodeMapping);
	loadMapperList(edgeMapping);
	loadEdgeDistance();

}

void File::save()
{
	saveGraphSize();
	saveGraphEdgeList();
	saveGraphAdjList();
	saveMapperSize(nodeMapping);
	saveMapperSize(edgeMapping);
	saveMapperfreeIds(nodeMapping);
	saveMapperfreeIds(edgeMapping);
	saveMapperList(nodeMapping);
	saveMapperList(edgeMapping);
	saveEdgeDistance();
}
