#include "MapGraph.h"

#include <fstream>
#include <iostream>

#include "boost/tokenizer.hpp"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
MapGraph::MapGraph(HashDataMap map) :
	GraphBase(map)
{
    m_szFileContents.clear();
	ParseXmlData();
	WriteGraphFileContents();
    WriteFileToDisk("MapGraph.html");
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
MapGraph::WriteGraphFileContents()
{
	m_szFileContents << "var data = [{\n\ttype:'scattermapbox',\n\tlat:['";
    m_szFileContents << lats[0] << "'";
    for (int i = 1; i < lats.size(); i++)
    {
        if ( !IsNumber(lats[i]))
        {
            m_toSkip.push_back(i);
            continue;
        }

        m_szFileContents << ", '";
        int iIndex = lats[i].find(",");
        if ( iIndex != std::string::npos )
            m_szFileContents << lats[i].substr(0,iIndex - 1);
        else
            m_szFileContents << lats[i];

        m_szFileContents << "'";
    }

    m_szFileContents << "],\n\tlon: ['";
    m_szFileContents << longs[0] << "'";
    for (int i = 1; i < longs.size(); i++)
    {
        if ( std::find(m_toSkip.begin(), m_toSkip.end(), i) != m_toSkip.end() )
            continue;

        m_szFileContents << ", '";
        int iIndex = longs[i].find(",");
        if ( iIndex != std::string::npos )
            m_szFileContents << longs[i].substr(0,iIndex - 1);
        else
            m_szFileContents << longs[i];

        m_szFileContents << "'";
    }

    m_szFileContents << "],\n\tmode:'markers',\n\tmarker: {\n\t\tsize:14\n\t},}]\n\nvar layout = {\n\tautosize: true,\n\t"
                     << "hovermode:'closest',\n\tmapbox: {\n\tbearing:0,\n\tcenter: {\n\tlat:35,\n\tlon:-105\n},\n\tpitch:0,\n\t"
                     << "zoom:5\n\t},\n}\n\nPlotly.setPlotConfig({\nmapboxAccessToken: \"pk.eyJ1IjoianBlZ2FicSIsImEiOiJja2JoMWRtODgwMHlmMm9xbmFndGdqdzU4In0.JeXfs_Z6VjRDvtG7oiWHnA\"\n\t"
                     << "})\nPlotly.newPlot('plotDiv', data, layout);\n</script>";
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
MapGraph::ParseXmlData()
{
    std::fstream in("Twitter_141103.csv");
    if ( in.is_open() )
    {
        typedef boost::tokenizer< boost::escaped_list_separator<char> > Tokenizer;
        std::string line;

        while (std::getline(in,line))
        {
            int iIndex = 1;
            bool bLatFound = false;
            bool bFoundBoth = false;
            boost::char_separator<char> obj(",");
            boost::tokenizer<boost::char_separator<char> > tokens(line,obj);
            for(boost::tokenizer<boost::char_separator<char> >::iterator it=tokens.begin();
                it!=tokens.end(); ++it)
            {
                if ( iIndex >= 3)
                {
                    if (std::isdigit((*it)[0]) || (*it) == "-")
                    {
                        lats.push_back(*it);
                        bLatFound = true;
                        iIndex++;
                        continue;
                    }
                }
                if ( iIndex >= 4 && bLatFound)
                {
                    longs.push_back(*it);
                    bLatFound = false;
                    break;
                }

                iIndex++;
            }
        }
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool
MapGraph::IsNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && ( std::isdigit(*it) || (*it) == '-' || (*it) == '.' ) ) 
        ++it;
    return !s.empty() && it == s.end();
}
