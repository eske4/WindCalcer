#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

union windProData
{
    std::tm timestamp;
    double data; 
    bool comment;
};


void printData(std::string inputFile);
std::ifstream isFileOpen(std::string fileLoc);