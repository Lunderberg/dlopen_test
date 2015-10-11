#include "DynamicLibrary.hh"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include <dlfcn.h>

#include "DynamicExceptions.hh"

DynamicLibrary::DynamicLibrary(const char* libname) {
  library = dlopen(libname, RTLD_NOW);
  if(!library){
    std::stringstream ss;
    ss << "DynamicFileNotFound: " << libname;
    throw DynamicFileNotFound(ss.str());
  }
}

DynamicLibrary::~DynamicLibrary() {
  dlclose(library);
}

DynamicLibrary::DynamicLibrary(DynamicLibrary&& other){
  swap(other);
}

DynamicLibrary& DynamicLibrary::operator=(DynamicLibrary&& other){
  swap(other);
  return *this;
}

void DynamicLibrary::swap(DynamicLibrary& other){
  std::swap(library, other.library);
}

void* DynamicLibrary::GetSymbol(const char* symbol) {
  void* output = dlsym(library, symbol);
  if(!output){
    std::stringstream ss;
    ss << "DynamicSymbolNotFound: " << symbol;
    throw DynamicSymbolNotFound(ss.str());
  }
  return output;
}
