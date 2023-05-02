#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <array>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <memory>

union windProData
{
    std::tm timestamp;
    double data; 
    bool comment;
};


void printData(std::string inputFile);
std::ifstream isFileOpen(std::string fileLoc);
std::unique_ptr<const std::string[]> getHeaders(std::ifstream &file, size_t &arrSize);
