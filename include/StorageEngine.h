#pragma once
#include "gqlite.h"
#include <mdbx.h++>
#include "Graph.h"
#include <map>

class GStorageEngine {
public:
    GStorageEngine();
    ~GStorageEngine();

    int create(const char* filename);

    int openGraph(const char* name, GGraph*& pGraph);

    int closeGraph(GGraph* pGraph);

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
    /*
     * @brief schema is used to record all the graph's name
     */
    void schema();
private:
    mdbx::env_managed _env;
    mdbx::txn _txn;
    std::map<std::string, GGraph*> _mHandle;
};