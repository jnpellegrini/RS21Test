#ifndef DATA_PARSER_H
#define DATA_PARSER_H

#include "boost/property_tree/ptree.hpp"

#include "Utils.h"

class DataParser
{
public:
    DataParser(boost::property_tree::ptree pt);
    bool ParseData();
    bool PrepHTMLForPlotly();
    HashDataMap m_map;
private:
    boost::property_tree::ptree m_ptree;

};

#endif DATA_PARSER_H
