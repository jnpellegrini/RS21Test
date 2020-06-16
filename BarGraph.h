#ifndef BAR_GRAPH_H
#define BAR_GRAPH_H

#include "GraphBase.h"

class BarGraph : public GraphBase
{
public:
	BarGraph(HashDataMap map);

	virtual void WriteGraphFileContents() override;

private:
	int GetPopulation(std::vector<std::string> aszValues);
};

#endif BAR_GRAPH_H
