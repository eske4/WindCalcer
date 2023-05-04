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
    std::vector<std::vector<WindData>> windData;
    std::vector<std::string> Headers;

    WindProData(std::vector<std::vector<WindData>> windData, std::vector<std::string> Headers)
    {
        this->windData = windData;
        this->Headers = Headers;
    }

    WindProData(const WindProData& other)
    {
        windData = other.windData;
        Headers = other.Headers;
    }

    WindProData& operator=(const WindProData& other)
    {
        if (this != &other)
        {
            windData = other.windData;
            Headers = other.Headers;
        }
        return *this;
    };

    ~WindProData() = default;
    WindProData() = default;
};


WindProData fetchWindproData(std::string fileLoc);
std::ifstream isFileOpen(std::string& fileLoc);
std::vector<std::string> getHeaders(std::ifstream &file);
WindProData getData(std::ifstream file);
bool is_double(const std::string& str);