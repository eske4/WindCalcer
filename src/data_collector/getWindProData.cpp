#include "getWindProData.h"

WindProData fetchWindproData(std::string fileLoc)
{
    auto windProData = getData(isFileOpen(fileLoc));
    return windProData;
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
std::unique_ptr<const std::string[]> getHeaders(std::ifstream &file, size_t &arrSize)
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

    // Convert the vector to a const string array and return it as a unique_ptr
    auto ptr = std::make_unique<std::string[]>(Headers.size());
    for(size_t i = 0; i < Headers.size(); i++)
        ptr[i] = Headers.at(i);
    
    // Set the array size and return the unique_ptr
    arrSize = Headers.size();
    return ptr;
}

WindProData getData(std::ifstream file)
{
    size_t headerSize{};
    auto headers = getHeaders(file, headerSize);
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

    auto ptrWindData = std::make_unique<std::unique_ptr<const WindData[]>[]>(placeHolder.size());
    auto ptrInnerSize = std::make_unique<size_t[]>(placeHolder.size());

    for (size_t i = 0; i < placeHolder.size(); i++)
    {
        auto ptrPlaceHolder = std::make_unique<WindData[]>(placeHolder.at(i).size());
        for(size_t j = 0; j < placeHolder[i].size(); j++)
        {
            if(j == 0)
                {
                    WindData time{};
                    time.timestamp = placeHolder.at(i).at(j).timestamp;
                    ptrPlaceHolder[j] = time;
                }
            else
                ptrPlaceHolder[j] = WindData{.data = placeHolder.at(i).at(j).data};
        }
        ptrInnerSize[i] = std::move(placeHolder[i].size());
        ptrWindData[i] = std::move(ptrPlaceHolder);
    }

    for(size_t i = 0; i < placeHolder.size(); i++)
    {
        for(size_t j = 0; j < placeHolder.at(i).size(); j++)
        {
            if(j == 0) 
                std::cout << std::put_time(&ptrWindData[i][j].timestamp, "%Y-%m-%d %H:%M:%S") << " ";
            else
                std::cout << ptrWindData[i][j].data << " ";
        } 
        std::cout << "\n";  
    }

    return {std::move(ptrWindData), std::move(headers), std::move(ptrInnerSize), headerSize, placeHolder.size()};
}

bool is_double(const std::string& str) {
        std::istringstream ss(str);
        double d;
        return (ss >> d) && (ss.eof()) && (!ss.fail()) && (d != std::numeric_limits<double>::infinity())
            && (d != -std::numeric_limits<double>::infinity()) && (d == d);
    }
