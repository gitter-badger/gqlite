#include "StorageEngine.h"
using namespace mdbx;

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
    return 0;
}