#include "Rotor.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

Rotor::Rotor() {

  numberOfRotations = 0;
  
}

void Rotor::configureRotor(std::ifstream& file) { 

  if (file) {
 
    int i;
    int j = 1;

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
char Rotor::encode(char contactInput) {
  int asciiValue = contactInput; 
  if (asciiValue >= 65 && asciiValue <= 90) {

    int transformation = configArray[((asciiValue-65)+numberOfRotations)%26];
    return (char)(transformation+65);
   
  }

  exit(107);

}

//rotates the rotor by altering the configArray
void Rotor::rotate(void) {

  numberOfRotations = (numberOfRotations+1)%26; 

}
