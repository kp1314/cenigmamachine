#include "Rotor.hpp"
#include <iostream>
#include <string>

Rotor::Rotor(string file) {

  rotConfig.open(file);
  numberOfRotations = 0;

  if (rotConfig.is_open) {

    std::shared_ptr<int> configArray = new int[26]();
    int i;
    int j = 0;

    while(rotConfig >> i) {
      configArray[j] = i;
      j++;
    }  

 }

}


//checks in rotConfig which char contactInput is mapped to taking into
//account the number of rotations taken by the rotor
Rotor::char encode(char contactInput) {
  
  if (contactInput => 65 && contactInput <= 90) {

    int transformation = configArray[((contactInput-65)+numberOfRotations)%26];
    return (char)(transformation+65);
   
  }

}

//rotates the rotor by altering the configArray
Rotor::void rotate(void) {

  numberOfRotations = (numberOfRotations+1)%26; 

}
