#ifndef PLOT_GENERATOR_H
#define PLOT_GENERATOR_H

#include "boost/property_tree/ptree.hpp"
#include "DataParser.h"

class PlotGenerator
{
public:
    PlotGenerator(boost::property_tree::ptree pt);
    bool GenerateGraphs();

private:
    DataParser m_parser;
};

#endif PLOT_GENERATOR_H
