#include <iostream>
#include "config.hpp"
#include "file_dialog.h"
#include "UI.h"

int main()
{
    std::cout << project_name << " ";
    std::cout << project_version << "\n";

    auto fileloc = openFileDialog();

    std::cout << fileloc << "\n";

    draw();

    std::cout << "\n";

    return 0;
}
