#include "VirtualEngine.h"
#include <chrono>
#include <future>
#include "Platform.h"

GVirtualEngine::GVirtualEngine()
:_pStorageEngine(new GStorageEngine)
,_top(-1)
{
  _tInterpret = std::thread(&GVirtualEngine::execute, this);
}

GVirtualEngine::~GVirtualEngine()
{
  _tInterpret.join();
  delete _pStorageEngine;
}

void GVirtualEngine::addInstruction(const Instruction& instruction)
{
  _m.lock();
  this->_top += 1;
  this->_instructions[this->_top] = instruction;
  _m.unlock();
}

void GVirtualEngine::awaitExecute(Instruction& instruction)
{
  this->interpret(instruction);
}

void GVirtualEngine::execute()
{
  extern std::atomic<bool> _gqlite_g_close_flag_;
  do
  {
    debug((std::string("instruction: ") + std::to_string(this->_top)).c_str());
    _m.lock();
    while (this->_top >= 0) {
      Instruction& i = _instructions[this->_top];
      this->interpret(i);
      --this->_top;
    }
    _m.unlock();
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  } while (!_gqlite_g_close_flag_);
}

void GVirtualEngine::interpret(Instruction& i)
{
  switch (i._ops)
  {
  case OP_GraphDB:
    i._v1 = _pStorageEngine->create(i._v3.s);
    break;
  default:
    break;
  }
}
