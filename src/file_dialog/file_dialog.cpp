#include "file_dialog.h"

std::string openFileDialog()
{
    // File open
    auto fileLoc = pfd::open_file("Select a file").result();
    if(fileLoc.empty())
    {
        return "";
    }
    std::cout << fileLoc[0] << "\n";
    return fileLoc[0];
}