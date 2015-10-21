#include <iostream>
#include <fstream>
#include <vector>

class Rotor { 

  //Rotor takes in rotor configuration 
  public: 
    Rotor();
    char encode(char);  
    void rotate(void);
    void configureRotor(std::ifstream&);
  private:
    std::vector<int> configArray{std::vector<int>(26,0)};
    int numberOfRotations;

};
