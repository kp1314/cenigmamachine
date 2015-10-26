// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <memory>
#include <stdexcept>
#include <math.h>
#include "Encoder.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"
#include "Plugboard.hpp"

using namespace std;

int main(int argc, char **argv)
{
  if (argc < 2) {
  
    cout << "Please give the plugboard configuration file as an argument" 
         << endl;
    return -1;

  } else {

    int rotorCount = 0;
    vector<shared_ptr<Rotor>> rotorVec;
    shared_ptr<Reflector> pReflector(new Reflector());   

    //configure the rotors
    while (rotorCount < argc-2) {
      std::ifstream rotConfig;
      rotConfig.open(argv[rotorCount+1], std::ifstream::in);
      rotorVec.push_back(shared_ptr<Rotor>(new Rotor(rotConfig)));
      rotorCount++;
      rotConfig.close();
    }
   
    //after this point rotorCount is now (argc-2)

    //configure the plugboard
    ifstream plugConfig;
    plugConfig.open(argv[argc-1]);
    shared_ptr<Plugboard> pPlugboard(new Plugboard(plugConfig));
    plugConfig.close();
 
    int i = 0;
    int rotationsOfFirstRotor = 0;
    string keysPressed; 

    while (cin >> ws >> keysPressed) {     

    for (char& c : keysPressed) {
      
      //put though the plugboard
      pPlugboard->encode(c);
      
      //put through the rotors
      while (i <= 2*(rotorCount)) {  
     
        if (i < (rotorCount)) { 
          rotorVec.at(i)->encode(c);
        } else if (i == (rotorCount)) {
          pReflector->encode(c);
          for (auto r : rotorVec) {
            r->setOppositeConfiguration(true);
          } 
        } else if (i > (rotorCount)) {
          rotorVec.at((2*(rotorCount))%i)->encode(c);
        }
          i++;
      } 
      
      //rotate rotors that need rotating;
      
      rotationsOfFirstRotor++;   
      for (int k = 0; k < (rotorCount); k++) {

        if ((rotationsOfFirstRotor%
            (int)(pow(ALPHA_LENGTH,k)) == 0)) {
          
          rotorVec.at(k)->rotate();

        }        
      } 
     
      //going through rotors forwads now
      for (auto r : rotorVec) {
        r->setOppositeConfiguration(false);
      }
      
      //reset rotor counter, pass char through plugboard 
      i = 0;
      pPlugboard->encode(c);
    
    }
    
    cout << keysPressed;
  } 
}


  return 0;
}
