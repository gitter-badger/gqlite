#include "gqlite.h"
#include "GQliteImpl.h"
#include <atomic>

std::atomic<bool> _gqlite_g_close_flag_ = false;

SYMBOL_EXPORT int gqlite_open_with_mode(const char* filename, gqlite** ppDb, gqlite_open_mode mode)
{
  GQLiteImpl* impl = new GQLiteImpl();
  *ppDb = (gqlite*)impl;
  return impl->open(filename, mode);
}

SYMBOL_EXPORT int gqlite_open(const char* filename, gqlite** ppDb)
{
  gqlite_open_mode mode;
  mode.st_schema = gqlite_disk;
  return gqlite_open_with_mode(filename, ppDb, mode);
}

SYMBOL_EXPORT int gqlite_close(gqlite*)
{
  _gqlite_g_close_flag_.store(true);
  return 0;
}

SYMBOL_EXPORT int gqlite_create(gqlite* pDb, const char* gql)
{
  return 0;
}