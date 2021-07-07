#pragma once
#include "gqlite.h"
#include <mdbx.h++>
#include "Graph.h"
#include <map>

template<int Kind>
struct Link
{
    uint32_t _id;
    uint16_t _lcnt;      // link count
    uint32_t* _links;
    double _weight;
};

typedef Link<1> Vertex;
typedef Link<2> Edge;
typedef Link<3> Group;

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
    mdbx::env_managed _env;
    mdbx::txn _txn;
    std::map<std::string, mdbx::map_handle> _mHandle;
};