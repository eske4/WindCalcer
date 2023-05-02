#include "getWindProData.h"

void printData(std::string fileLoc)
{
    // Open the file
    std::ifstream file = isFileOpen(fileLoc);

    // Read the headers from the file
    size_t arrSize{};
    std::unique_ptr<const std::string[]> Headers = getHeaders(file, arrSize);

    // Print the headers to the console
    for(size_t i = 0; i < arrSize; i++)
    {
        std::cout << Headers[i] << "\n";
    }
}

// Open a file and return the input file stream
std::ifstream isFileOpen(std::string fileLoc)
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
    std::string line;
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


