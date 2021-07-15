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

  int exec(const char* gql);
  
private:
  int create(const char* filename, gqlite_open_mode mode);

private:
  GParserEngine* _pParserEngine = nullptr;
  GStorageEngine* _pStorageEngine = nullptr;
  GVirtualEngine* _pVirtualEngine = nullptr;
};