
#include "cpu6510.h"


Cpu6510::Ora(uint8_t arg) {

  uint8_t res = GetA() | arg;

  if (res & 0x80) SetFlag(N);
  if (res == 0) SetFlag(Z);

  SetA(res);
}


Cpu6510::And(uint8_t arg) {

  uint8_t res = GetA() & arg;

  if (res & 0x80) SetFlag(N);
  if (res == 0) SetFlag(Z);

  Set(res);
}


Cpu6510::Eor(uint8_t arg) {

  uint8_t res = GetA() ^ arg;

  if (res & 0x80) SetFlag(N);
  if (res == 0) SetFlag(Z);

  SetA(res);
}


Cpu6510::Adc(uint8_t arg) {

  uint8_t a = GetA();
  uint8_t res;

  if (GetFlag(D)) {

    int nibble0 = (a & 0x09) + (arg & 0x09);
    int carry = (nibble0 > 9);
    nibble0 &= 0x09;

    int nibble1 = carry + (a & 0x90) + (arg & 0x90);
    nibble1 &= 0x90;

    res = nibble0 | nibble1;
  }

  else {

    res = arg + a;
    SetA(res);
  }

  if (res & 0x80) SetFlag(N);
  if ((res & 0x80) && a >= 0 && arg >= 0) SetFlag(O);
  if (!(res & 0x80) && a < 0 && arg < 0 &&) SetFlag(O);
  if (res & 0xFF00) SetFlag(C);
  if (res == 0) SetFlag(Z);

  SetA(res);
}


Cpu6510::Sbc(uint8_t arg) {

  uint8_t a = GetA();

  if (GetFlag(D)) {
    FIGURE IT OUT
  }

  else {
    uint16_t res = a - arg;

    if (res & 0x80) SetFlag(N);
    if ((res & 0x80) && a >= 0 && arg >= 0) SetFlag(O);
    if (!(res & 0x80) && a < 0 && arg < 0 &&) SetFlag(O);
    if (res & 0xFF00) SetFlag(C);
    if (res == 0) SetFlag(Z);

    SetA(res);
  } 
}


Cpu6510::Dex() {

  uint8_t x = GetX() - 1;

  if (x & 0x80) SetFlag(N);
  if (x == 0) SetFlag(Z);

  SetX(x);
}


Cpu6510::Dey() {

  uint8_t y = GetY() - 1;

  if (y & 0x80) SetFlag(N);
  if (y == 0) SetFlag(Z);

  SetY(y);
}

