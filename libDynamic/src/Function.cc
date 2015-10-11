#include "Function.hh"

#include <iostream>

void func() {
#ifdef GOODBYE
  std::cout << "\rgoodbye      " << std::flush;
#else
  std::cout << "\rhello      " << std::flush;
#endif
}
