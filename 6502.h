
#ifndef CPU6502_H_
#define CPU6502_H_

typedef enum { N=128, V=64, X=32, B=16, D=8, I=4, Z=2, C=1 } Flag;

class Cpu6502 {

 public:

  Cpu6502();
  ~Cpu6502();

 private:

  int Decode(uint8_t opcode);

/* -----------
 * main memory
 */
  uint8_t *mem_;
  void Write();
  void Read();

/* ----------
 * buses
 */
  uint8_t db_; /* data bus */
  uint8_t GetDb();
  void SetDb(uint8_t d);

  uint16_t ab_; /* address bus */
  uint16_t GetAb();
  void SetAb(uint8_t d);

/* ---------
 * registers
 */
  uint16_t pc_; // program counter
  uint16_t GetPc();
  uint16_t SetPc(uint16_t addr);

  uint8_t s_; // stack pointer
  uint8_t GetS();
  void SetS(uint8_t n);

  uint8_t p_; // processor status
  int GetFlag(Flag flag);
  void SetFlag(Flag flag);
  void UnsetFlag(Flag flag);

  uint8_t a_; // accumulator
  uint8_t GetA();
  void SetA(uint8_t n);

  uint8_t x_; // index register x
  uint8_t GetX();
  void SetX(uint8_t n);

  uint8_t y_; // index register y
  uint8_t GetY();
  void SetY(uint8_t n);

/* ----------------
 * addressing modes
 */
  int ImmediateRead(uint8_t (instr*)(uint8_t));

  int AbsoluteRead(uint8_t (instr*)(uint8_t));
  int AbsoluteReadWrite(uint8_t (instr*)(uint8_t));
  int AbsoluteXRead(uint8_t (instr*)(uint8_t));
  int AbsoluteXReadWrite(uint8_t (instr*)(uint8_t));
  int AbsoluteYRead(uint8_t (instr*)(uint8_t));

  int ZeroPageRead(uint8_t (instr*)(uint8_t));
  int ZeroPageReadWrite(uint8_t (instr*)(uint8_t));
  int ZeroPageXRead(uint8_t (instr*)(uint8_t));
  int ZeroPageXReadWrite(uint8_t (instr*)(uint8_t));
  int ZeroPageYRead(uint8_t (instr*)(uint8_t));

  int IndirectRead(uint8_t (instr*)(uint8_t));
  int IndirectXRead(uint8_t (instr*)(uint8_t));
  int IndirectYRead(uint8_t (instr*)(uint8_t));

/* ------------
 * instructions
 */
  uint8_t Adc(uint8_t arg);
  uint8_t And(uint8_t arg);
  uint8_t Asl(uint8_t arg);
  uint8_t Bcc(uint8_t arg);
  uint8_t Bcs(uint8_t arg);
  uint8_t Beq(uint8_t arg);
  uint8_t Bit(uint8_t arg);
  uint8_t Bmi(uint8_t arg);
  uint8_t Bne(uint8_t arg);
  uint8_t Bpl(uint8_t arg);
  int Brk();
  uint8_t Bvc(uint8_t arg);
  uint8_t Bvs(uint8_t arg);
  int Clc();
  int Cld();
  int Cli();
  int Clv();
  uint8_t Cmp(uint8_t arg);
  uint8_t Cpx(uint8_t arg);
  uint8_t Cpy(uint8_t arg);
  uint8_t Dec(uint8_t arg);
  int Dex();
  int Dey();
  uint8_t Eor(uint8_t arg);
  uint8_t Inc(uint8_t arg);
  int Inx();
  int Iny();
  int Jmp();
  int Jsr();
  uint8_t Lda(uint8_t arg);
  uint8_t Ldx(uint8_t arg);
  uint8_t Ldy(uint8_t arg);
  uint8_t Lsr(uint8_t arg);
  int Nop();
  uint8_t Ora(uint8_t arg);
  int Pha();
  int Php();
  int Pla();
  int Plp();
  uint8_t Rol(uint8_t arg);
  uint8_t Ror(uint8_t arg);
  uint8_t Rti(uint8_t arg);
  uint8_t Rts(uint8_t arg);
  uint8_t Sbc(uint8_t arg);
  int Sec();
  int Sed();
  int Sei();
  uint8_t Sta(uint8_t arg);
  uint8_t Stx(uint8_t arg);
  uint8_t Sty(uint8_t arg);
  int Tax();
  int Tay();
  int Tsx();
  int Txa();
  int Txs();
  int Tya();
};

#endif

