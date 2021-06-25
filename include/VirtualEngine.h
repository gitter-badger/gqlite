#pragma once
#include "QueryEngine.h"
#include "StorageEngine.h"

// this is 
enum OPS{
    // control
    OP_Goto,
    OP_Compare,
    OP_Add,
    OP_Call,
    // graph operation
    OP_GraphDB,      // OP_GraphDB, 1/2, NULL, path:    create or delete db with path
    OP_OpenGraph,    // 
    OP_CloseGraph,
    OP_Trans,       
    OP_Set,
    OP_Get,
    OP_Del,
};

class GVirtualEngine{
public:
    GVirtualEngine();

private:

};