#ifndef PLUGBOARD
#define PLUGBOARD

#include "Encoder.hpp"

class Plugboard {

  //Plugboard takes in plug configuration
  public:
    Plugboard(std::ifstream&);
    void encode(char&);
  private:
    std::vector<int> configArray{std::vector<int>(ALPHA_LENGTH,
        VECTOR_INITIALIZE)};
};

#endif
