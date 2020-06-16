// PlotlyGrapgGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "boost/property_tree/json_parser.hpp"
#include "boost/property_tree/ptree.hpp"

#include "PlotGenerator.h"

int main(int argc, char *argv[])
{
	std::string szFileToRead;
	if ( argc == 1 )
		szFileToRead = "BernallioCensusBlocks_Joined.json";
	else if (argc == 2)
		szFileToRead = argv[1];
	else
		return EXIT_FAILURE;
		//throw error and exit fail

	boost::property_tree::ptree pt;
	boost::property_tree::read_json(szFileToRead, pt);

	PlotGenerator pg(pt);
	if ( ! pg.GenerateGraphs() )
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

