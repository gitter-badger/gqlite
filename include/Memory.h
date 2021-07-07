#pragma once

class GMemory {
public:
  static void* Malloc(long len);
  static void Free(void* ptr);
  
private:
  GMemory();
  ~GMemory();

private:
  void* _cache = nullptr;
  long* _stack = nullptr;
  long _top_index = 0;
};
