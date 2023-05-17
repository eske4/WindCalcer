#include "getWindProData.h"

// Read wind data from a file and return a WindProData object
std::unique_ptr<WindProData> readWindProDataFromFile(std::string fileLoc)
{ 
    return extractDataFromFile(openFile(fileLoc));
}

// Open a file and return the input file stream
std::unique_ptr<std::ifstream> openFile(const std::string& fileLoc)
{
    std::ifstream text;
    text.open(fileLoc, std::fstream::binary);

    if (!text.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    return std::make_unique<std::ifstream>(std::move(text));
}

// Extract headers from the file and return them as a vector of strings
std::vector<std::string> extractHeadersFromFile(std::unique_ptr<std::ifstream> &file)
{
    // Read until the "TimeStamp" line to skip the metadata
    std::string line{};
    while (*file >> line) {
        if (line == "TimeStamp") {
            file->seekg(-9L, std::ios::cur);
            break;
        }
    }

    if(file->eof())
    {
        file->close();
        throw std::runtime_error("No time stamp found in file");
    }

    // Read the headers from the file and store them in a vector
    std::vector<std::string> Headers{};
    std::getline(*file, line);
    boost::split(Headers, line, boost::is_any_of("\t"));
    Headers.pop_back();

    if(Headers.size() == 0)
    {
        file->close();
        throw std::runtime_error("No headers found in file");
    }

    return Headers;
}

// Extract wind data from the file and return a WindProData object
std::unique_ptr<WindProData> extractDataFromFile(std::unique_ptr<std::ifstream> file)
{
    auto headers = extractHeadersFromFile(file);
    std::string line;
    std::getline(*file, line);
    std::vector<std::vector<WindData>> placeHolder{};

    // Read each line of data from the file and store it in a vector
    while(std::getline(*file, line))
    {
        std::vector<WindData> aLineOfData{};
        std::vector<std::string> data;
        boost::split(data, line, boost::is_any_of("\t"));

        // Parse the timestamp from the first element in the line of data
        {
            std::tm timeStamp{};
            std::istringstream ss{ data.at(0) };
            ss >> std::get_time(&timeStamp, "%d-%m-%Y %H:%M");
            aLineOfData.emplace_back(WindData{.timestamp = std::move(timeStamp)});
        }
    
        // Parse the wind data from the remaining elements in the line of data
        bool isLoopBroken = false;
        for (size_t i = 1; i < data.size(); i++) {
            if (!data.at(i).empty()) {
                double d;
                const char* begin = data.at(i).c_str();
                const char* end = begin + data.at(i).size();
                auto result = std::from_chars(begin, end, d);
                if (result.ec == std::errc())
                {
                    aLineOfData.emplace_back(WindData{.data = std::move(d)});
                }
                else
                {
                    isLoopBroken = true;
                    break;
                }    
            }
        }
        if (!isLoopBroken)
        {
            placeHolder.emplace_back(std::move(aLineOfData));
        }
    }

    // Create and return a WindProData object containing the wind data and headers
    if(placeHolder.size() == 0)
    {
        throw std::runtime_error("No data found in file");
        file->close();
    }

    file->close();

    return std::make_unique<WindProData>(std::move(placeHolder), std::move(headers));
}
