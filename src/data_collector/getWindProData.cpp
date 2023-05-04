#include "getWindProData.h"

WindProData fetchWindproData(std::string fileLoc)
{ 
    return getData(isFileOpen(fileLoc));
}

// Open a file and return the input file stream
std::ifstream isFileOpen(std::string& fileLoc)
{
    std::ifstream text;
    text.open(fileLoc);

    if (!text.is_open()) {
        std::cout << "Error: could not find file";
        std::terminate();
    }
    return text;
}

// Read the headers from the file and return them as a unique_ptr to a const string array
std::vector<std::string> getHeaders(std::ifstream &file)
{
    // Read until the "TimeStamp" line to skip the metadata
    std::string line{};
    while (file >> line) {
        if (line == "TimeStamp") {
            file.seekg(-9L, std::ios::cur);
            break;
        }
    }

    // Read the headers from the file and store them in a vector
    std::vector<std::string> Headers{};
    std::getline(file, line);
    boost::split(Headers, line, boost::is_any_of("\t"));
    Headers.pop_back();

    return Headers;
}

WindProData getData(std::ifstream file)
{
    auto headers = getHeaders(file);
    std::string line;
    std::getline(file, line);
    std::vector<std::vector<WindData>> placeHolder{};

    while(std::getline(file, line))
    {
        std::vector<WindData> aLineOfData{};
        std::vector<std::string> data;
        boost::split(data, line, boost::is_any_of("\t"));

        {
            std::tm timeStamp{};
            std::istringstream ss{ data.at(0) };
            ss >> std::get_time(&timeStamp, "%d-%m-%Y %H:%M");
            WindData time;
            time.timestamp = timeStamp;
            aLineOfData.emplace_back(time);
        }
    
        for (size_t i = 1; i < data.size(); i++)
        {
            if(!data.at(i).empty() && is_double(data.at(i)))
                aLineOfData.emplace_back(WindData{.data = std::stod(data.at(i))});    
        }
        placeHolder.emplace_back(aLineOfData);
    }
    return WindProData{placeHolder, headers};
}

bool is_double(const std::string& str) {
        std::istringstream ss(str);
        double d;
        return (ss >> d) && (ss.eof()) && (!ss.fail()) && (d != std::numeric_limits<double>::infinity())
            && (d != -std::numeric_limits<double>::infinity()) && (d == d);
    }
