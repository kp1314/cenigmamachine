// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <memory>
#include <stdexcept>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Reflector.hpp"
#include "Rotor.hpp"
#include "Plugboard.hpp"

using namespace std;

int main(int argc, char **argv)
{
  if (argc <= 2) {
  
    cout << "Please give the rotor and plugboard configuration files as arguments" << endl;
    return -1;

  } else {

    int rotorCount = 0;
    vector<shared_ptr<Rotor>> rotorVec(argc-2);
    shared_ptr<Plugboard> pPlugboard(new Plugboard());
 
    //configure the rotors
    while (rotorCount < argc-2) {
      std::ifstream rotConfig;
      rotConfig.open(argv[rotorCount+1], std::ifstream::in);
      rotorVec.at(rotorCount)->configureRotor(rotConfig);
      rotorCount++;
      rotConfig.close();
    }

    //configure the plugboard
    std::ifstream plugConfig;
    plugConfig.open(argv[argc-1]);
    pPlugboard->configurePlugboard(plugConfig);

    cout << "Press any uppercase alphabet key";

    char keyPressed;
    cin >> keyPressed;
    cout << "you pressed " << keyPressed << endl;
     

  }

  return 0;
}
