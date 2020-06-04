
#include "cpu6510.h"

Cpu6510::Accumulator(void (instr*)(uint8_t)) {

  uint8_t a = GetA();
  a = instr(a);

  SetA(a);

  return 2;
}


Cpu6510::XReg(void (instr*)(uint8_t)) {

  uint8_t x = GetX();
  x = instr(x);

  SetX(x);

  return 2;
}


Cpu6510::YReg(void (instr*)(uint8_t)) {

  uint8_t y = GetY();
  y = instr(y);

  SetY(y);

  return 2;
}


Cpu6510::ImmediateRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 1);

  uint8_t arg = ReadByte(pc);

  instr(arg);

  return 2;
}


Cpu6510::ZeroPageRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 1);

  uint8_t addr = ReadByte(pc);
  uint8_t arg = ReadByte(addr);

  instr(arg);

  return 3;
}


Cpu6510::ZeroPageReadWrite(uint8_t (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 1);

  uint8_t addr = ReadByte(pc);
  uint8_t arg = ReadByte(arg);

  uint8_t res = instr(arg);

  WriteByte(addr, res);

  return 5;
}


Cpu6510::ZeroPageXRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 1);

  uint8_t addr = ReadByte(pc) + GetX();
  uint8_t arg = ReadByte(addr);

  instr(arg);

  return 4;
}


Cpu6510::ZeroPageYRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 1);

  uint8_t addr = ReadByte(pc) + GetY();
  uint8_t arg = ReadByte(addr);

  instr(arg);

  return 4;
}


Cpu6510::IndirectXRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 1);

  uint8_t zpaddr = ReadByte(pc) + GetX();
  uint16_t addr = ReadWord(zpaddr);
  uint8_t arg = ReadByte(addr);

  instr(arg);

  return 6;
}


Cpu6510::IndirectYRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 1);

  uint8_t offset = GetY();
  uint8_t zpaddr = ReadByte(pc);
  uint16_t base = ReadWord(zpaddr);
  uint16_t addr = base + offset;
  uint8_t arg = ReadByte(addr);

  instr(arg);

  if ((base & 0xFF) < (base & 0xFF) && (base & 0xFF) < offset)
    return 6;

  return 5;
}


Cpu6510::AbsoluteRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 2);

  uint16_t addr = ReadWord(pc);
  uint8_t arg = ReadByte(addr);

  instr(arg);

  return 4;
}


Cpu6510::AbsoluteXRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 2);

  uint8_t offset = GetX();
  uint16_t base = ReadWord(pc);
  uint16_t addr = base + offset;
  uint8_t arg = ReadByte(addr);

  instr(arg);

  if ((addr & 0xFF) < (base & 0xFF) && (addr & 0xFF) < offset)
    return 5;

  return 4;
}


Cpu6510::AbsoluteYRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 2);

  uint8_t offset = GetY();
  uint16_t base = ReadWord(pc);
  uint16_t addr = ReadWord(pc);
  uint8_t arg = ReadByte(addr);

  instr(arg);

  if ((addr & 0xFF) < (base & 0xFF) &&
      (addr & 0xFF) < offset)
    return 5;

  return 4;
}

