#include "Reflector.hpp"
#include <string>

Reflector::Reflector() {

}

void Reflector::reflect(char& keyPressed) {
  
    int transformation = (((keyPressed-65)+13)%26) + 65;
    keyPressed = transformation;
}
