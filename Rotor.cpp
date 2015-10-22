#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include "Rotor.hpp"

Rotor::Rotor() {
  
  isOppositeConfiguration=false;
  numberOfRotations = 0;
}

void Rotor::configureRotor(std::ifstream& file) { 

  if (file) {
 
    int i = 0;
    int j = 0;
        
    while(file >> i) {
      configArray.at(j) = i;
      j++;
    }  

  } else {
    
    throw std::invalid_argument("file didnt open correctly");
 
  }
}

//checks in rotConfig which char contactInput is mapped to taking into
//account the number of rotations taken by the rotor
void Rotor::encode(char& keyPressed) {
  
    if (keyPressed >= 65 && keyPressed <= 90) {

      if (!isOppositeConfiguration) {

        keyPressed = configArray[((keyPressed-65)+numberOfRotations)%26]-numberOfRotations+65;
        
      } else {      

        for (int i = 0; i < 26; i++) {
          if (configArray[i] == keyPressed-65) {
            keyPressed = i+numberOfRotations+65;
            break;
          }
        }
     }

    } else {
      std::cout << "Character was not a valid character" << std::endl;
      exit(107);
    }
  }

void Rotor::setOppositeConfiguration(bool b) {
  isOppositeConfiguration = b; 
}

void Rotor::rotate(void) {
  numberOfRotations = (numberOfRotations+1)%26;
}
