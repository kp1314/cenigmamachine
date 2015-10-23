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
  if (argc < 2) {
  
    cout << "Please give the plugboard configuration file as an argument" << endl;
    return -1;

  } else {

    int rotorCount = 0;
    vector<shared_ptr<Rotor>> rotorVec;
    shared_ptr<Plugboard> pPlugboard(new Plugboard());
    shared_ptr<Reflector> pReflector(new Reflector());   

    //configure the rotors
    while (rotorCount < argc-2) {
      std::ifstream rotConfig;
      rotConfig.open(argv[rotorCount+1], std::ifstream::in);
      rotorVec.push_back(shared_ptr<Rotor>(new Rotor()));
      rotorVec.at(rotorCount)->configureRotor(rotConfig);
      rotorCount++;
      rotConfig.close();
    }

    //configure the plugboard
    std::ifstream plugConfig;
    plugConfig.open(argv[argc-1]);
    pPlugboard->configurePlugboard(plugConfig);
 
    string keysPressed;
    cin >> keysPressed;

    int i = 0;
    int rotationsOfFirstRotor = 0;

    for (char& c : keysPressed) {
        
      //put though the plugboard
      pPlugboard->swapIO(c);
      
      //put through the rotors
      while (i <= 2*(argc-2)) {  
     
        if (i < (argc-2)) { 
          rotorVec.at(i)->encode(c);
        } else if (i == (argc-2)) {
          pReflector->reflect(c);
          for (auto r : rotorVec) {
            r->setOppositeConfiguration(true);
          } 
        } else if (i > (argc-2)) {
          rotorVec.at((2*(argc-2))%i)->encode(c);
        }
          i++;
      } 
      
      //rotate rotors that need rotating;
      for (int k = 0; k < (argc-2); k++) {

        if (k !=0 && (rotationsOfFirstRotor%(26^k) == 0)) {
          rotorVec.at(k)->rotate();
        }
          rotationsOfFirstRotor++;   
      } 
     
      //going through rotors forwads now
      for (auto r : rotorVec) {
        r->setOppositeConfiguration(false);
      }
      
      //reset rotor counter, pass char through plugboardOB 
      i = 0;
      pPlugboard->swapIO(c);
    
    } 
    cout << keysPressed << endl;
  }

  return 0;
}
