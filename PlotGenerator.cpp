#include "PlotGenerator.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
PlotGenerator::PlotGenerator(boost::property_tree::ptree pt):
	m_parser(pt)
{
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool
PlotGenerator::GenerateGraphs()
{
	if ( ! m_parser.ParseData() )
		return false;

	if ( ! m_parser.PrepHTMLForPlotly() )
		return false;

	return true;
}
