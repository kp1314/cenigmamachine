#include "Reflector.hpp"

void Reflector::encode(char& keyPressed) {
  
    int transformation = (((keyPressed-A_ASCII)+(ALPHA_LENGTH/2))%
         ALPHA_LENGTH) + A_ASCII;
    keyPressed = transformation;
}

