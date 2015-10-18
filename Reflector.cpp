#include "Reflector.hpp"

Reflector::char reflect(char inputContact) {

  return (inputContact+13)%26;

}
