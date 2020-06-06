
#include "RP2A03.h"


RP2A03::WriteByte(uint16_t addr, uint8_t byte) {

  mem_[addr] = byte;
}


RP2A03::ReadByte(uint16_t addr) {

  return mem_[addr];
}


RP2A03::ReadWord(uint16_t addr) {

  uint16_t data = mem_[addr] << 8;
  data |= mem_[addr + 1];

  return data;
}


RP2A03::GetFlag(Flag flag) {

  return p_ & flag;
}


RP2A03::SetFlag(Flag flag) {

  p_ |= flag;
}


RP2A03::UnsetFlag(Flag flag) {

  p_ ^= flag;
}

