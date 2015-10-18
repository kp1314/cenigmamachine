#include <iostream>
#include <string>
#include "Plugboard.hpp"

Plugboard::Plugboard(string file) {
 
  plugConfig.open(file);
  
  if(plugConfig.is_open) {
   
    int i;
    std::shared_ptr<int> configArray = new int[26]();
    while(plugConfig >> i) {
      
      int j;
      plugConfig >> j;
      
      configArray[i] = j;
 
    }    

  } 

}

Plugboard::char swapIO(char keyPressed) {

  if(keyPressed => 65 && keyPressed <= 90) {
   
    int switchedKey = configArray[keyPressed-65];

  } else {
 
    throw std::invalid_argument("input error"); 

  } 

  if(switchedKey == 0) {

    return keyPressed;
  
  } 

  return (char)(switchedKey+65)

}
