#include "StorageEngine.h"

GStorageEngine::GStorageEngine(const char* filename) {
    using namespace mdbx;
    env::geometry db_geometry;
    env_managed::create_parameters create_param;
    create_param.geometry=db_geometry;

    env::operate_parameters operator_param;

    env_managed em(filename, create_param, operator_param);
}