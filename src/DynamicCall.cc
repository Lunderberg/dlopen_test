#include "DynamicCall.hh"

#include <fstream>

#include <sys/stat.h>

#include "DynamicExceptions.hh"

typedef void* __attribute__((__may_alias__)) void_alias;

DynamicCall::DynamicCall(std::string libname)
  : libname(libname), library(nullptr) {
  Reload();
}

void DynamicCall::CallFunc() {
  func();
}

namespace {
  bool file_exists(const std::string& filename) {
    return std::ifstream(filename);
  }
}

void DynamicCall::Reload() {
  if(file_exists(libname)){
    struct stat buf;
    stat(libname.c_str(), &buf);
    if(buf.st_mtime > last_modified){
        library = std::unique_ptr<DynamicLibrary>(new DynamicLibrary(libname.c_str(), true));
        *(void_alias*)(&func) = library->GetSymbol("func");
        last_modified = buf.st_mtime;
    }
  }
}
