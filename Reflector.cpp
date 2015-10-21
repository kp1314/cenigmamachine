#include "Reflector.hpp"

Reflector::Reflector() {

}

char Reflector::reflect(char inputContact) {

  return (inputContact+13)%26;

}
