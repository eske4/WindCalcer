#pragma once

#include "getWindProData.h"

namespace WindProSystem {
  
  class WindPro {
    public:
    // Constructor
    WindPro(std::string fileLoc);

    // Member functions
    void myFunction1();
    int myFunction2();

  private:
    WindProData data;
  };
}