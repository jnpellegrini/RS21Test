#include "DataParser.h"

#include <iostream>

#include "BarGraph.h"
#include "MapGraph.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
DataParser::DataParser(boost::property_tree::ptree pt) :
	m_ptree(pt)
{
	
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool
DataParser::ParseData()
{
	for(auto& e : m_ptree.get_child("features"))
	{
		for(auto& r : e.second.get_child("properties"))
		{
			m_map[r.first].push_back(r.second.get_value<std::string>());
		}
	}
	return m_map.size() != 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool
DataParser::PrepHTMLForPlotly()
{
	BarGraph bg(m_map);
	MapGraph mp(m_map);

	return true;
}
