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


std::unique_ptr<WindProData> readWindProDataFromFile(std::string fileLoc);
std::unique_ptr<std::ifstream> openFile(const std::string& fileLoc);
std::vector<std::string> extractHeadersFromFile(std::unique_ptr<std::ifstream> &file);
std::unique_ptr<WindProData> extractDataFromFile(std::unique_ptr<std::ifstream> file);