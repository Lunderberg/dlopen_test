#ifndef _DYNAMICCALL_H_
#define _DYNAMICCALL_H_

#include <memory>
#include <string>

#include "DynamicLibrary.hh"
#include "ObjectPassed.hh"

class DynamicCall {
public:
  DynamicCall(std::string libname);

  DynamicCall(const DynamicCall&) = delete;
  DynamicCall(DynamicCall&&) = delete;
  DynamicCall operator=(const DynamicCall&) = delete;
  DynamicCall operator=(DynamicCall&&) = delete;

  void CallFunc();
  void Reload();

private:
  std::string libname;
  std::unique_ptr<DynamicLibrary> library;
  void(*func)(ObjectPassed&);
  time_t last_modified;
};

#endif /* _DYNAMICCALL_H_ */
