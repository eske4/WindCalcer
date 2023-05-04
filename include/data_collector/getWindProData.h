#pragma once

#include <boost/date_time.hpp>
#include <boost/date_time/posix_time/posix_time_io.hpp>
#include <boost/algorithm/string.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <limits>
#include <array>
#include <vector>
#include <memory>
#include <charconv>

union WindData
{
    std::tm timestamp;
    double data; 
};

struct WindProData
{
    std::vector<std::vector<WindData>> windData;
    std::vector<std::string> Headers;
};


WindProData readWindProDataFromFile(std::string fileLoc);
std::ifstream openFile(std::string& fileLoc);
std::vector<std::string> extractHeadersFromFile(std::ifstream &file);
WindProData extractDataFromFile(std::ifstream file);