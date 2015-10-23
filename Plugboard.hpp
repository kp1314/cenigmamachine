#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Plugboard {

  //Plugboard takes in plug configuration
  public:
    Plugboard();
    void configurePlugboard(std::ifstream&);
    void swapIO(char&);
  private:
    std::vector<int> configArray{std::vector<int>(26,-1)};
};
