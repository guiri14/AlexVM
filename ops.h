#ifndef OPS_H
#define OPS_H
#include <stdint.h>
typedef uint8_t BYTE;
typedef uint16_t WORD;

enum ASM {
    END,
    SET,
    MOV,
    ADD,
    SUB,
    MUL,
    DIV,
    LOG,
	LOGH,
    JMP,
    CMP,
    JE,
    JNE,
    JGT,
    JLT,
    JGE,
    JLE,
    INC,
    DEC,
	NOP, // null op
	ROTL,//  rotate left, EX: ROTL 1100101010110001 --> 1001010101100011
	ROTR // rotate right, EX: ROTR 1100101010110001 --> 1110010101011000
};

enum REGS {
    A,
    B,
    C,
    D,
    FLAGS,
    IP,
    SP,
    NUM_OF_REGS
};

#endif
