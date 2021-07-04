#pragma once

class GMemory {
public:
  static void* Malloc(size_t len);
  static void Free(void* ptr);
  
private:
  GMemory();
  ~GMemory();

private:
  void* _cache = nullptr;
  long* _stack = nullptr;
  size_t _top_index = 0;
};
