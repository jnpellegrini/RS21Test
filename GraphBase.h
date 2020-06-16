#ifndef GRAPH_BASE_H
#define GRAPH_BASE_H

#include "Utils.h"

#include <fstream>
#include <sstream>

class GraphBase
{
public:
	GraphBase(HashDataMap map);

	virtual void WriteGraphFileContents() = 0;

protected:
	void WriteHeader();
	void WriteLastLines();
	void WriteFileToDisk(std::string szName);

	HashDataMap m_map;

	std::stringstream m_szFileContents;
};

#endif GRAPH_BASE_H
