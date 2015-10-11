#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include "DynamicCall.hh"

int main() {
  DynamicCall lib("lib/libDynamic.so");
  while(true){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    lib.Reload();
    lib.CallFunc();
  }
}
