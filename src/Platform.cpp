#include "Platform.h"
#include <sys/stat.h>
#include <errno.h>
#include <iostream>
#ifdef _WIN32
#else
#endif

bool isFileExist(const char* file)
{
  struct _stat buf;
  int result = _stat(file, &buf);
  if (result != 0) {
    if (errno == ENOENT) return false;
  }
  return true;
}

void debug(const char* info)
{
  std::cout << info << std::endl;
}
