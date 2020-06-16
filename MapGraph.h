#ifndef MAP_GRAPH_H
#define MAP_GRAPH_H

#include "GraphBase.h"
#include "boost/property_tree/ptree.hpp"


class MapGraph : public GraphBase
{
public:
	MapGraph(HashDataMap map);

	virtual void WriteGraphFileContents() override;

private:
	void ParseXmlData();
	bool IsNumber(const std::string& szLine);

	std::vector<std::string> lats;
	std::vector<std::string> longs;
	std::vector<int> m_toSkip;

};

#endif MAP_GRAPH_H
