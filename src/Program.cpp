#include "Program.h"

uint32_t GProgram::_indx = 0;

uint32_t GProgram::GenerateIndex()
{
  return ++GProgram::_indx;
}
