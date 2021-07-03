#include "GQliteImpl.h"
#include "QueryEngine.h"
#include "Platform.h"
#include "Program.h"
#include "Error.h"

GQLiteImpl::GQLiteImpl()
  :_pQueryEngine(new GQueryEngine)
  , _pVirtualEngine(new GVirtualEngine)
{}

GQLiteImpl::~GQLiteImpl()
{
  delete _pQueryEngine;
  delete _pVirtualEngine;
}

int GQLiteImpl::open(const char* filename, gqlite_open_mode mode)
{
  if (!isFileExist(filename)) {
    create(filename, mode);
  }
  return 0;
}

int GQLiteImpl::create(const char* filename, gqlite_open_mode mode)
{
  Instruction i;
  i._ops = OP_GraphDB;
  i._v3type = PTR_Str;
  size_t len = strlen(filename);
  i._v3.s = (char*)malloc(sizeof(char) * len);
  if (!i._v3.s) {
    return ECode_No_Memory;
  }
  i._indx = GProgram::GenerateIndex();
  i._ops = OP_Program;
  i._v1 = PROGRAM_Start;
  _pVirtualEngine->addInstruction(i);
  memcpy(i._v3.s, filename, len);
  _pVirtualEngine->addInstruction(i);
  i._ops = OP_Return;
  _pVirtualEngine->addInstruction(i);
  i._ops = OP_Program;
  i._v1 = PROGRAM_Finish;
  _pVirtualEngine->addInstruction(i);
  return ECode_Success;
}
