#ifndef _DYNAMICEXCEPTIONS_H_
#define _DYNAMICEXCEPTIONS_H_

#include <stdexcept>

struct DynamicException : public std::runtime_error {
  using std::runtime_error::runtime_error;
};

struct DynamicFileNotFound : public DynamicException {
  using DynamicException::DynamicException;
};

struct DynamicSymbolNotFound : public DynamicException {
  using DynamicException::DynamicException;
};

struct DynamicSymlinkCreation : public DynamicException {
  using DynamicException::DynamicException;
};

#endif /* _DYNAMICEXCEPTIONS_H_ */
