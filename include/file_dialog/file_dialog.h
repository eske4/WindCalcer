#pragma once

#include "portable-file-dialogs.h"
#include <string>

std::string  openFileDialog();
std::ifstream isFileOpen(std::string fileLoc);