#pragma once
#include "QueryEngine.h"
#include "StorageEngine.h"
#include <thread>
#include <mutex>

#define PROGRAM_Start   1
#define PROGRAM_Finish  2

// this is 
enum OPS{
    // control
    OP_Goto,
    OP_Compare,
    OP_Add,
    OP_Call,
    OP_Program,
    OP_Return,
    OP_Halt,
    // graph operation
    OP_GraphDB,      // OP_GraphDB, return, NULL, path:    create or delete db with path
    OP_Graph,        // OP_Graph, return, 1/2, name: create or delete a graph
    OP_Trans,       
    OP_Set,
    OP_Get,
    OP_Del,
};

enum PTR_TYPE {
  PTR_Int,
  PTR_Normal,
  PTR_Str,
  PTR_REAL,
};
struct Instruction {
  OPS _ops;
  uint32_t _indx;
  int32_t _v1;
  uint32_t _v2;
  union v3union{
    int32_t i;
    void* p;
    char* s;
    double* r;
  } _v3;
  PTR_TYPE _v3type;
};

class GVirtualEngine{
public:
  GVirtualEngine();
  ~GVirtualEngine();

  void addInstruction(const Instruction& instruction);
  void awaitExecute(Instruction& instruction);

private:
  void execute();
  void interpret(Instruction& i);

private:
  Instruction _instructions[512];
  int _top;
  std::thread _tInterpret;
  std::mutex _m;
  GStorageEngine* _pStorageEngine;
};