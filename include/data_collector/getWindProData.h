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

union WindData
{
    std::tm timestamp;
    double data; 
};

struct WindProData
{
    std::unique_ptr<std::unique_ptr<const WindData[]>[]> windData;
    std::unique_ptr<const std::string[]> Headers;
    std::unique_ptr<size_t[]> innerDataSize;
    size_t headerSize;
    size_t outerDataSize;
};

WindProData fetchWindproData(std::string fileLoc);
std::ifstream isFileOpen(std::string& fileLoc);
std::vector<std::string> getHeaders(std::ifstream &file);
WindProData getData(std::ifstream file);
bool is_double(const std::string& str);