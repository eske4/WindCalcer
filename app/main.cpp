#include <iostream>
#include "config.hpp"
#include "file_dialog.h"
#include "UI.h"
#include "getWindProData.h"

int main()
{
    std::cout << project_name << " ";
    std::cout << project_version << "\n";

    draw();

    std::cout << "\n";

    printData(openFileDialog());

    return 0;
}
