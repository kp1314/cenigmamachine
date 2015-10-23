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

        int transformation = (configArray[((keyPressed-65)+numberOfRotations)%26]
                              - numberOfRotations)%26;
        //in case of negative mod
        if (transformation < 0) {
          transformation += 26;
        }
        
        //transform key pressed
        keyPressed = ((transformation)%26)+65;
      
      } else {      //going through the rotors

        for (int i = 0; i < 26; i++) {
       
        int transformation = ((keyPressed-65)+numberOfRotations)%26;
           
          if (configArray[i] == transformation) {
            
            //incase of negative mod
            if (i < numberOfRotations) {
              i += 26;
            }
            

            keyPressed = ((i-numberOfRotations)%26)+65;
            break;
          }
        }
      }

    } else {
      
      throw std::invalid_argument("input error to Rotor");    

    }
}

void Rotor::setOppositeConfiguration(bool b) {
  isOppositeConfiguration = b; 
}

void Rotor::rotate(void) {
  numberOfRotations = (numberOfRotations+1)%26;
}
