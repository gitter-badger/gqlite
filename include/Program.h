#pragma once
#include <stdint.h>

class GProgram {
public:
  static uint32_t GenerateIndex();

private:
  static uint32_t _indx;
};