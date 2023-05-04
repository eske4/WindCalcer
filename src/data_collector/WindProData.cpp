#include "WindProData.h"

namespace WindProSystem {

  // Constructor implementation
  WindPro::WindPro(std::string fileLoc) {
    data = fetchWindproData(fileLoc);
  }

  // Member function implementations
  void WindPro::myFunction1() {
    // your code here
  }

  int WindPro::myFunction2() {
    // your code here
    return 0;
  }

}