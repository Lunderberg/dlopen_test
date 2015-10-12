#include "Function.hh"

#include <iostream>

void func(ObjectPassed& obj) {
  std::cout << "----------------------" << std::endl;
  std::cout << obj.message << std::endl;
  std::cout << obj.value << std::endl;
#ifdef GOODBYE
  std::cout << "goodbye" << std::endl;
#else
  std::cout << "hello" << std::endl;
#endif
}
