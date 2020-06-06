
#include "RP2A03.h"


RP2A03::Ora(uint8_t arg) {

  uint8_t res = GetA() | arg;

  if (res & 0x80) SetFlag(N);
  if (res == 0) SetFlag(Z);

  SetA(res);
}


RP2A03::And(uint8_t arg) {

  uint8_t res = GetA() & arg;

  if (res & 0x80) SetFlag(N);
  if (res == 0) SetFlag(Z);

  Set(res);
}


RP2A03::Eor(uint8_t arg) {

  uint8_t res = GetA() ^ arg;

  if (res & 0x80) SetFlag(N);
  if (res == 0) SetFlag(Z);

  SetA(res);
}


RP2A03::Adc(uint8_t arg) {

  uint8_t a = GetA();
  uint16_t res = a + arg;

  if (res & 0x80) SetFlag(N);
  if ((res & 0x80) && a >= 0 && arg >= 0) SetFlag(O);
  if (!(res & 0x80) && a < 0 && arg < 0 &&) SetFlag(O);
  if (res & 0xFF00) SetFlag(C);
  if (res == 0) SetFlag(Z);

  SetA((uint8_t) res);
}


RP2A03::Sbc(uint8_t arg) {

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


RP2A03::Dex() {

  uint8_t x = GetX() - 1;

  if (x & 0x80) SetFlag(N);
  if (x == 0) SetFlag(Z);

  SetX(x);
}


RP2A03::Dey() {

  uint8_t y = GetY() - 1;

  if (y & 0x80) SetFlag(N);
  if (y == 0) SetFlag(Z);

  SetY(y);
}

