#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Rotor { 

  //Rotor takes in rotor configuration 
  public: 
    Rotor();
    void rotate(void);
    void encode(char&);  
    void configureRotor(std::ifstream&);
    void setOppositeConfiguration(bool);
  private:
    std::vector<int> configArray{std::vector<int>(26,0)};
    int numberOfRotations;
    bool isOppositeConfiguration;

};
