#include "VirtualEngine.h"
#include <chrono>
#include <future>
#include "Platform.h"

GVirtualEngine::GVirtualEngine()
:_pStorageEngine(new GStorageEngine)
{
  _tInterpret = std::thread(&GVirtualEngine::interpret, this);
}

GVirtualEngine::~GVirtualEngine()
{
  _tInterpret.join();
  delete _pStorageEngine;
}

void GVirtualEngine::addInstruction(const Instruction& instruction)
{
  _m.lock();
  this->_instructions.emplace(instruction);
  _m.unlock();
}

void GVirtualEngine::interpret()
{
  extern std::atomic<bool> _gqlite_g_close_flag_;
  do
  {
    debug((std::string("instruction: ") + std::to_string(_instructions.size())).c_str());
    _m.lock();
    while (_instructions.size()) {
      Instruction i = _instructions.top();
      _instructions.pop();
    }
    _m.unlock();
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  } while (!_gqlite_g_close_flag_);
}
