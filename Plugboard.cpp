#include "Plugboard.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

Plugboard::Plugboard() {
  
}

void Plugboard::configurePlugboard(std::ifstream& file) {
  
  if(file) {
   
    int i = 0;
    
    while(file >> i) {
      
      int j = 0;
      file >> j;
      
      configArray[i] = j;
      configArray[j] = i;
 
    }    

  } else {
 
  throw std::invalid_argument("can't configure Plugboard");
 }
}

void Plugboard::swapIO(char& keyPressed) {

  int switchedKey = 0;
  
    if(keyPressed >= 65 && keyPressed <= 90) {
   
      switchedKey = configArray[keyPressed-65];

      if(switchedKey >= 0) {
        keyPressed = switchedKey + 65;
        
      }

    } else {
 
      throw std::invalid_argument("input error"); 

    } 

}
