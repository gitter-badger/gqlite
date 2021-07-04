#include "Memory.h"
#include <memory>
#include <mutex>
#define MAX_MEMORY_SIZE   16*1024
#define MAX_STACK_SIZE    128

namespace {
  static std::once_flag of;
  GMemory* _gqlite_memory = nullptr;
}

void* GMemory::Malloc(size_t len)
{
  std::call_once(of, []() {
    if (!_gqlite_memory) {
      _gqlite_memory = new GMemory();
    }
    });
  long offset = _gqlite_memory->_stack[_gqlite_memory->_top_index] + (long)len;
  if (offset >= MAX_MEMORY_SIZE) return nullptr;
  long current = _gqlite_memory->_stack[_gqlite_memory->_top_index];
  _gqlite_memory->_stack[_gqlite_memory->_top_index] = offset;
  ++_gqlite_memory->_top_index;
  return (char*)_gqlite_memory->_cache + current;
}

void GMemory::Free(void* ptr)
{

}

GMemory::GMemory()
{
  _cache = malloc(MAX_MEMORY_SIZE);
  _stack = (long*)malloc(sizeof(long) * MAX_STACK_SIZE);
}

GMemory::~GMemory()
{
  free(_cache);
  free(_stack);
}
