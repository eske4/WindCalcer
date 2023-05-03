#include <iostream>
#include "config.hpp"
#include "file_dialog.h"
#include "UI.h"
#include "WindProData.h"
using namespace WindProSystem;

int main()
{
    std::cout << project_name << " ";
    std::cout << project_version << "\n";

    draw();

    std::vector<WindProSystem::WindPro> windarr;

    for (size_t i = 0; i < 5; i++) {
    windarr.push_back(WindProSystem::WindPro(openFileDialog()));
}

    std::cout << "\n";

    return 0;
}
