#include "GQliteImpl.h"
#include "ParserEngine.h"
#include "Platform.h"
#include "Program.h"
#include "Error.h"

GQLiteImpl::GQLiteImpl()
  :_pParserEngine(new GParserEngine)
  , _pVirtualEngine(new GVirtualEngine)
{}

GQLiteImpl::~GQLiteImpl()
{
  delete _pParserEngine;
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
  size_t len = strlen(filename);
  GQL_DEBUG("111222");
  char* str = (char*)malloc(sizeof(char) * len);
  if (!str) {
    return ECode_No_Memory;
  }
  GQL_DEBUG("11111");
  Instruction i;
  i._indx = GProgram::GenerateIndex();
  _pVirtualEngine->addInstruction(i);
  i._ops = OP_GraphDB;
  i._v3type = PTR_Str;
  memcpy(str, filename, len);
  i._v3.s = str;
  _pVirtualEngine->awaitExecute(i);
  return ECode_Success;
}

int GQLiteImpl::exec(const char* gql)
{
  return ECode_Success;
}