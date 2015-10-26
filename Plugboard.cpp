#include <stdexcept>
#include <iostream>
#include <string>
#include "Plugboard.hpp"

Plugboard::Plugboard(std::ifstream& configFile) {
  
  if(configFile) {
   
    int i = 0;
    
    while(configFile >> i) {
      
      int j = 0;
      configFile >> j;

      configArray[i] = j;
      configArray[j] = i;
 
    }    

  } else {
 
    throw std::invalid_argument("Plugboard configuration error");
  }
}

void Plugboard::encode(char& keyPressed) {

  int switchedKey = 0;
  
  if(keyPressed >= A_ASCII && keyPressed <= Z_ASCII) {
   
    switchedKey = configArray[keyPressed-A_ASCII];

    //all entries of vector are initialized to -1
    //if negative it means character isn't affected 
    //by the plugboard
    if(switchedKey >= 0) {
      keyPressed = switchedKey + A_ASCII;
    }

  } else {
 
    throw std::invalid_argument("Plugboard input error"); 
  } 
}
