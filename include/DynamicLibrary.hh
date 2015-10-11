#ifndef _DYNAMICLIBRARY_H_
#define _DYNAMICLIBRARY_H_

#include <string>

class DynamicLibrary {
public:
  DynamicLibrary(const char* libname);
  ~DynamicLibrary();
  DynamicLibrary(DynamicLibrary&& other);
  DynamicLibrary& operator=(DynamicLibrary&& other);

  DynamicLibrary(const DynamicLibrary&) = delete;
  DynamicLibrary& operator=(const DynamicLibrary&) = delete;

  void* GetSymbol(const char* symbol);

private:
  void swap(DynamicLibrary& other);

  void* library;
};

#endif /* _DYNAMICLIBRARY_H_ */
