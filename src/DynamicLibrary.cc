#include "DynamicLibrary.hh"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

#include <dlfcn.h>
#include <unistd.h>

#include "DynamicExceptions.hh"
#include "FullPath.hh"

DynamicLibrary::DynamicLibrary(std::string libname, bool unique_name) {
  if(unique_name){
    std::string tempname = std::tmpnam(NULL);
    int error = symlink(full_path(libname).c_str(), tempname.c_str());
    if(error){
      throw DynamicSymlinkCreation("Could not make temp symlink");
    }
    library = dlopen(tempname.c_str(), RTLD_NOW);
    unlink(tempname.c_str());
  } else {
    library = dlopen(libname.c_str(), RTLD_NOW);
  }

  if(!library){
    std::stringstream ss;
    ss << "DynamicFileNotFound: " << libname;
    throw DynamicFileNotFound(ss.str());
  }
}

DynamicLibrary::~DynamicLibrary() {
  if(library) {
    dlclose(library);
  }
}

DynamicLibrary::DynamicLibrary(DynamicLibrary&& other)
  : library(NULL){
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
