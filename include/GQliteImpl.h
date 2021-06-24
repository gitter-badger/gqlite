#pragma once
#include "VirtualEngine.h"

class GQueryEngine;
class GStorageEngine;

class GQLiteImpl {
public:
    GQLiteImpl();
    ~GQLiteImpl();

private:
    GQueryEngine* _pQueryEngine;
    GStorageEngine* _pStorageEngine;
};