#pragma once
#include "GQLlite.h"
#include <mdbx.h++>

class GStorageEngine {
public:
    GStorageEngine(const char* filename);

    /**
     * @brief add node
     */
    int addNode();

    int addRelationship();

    int updateNode();

    int updateRelationship();

    int dropNode();

    int dropRelationship();

private:
    
};