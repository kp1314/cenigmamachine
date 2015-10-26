#include <stdexcept> 
#include <iostream>
#include <string>
#include <vector>
#include "Encoder.hpp"
#include "Rotor.hpp"

Rotor::Rotor(std::ifstream& configFile) {
  
  isOppositeConfiguration = false;
  numberOfRotations = 0;

  if (configFile) {
 
    int i = 0;
    int j = 0;
        
    while(configFile >> i) {
      
      configArray[j] = i;
      j++;

    }  

  } else {
    
    throw std::invalid_argument("Rotor configuration error");
 
  }
}

//checks in rotConfig which char contactInput is mapped to taking into
//account the number of rotations taken by the rotor
void Rotor::encode(char& keyPressed) {
  
    if (keyPressed >= A_ASCII && keyPressed <= Z_ASCII) {

      if (!isOppositeConfiguration) { // go through rotors forwards

        int transformation = (configArray[((keyPressed-A_ASCII)+
            numberOfRotations)%ALPHA_LENGTH] 
                - numberOfRotations)%ALPHA_LENGTH;
        
        //in case of negative mod
        if (transformation < 0) {
          transformation += ALPHA_LENGTH;
        }
        
        //transform key pressed
        keyPressed = ((transformation)%ALPHA_LENGTH)+A_ASCII;
      
      } else {      //going through the rotors backwards

        for (int i = 0; i < ALPHA_LENGTH; i++) {
       
          int transformation = ((keyPressed-A_ASCII)
              +numberOfRotations)%ALPHA_LENGTH;
           
          if (configArray[i] == transformation) {
            
            //incase of negative mod
            if (i < numberOfRotations) {
              i += ALPHA_LENGTH;
            }
            
            keyPressed = ((i-numberOfRotations)%ALPHA_LENGTH)
                +A_ASCII;
            break;
          }
        }
      }

    } else {
 
      throw std::invalid_argument("Rotor input error");    

    }
}

//tell rotor we want to read it backwards
void Rotor::setOppositeConfiguration(bool b) {
  isOppositeConfiguration = b; 
}

//rotate the rotor
void Rotor::rotate(void) {
  numberOfRotations = (numberOfRotations+1)%ALPHA_LENGTH;
}
