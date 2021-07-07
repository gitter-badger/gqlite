#pragma once
#include <stdint.h>

class GProgram {
public:
  static uint32_t GenerateIndex();

  GProgram();

private:
  static uint32_t _indx;
};