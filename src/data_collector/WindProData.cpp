#include "WindProData.h"

namespace WindProSystem {

  // Constructor implementation
  WindPro::WindPro(std::string fileLoc) {
    data = fetchWindproData(fileLoc);
  }

  // Member function implementations
  void WindPro::myFunction1() {
    std::cout << data.Headers.at(0) << "\n";
    std::cout << data.windData.at(0).at(1).data << "\n";
  }

  int WindPro::myFunction2() {
    // your code here
    return 0;
  }

}