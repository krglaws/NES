
#include <RP2A03.h>


RP2A03::Fetch() {

  uint16_t pc = GetPc();
  uint8_t opcode = ReadB(pc);

  SetDb(opcode);
  SetPc(pc + 1);
}


RP2A03::Decode() {

  uint8_t opcode = GetDb();

  switch (opcode) {

  /* ------------------
   * LOGIC + ARITHMETIC
   */

    /* ORA */
    case 0x09: return ImmediateRead(&Ora);
    case 0x05: return ZeroPageRead(&Ora);
    case 0x15: return ZeroPageXRead(&Ora);
    case 0x01: return IndirectXRead(&Ora);
    case 0x11: return IndirectYRead(&Ora);
    case 0x0D: return AbsoluteRead(&Ora);
    case 0x1D: return AbsoluteXRead(&Ora);
    case 0x19: return AbsoluteYRead(&Ora);
 
    /* AND */
    case 0x29: return ImmediateRead(&And);
    case 0x25: return ZeroPageRead(&And);
    case 0x35: return ZeroPageXRead(&And);
    case 0x21: return IndirectXRead(&And);
    case 0x31: return IndirectYRead(&And);
    case 0x2D: return AbsoluteRead(&And);
    case 0x3D: return AbsoluteXRead(&And);
    case 0x39: return AbsoluteYRead(&And);

    /* EOR */
    case 0x49: return ImmediateRead(&Eor);
    case 0x45: return ZeroPageRead(&Eor);
    case 0x55: return ZeroPageXRead(&Eor);
    case 0x41: return IndirectXRead(&Eor);
    case 0x51: return IndirectYRead(&Eor);
    case 0x4D: return AbsoluteRead(&Eor);
    case 0x5D: return AbsoluteXRead(&Eor);
    case 0x59: return AbsoluteYRead(&Eor);

    /* ADC */
    case 0x69: return ImmediateRead(&Adc);
    case 0x65: return ZeroPageRead(&Adc);
    case 0x75: return ZeroPageXRead(&Adc);
    case 0x61: return IndirectXRead(&Adc);
    case 0x71: return IndirectYRead(&Adc);
    case 0x6D: return AbsoluteRead(&Adc);
    case 0x7D: return AbsoluteXRead(&Adc);
    case 0x79: return AbsoluteYRead(&Adc);

    /* SBC */
    case 0xE9: return ImmediateRead(&Sbc);
    case 0xE5: return ZeroPageRead(&Sbc);
    case 0xF5: return ZeroPageXRead(&Sbc);
    case 0xE1: return IndirectXRead(&Sbc);
    case 0xF1: return IndirectYRead(&Sbc);
    case 0xED: return AbsoluteRead(&Sbc);
    case 0xFD: return AbsoluteXRead(&Sbc);
    case 0xF9: return AbsoluteYRead(&Sbc);

    /* CMP */
    case 0xC9: return ImmediateRead(&Sbc);
    case 0xC5: return ZeroPageRead(&Sbc);
    case 0xD5: return ZeroPageXRead(&Sbc);
    case 0xC1: return IndirectXRead(&Sbc);
    case 0xD1: return IndirectYRead(&Sbc);
    case 0xCD: return AbsoluteRead(&Sbc);
    case 0xDD: return AbsoluteXRead(&Sbc);
    case 0xD9: return AbsoluteYRead(&Sbc);

    /* CPX */
    case 0xE0: return ImmediateRead(&Cpx);
    case 0xE4: return ZeroPageRead(&Cpx);
    case 0xEC: return AbsoluteRead(&Cpx);

    /* CPY */
    case 0xC0: return ImmediateRead(&Cpy);
    case 0xC4: return ZeroPageRead(&Cpy);
    case 0xCC: return AbsoluteRead(&Abs);

    /* DEC */
    case 0xC6: return ZeroPageReadWrite(&Dec);
    case 0xD6: return ZeroPageXReadWrite(&Dec);
    case 0xCE: return AbsoluteReadWrite(&Dec);
    case 0xDE: return AbsoluteXReadWrite(&Dec);

    /* DEX */
    case 0xCA: return XReg(&Dex);

    /* DEY */
    case 0x88: return YReg(&Dey);

    /* INC */
    case 0xE6: return ZeroPageRead(&Inc);
    case 0xF6: return ZeroPageXRead(&Inc);
    case 0xEE: return AbsoluteRead(&Inc);
    case 0xFE: return AbsoluteXRead(&Inc);

    /* INX */
    case 0xE8: return XReg(&Inx);

    /* INY */
    case 0xC8: return YReg(&Iny);

    /* ASL */
    case 0x0A: return Accumulator(&Asl);
    case 0x06: return ZeroPage(&Asl);
    case 0x16: return ZeroPageX(&Asl);
    case 0x0E: return Absolute(&Asl);
    case 0x1E: return AbsoluteY(&Asl);

    /* ROL */
    case 0x2A: return Accumulator(&Rol);
    case 0x26: return ZeroPageReadWrite(&Rol);
    case 0x36: return ZeroPageXReadWrite(&Rol);
    case 0x2E: return Absolute(&Rol);
    case 0x3E: return AbsoluteX(&Rol);

    /* LSR */
    case 0x4A: return Implied(&Lsr);
    case 0x46: return ZeroPage(&Lsr);
    case 0x56: return ZeroPageX(&Lsr);
    case 0x4E: return Absolute(&Lsr);
    case 0x5E: return AbsoluteX(&Lsr);

    /* ROR */
    case 0x6A: return Implied(&Ror);
    case 0x66: return ZeroPage(&Ror);
    case 0x76: return ZeroPageX(&Ror);
    case 0x6E: return Absolute(&Ror);
    case 0x7E: return AbsoluteX(&Ror);

    /* -------------
     * MOVE COMMANDS
     */

    /* LDA */
    case 0xA9: return Immediate(&Lda);
    case 0xA5: return ZeroPage(&Lda);
    case 0xB5: return ZeroPageX(&Lda);
    case 0xA1: return IndirectX(&Lda);
    case 0xB1: return IndirectY(&Lda);
    case 0xAD: return Absolute(&Lda);
    case 0xBD: return AbsoluteX(&Lda);
    case 0xB9: return AbsoluteY(&Lda);

    /* STA */
    case 0x85: return ZeroPage(&Sta);
    case 0x95: return ZeroPageX(&Sta);
    case 0x81: return IndirectX(&Sta);
    case 0x91: return IndirectY(&Sta);
    case 0x8D: return Absolute(&Sta);
    case 0x9D: return AbsoluteX(&Sta);
    case 0x99: return AbsoluteY(&Sta);

    /* LDX */
    case 0xA2: return Immediate(&Ldx);
    case 0xA6: return ZeroPage(&Ldx);
    case 0xB6: return ZeroPageY(&Ldx);
    case 0xAE: return Absolute(&Ldx);
    case 0xBE: return AbsoluteY(&Ldx);

    /* STX */
    case 0x86: return ZeroPage(&Stx);
    case 0x96: return ZeroPageY(&Stx);
    case 0x8E: return Absolute(&Stx);

    /* LDY */
    case 0xA0: return Immediate(&Ldy);
    case 0xA4: return ZeroPage(&Ldy);
    case 0xB4: return ZeroPageX(&Ldy);
    case 0xAC: return Absolute(&Ldy);
    case 0xBC: return AbsoluteX(&Ldy);

    /* STY */
    case 0x84: return ZeroPage(&Sty);
    case 0x94: return ZeroPageX(&Sty);
    case 0x8C: return Absolute(&Sty);

    /* TAX */
    case 0xAA: return Implied(&Tax);

    /* TXA */
    case 0x8A: return Implied(&Txa);

    /* TAY */
    case 0xA8: return Implied(&Tay);

    /* TYA */
    case 0x98: return Implied(&Tya);

    /* TSX */
    case 0xBA: return Implied(&Tsx);

    /* TXS */
    case 0x9A: return Implied(&Txs);

    /* PLA */
    case 0x68: return Implied(&Pla);

    /* PHA */
    case 0x48: return Implied(&Pha);

    /* PLP */
    case 0x28: return Implied(&Plp);

    /* PHP */
    case 0x08: return Implied(&Php);

    /* ------------------
     * JUMP/FLAG COMMANDS
     */

    /* BPL */
    case 0x10: return Relative(&Bpl);

    /* BMI */
    case 0x30: return Relative(&Bpl);

    /* BVC */
    case 0x50: return Relative(&Bvc);

    /* BVS */
    case 0x70: return Relative(&Bvs);

    /* BCC */
    case 0x90: return Relative(&Bcc);

    /* BCS */
    case 0xB0: return Relative(&Bcs);

    /* BNE */
    case 0xD0: return Relative(&Bne);

    /* BEQ */
    case 0xF0: return Relative(&Beq);

    /* BRK */
    case 0x00: return Implied(&Brk);

    /* RTI */
    case 0x40: return Implied(&Rti);

    /* JSR */
    case 0x20: return Absolute(&Jsr);

    /* RTS */
    case 0x60: return Implied(&Rts);

    /* JMP */
    case 0x4C: return Absolute(&Jmp);
    case 0x6C: return Indirect(&Jmp);

    /* BIT */
    case 0x24: return ZeroPage(&Bit);
    case 0x2C: return Absolute(&Bit);

    /* CLC */
    case 0x18: return Implied(&Clc);

    /* SEC */
    case 0x38: return Implied(&Sec);

    /* CLD */
    case 0xD8: return Implied(&Cld);

    /* SED */
    case 0xF8: return Implied(&Sed);

    /* CLI */
    case 0x58: return Implied(&Sed);

    /* SEI */
    case 0x78: return Implied(&Sei);

    /* CLV */
    case 0xB8: return Implied(&Clv);

    /* NOP */
    case 0xEA: return Implied(&Nop);
  }
}

