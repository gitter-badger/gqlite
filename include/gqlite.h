#pragma once
#include <stdint.h>

#ifdef _WIN32
#define SYMBOL_EXPORT
#else
#define SYMBOL_EXPORT __attribute__((visibility("default")))
#endif

typedef void* gqlite;

enum gqlite_increase_mode {
    gm_random,
    /**
     * gm_unscale use BA model to extend data
     */
    gm_unscale,
};

typedef uint32_t (*gqlite_distance)(uint32_t pt1, uint32_t pt2);

typedef struct _gqlite_model {
    gqlite_increase_mode mode;
    gqlite_distance fdist;
} gqlite_model;

typedef struct _gqlite_statement {

}gqlite_statement;

enum gqlite_storage_schema {
  gqlite_disk,
  gqlite_memory,
};
typedef struct _gqlite_open_mode {
  gqlite_storage_schema st_schema;
}gqlite_open_mode;

#ifdef __cplusplus
extern "C" {
#endif

  SYMBOL_EXPORT int gqlite_open(const char* filename, gqlite** ppDb);
  SYMBOL_EXPORT int gqlite_open_with_mode(const char* filename, gqlite** ppDb, gqlite_open_mode mode);
SYMBOL_EXPORT int gqlite_create(gqlite* pDb, const char* gql);
SYMBOL_EXPORT void gqlite_insert(gqlite* pDb, const char* gql);
SYMBOL_EXPORT void gqlite_update(gqlite* pDb, const char* gql);
SYMBOL_EXPORT void gqlite_drop(gqlite* pDb, const char* gql);
SYMBOL_EXPORT void gqlite_query(gqlite* pDb, const char* gql, gqlite_statement statement);
SYMBOL_EXPORT int gqlite_close(gqlite*);
SYMBOL_EXPORT const char* gqlite_error(int error);

#ifdef __cplusplus
}
#endif
