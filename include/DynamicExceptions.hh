#ifndef _DYNAMICEXCEPTIONS_H_
#define _DYNAMICEXCEPTIONS_H_

#include <stdexcept>

struct DynamicException : public std::runtime_error {
  DynamicException(const std::string& msg) : std::runtime_error(msg) { }
};

struct DynamicFileNotFound : public DynamicException {
  DynamicFileNotFound(const std::string& msg) : DynamicException(msg) { }
};

struct DynamicSymbolNotFound : public DynamicException {
  DynamicSymbolNotFound(const std::string& msg) : DynamicException(msg) { }
};

struct DynamicSymlinkCreation : public DynamicException {
  DynamicSymlinkCreation(const std::string& msg) : DynamicException(msg) { }
};

#endif /* _DYNAMICEXCEPTIONS_H_ */
