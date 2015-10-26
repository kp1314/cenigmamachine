#include <iostream>
#include <fstream>
#include "Encoder.hpp"

class Rotor { 

  //Rotor takes in rotor configuration 
  public: 
    Rotor(std::ifstream&);
    void rotate(void);
    void setOppositeConfiguration(bool);
    void encode(char&);
  private:
    int numberOfRotations;
    bool isOppositeConfiguration;
    std::vector<int> configArray{std::vector<int>(ALPHA_LENGTH,
        VECTOR_INITIALIZE)};
};

