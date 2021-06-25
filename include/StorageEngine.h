#pragma once
#include "gqlite.h"
#include <mdbx.h++>

class GStorageEngine {
public:
    GStorageEngine();
    ~GStorageEngine();

    int create(const char* filename);

    int openGraph();

    int closeGraph();

    int startTrans();

    int commitTrans();

    int rollbackTrans();

    /**
     * @brief add node
     */
    int addNode();

    int group();

    int addRelationship();

    int updateNode();

    int updateRelationship();

    int dropNode();

    int dropRelationship();

    /*
     *
     */
    int startNode();

    int forward();

    int backward();

    int registCostFunc();

private:
    mdbx::env_managed _env;
};