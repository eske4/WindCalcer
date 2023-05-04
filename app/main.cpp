#include <iostream>
#include "config.hpp"
#include "file_dialog.h"
#include "UI.h"
#include "WindProData.h"

int main()
{
    std::cout << project_name << " ";
    std::cout << project_version << "\n";

    draw();

    std::vector<WindProSystem::WindPro> windarr;

    for (size_t i = 0; i < 5; i++) {
    windarr.push_back(WindProSystem::WindPro(openFileDialog()));
    }

    std::cout << "Files loaded: " << windarr.size();

    std::cout << "\n";

    windarr.at(0).myFunction1();

    return 0;
}
