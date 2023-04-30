#include <iostream>
#include "file_dialog.h"

std::string openFileDialog()
{
    // File open
    auto selection = pfd::open_file("Select a file").result();
    return selection[0];
}