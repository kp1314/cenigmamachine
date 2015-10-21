#include "Plugboard.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

Plugboard::Plugboard() {
  
}

void Plugboard::configurePlugboard(std::ifstream& file) {
  
  if(file) {
   
    int i;
    
    while(file >> i) {
      
      int j;
      file >> j;
      
      configArray[i] = j;
 
    }    

  }
 
}

char Plugboard::swapIO(char keyPressed) {

  int switchedKey;

  if(keyPressed >= 65 && keyPressed <= 90) {
   
    switchedKey = configArray[keyPressed-65];

  } else {
 
    throw std::invalid_argument("input error"); 

  } 

  if(switchedKey == 0) {

    return keyPressed;
  
  } 

  return (char)(switchedKey+65);

}
