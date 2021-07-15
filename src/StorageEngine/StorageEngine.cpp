#include "StorageEngine.h"
#include "Error.h"

using namespace mdbx;

// data table
// vertex/edge

GStorageEngine::GStorageEngine() {

}

GStorageEngine::~GStorageEngine() {
    _env.close();
}

int GStorageEngine::create(const char* filename) {
    env::geometry db_geometry;
    env_managed::create_parameters create_param;
    create_param.geometry=db_geometry;

    env::operate_parameters operator_param;

    _env = env_managed(filename, create_param, operator_param);
    _txn = _env.start_write();
    return 0;
}

int GStorageEngine::openGraph(const char* name, GGraph*& pGraph) {
    auto ptr = _mHandle.find(name);
    if (ptr == _mHandle.end()) {
        mdbx::map_handle handle = _txn.create_map(name, mdbx::key_mode::ordinal, mdbx::value_mode::single);
        if (handle.dbi == 0) return ECode_DB_Create_Fail;
        pGraph = new GGraph();
        _mHandle[name] = pGraph;
    }
    return 0;
}

int GStorageEngine::closeGraph(GGraph* pGraph) {
    // if (pGraph == nullptr) return 0;
    _txn.commit();
    _env.close();
    return 0;
}