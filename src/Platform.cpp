#include "Platform.h"
#include <sys/stat.h>
#include <errno.h>
#include <iostream>
#ifdef _WIN32
#else
#endif

bool isFileExist(const char* file)
{
#ifdef _WIN32
  struct _stat buf;
  int result = _stat(file, &buf);
  if (result != 0) {
    if (errno == ENOENT) return false;
  }
#else
  struct stat buf;
  int result = stat(file, &buf);
  if (result != 0) return false;
#endif
  return true;
}

void debug(const char* info)
{
  std::cout << info << std::endl;
}
