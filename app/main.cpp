#include <iostream>
#include "config.hpp"
#include "file_dialog.h"

int main()
{
    std::cout << project_name << " ";
    std::cout << project_version << "\n";

    auto fileloc = openFileDialog();

    std::cout << fileloc << "\n";

    return 0;
}
