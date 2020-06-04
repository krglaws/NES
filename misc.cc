
#include "cpu6510.h"


Cpu6510::WriteByte(uint16_t addr, uint8_t byte) {

  mem_[addr] = byte;
}


Cpu6510::ReadByte(uint16_t addr) {

  return mem_[addr];
}


Cpu6510::ReadWord(uint16_t addr) {

  uint16_t data = mem_[addr] << 8;
  data |= mem_[addr + 1];

  return data;
}


Cpu6510::GetFlag(Flag flag) {

  return p_ & flag;
}


Cpu6510::SetFlag(Flag flag) {

  p_ |= flag;
}


Cpu6510::UnsetFlag(Flag flag) {

  p_ ^= flag;
}

