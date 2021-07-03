#pragma once
#include "VirtualEngine.h"
#include "gqlite.h"

class GQueryEngine;
class GStorageEngine;

class GQLiteImpl {
public:
    GQLiteImpl();
    ~GQLiteImpl();

    int open(const char* filename, gqlite_open_mode mode);

private:
  int create(const char* filename, gqlite_open_mode mode);

private:
  GQueryEngine* _pQueryEngine = nullptr;
  GStorageEngine* _pStorageEngine = nullptr;
  GVirtualEngine* _pVirtualEngine = nullptr;
};