#pragma once
#include <stdint.h>

struct gqlite;

enum gqlite_increase_mode {
    gm_random,
    gm_unscale,
};

typedef uint32_t (*gqlite_distance)(uint32_t pt1, uint32_t pt2);

typedef struct _gqlite_model {
    gqlite_increase_mode mode;
    gqlite_distance fdist;
} gqlite_model;

int gqlite_open(const char* filename, gqlite** ppDb, gqlite_model mode);
int gqlite_create(gqlite* pDb, const char* gql);
void gqlite_insert(gqlite* pDb);
void gqlite_update(gqlite* pDb);
void gqlite_drop(gqlite* pDb);
void gqlite_query(gqlite* pDb);
int gqlite_close(gqlite*);