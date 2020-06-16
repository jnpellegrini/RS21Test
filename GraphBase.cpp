#include "GraphBase.h"

#include <iostream>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
GraphBase::GraphBase(HashDataMap map) :
	m_map(map)
{
	WriteHeader();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
GraphBase::WriteHeader()
{
	m_szFileContents << "<head>\n\t<script src=\"plotly-latest.min.js\"></script>\n"
					 << "</head>\n<body>\n\t<div id=\"plotDiv\" style=\"width:1160px;"
					 << "height:726px;\"></div>\n</body>\n\n<script>\n\n";
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
GraphBase::WriteLastLines()
{
	// have this write the footer info
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
GraphBase::WriteFileToDisk(std::string szName)
{
	std::ofstream outdata;
	outdata.open(szName);

	outdata << m_szFileContents.str();
	outdata.close();
}
