#include "getWindProData.h"

void printData(std::string fileLoc)
{
     
    std::ifstream data = isFileOpen(fileLoc);
    std::string line{};

    while (data >> line) {  // loop until data starts
    std::cout << line << " ";
    if (line == "TimeStamp") {
        
        data.seekg(-9L, std::ios::cur);
        break;
    }
  }
}

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