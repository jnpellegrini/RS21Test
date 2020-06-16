#include "BarGraph.h"

#include <iostream>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
BarGraph::BarGraph(HashDataMap map) :
	GraphBase(map)
{
	WriteGraphFileContents();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
BarGraph::WriteGraphFileContents()
{
	// Bernco Pop by sex
	// HD01_VD26 - Female
	// HD01_VD02 - Male

	int iPopulationFemale = 0;
	int iPopulationMale = 0;
	m_szFileContents << "var trace1 = {\n\tx: ['BernCo Population'],\n\ty: [";
	auto it = m_map.find("ACS_13_5YR_B01001_with_ann_HD01_VD26");
	if (it != m_map.end())
		iPopulationFemale = GetPopulation(it->second);

	m_szFileContents << iPopulationFemale << "],\n\tname: 'Population Female',\n\ttype: 'bar'\n};\n"
					 << "var trace2 = {\n\tx: ['BernCo Population'],\n"
					 << "\ty: [";

	it = m_map.find("ACS_13_5YR_B01001_with_ann_HD01_VD02");
	if (it != m_map.end())
		iPopulationMale = GetPopulation(it->second);

	m_szFileContents << iPopulationMale << "],\n\tname: 'Population Male',\n\ttype: 'bar'\n};"
					 << "\nvar data = [trace1, trace2]\nvar layout = {barmode: 'stack'};\n\n"
					 << "Plotly.newPlot('plotDiv', data, layout);\n\n</script>";

	WriteFileToDisk("BarGraph.html");
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int
BarGraph::GetPopulation(std::vector<std::string> aszValues)
{
	int iPop = 0;
	for (std::string szValue : aszValues)
		iPop += std::stoi(szValue);

	return iPop;
}
