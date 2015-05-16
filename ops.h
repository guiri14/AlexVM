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
    JMP,
    CMP,
    JE,
    JNE,
    JGT,
    JLT,
    JGE,
    JLE,
    INC,
    DEC
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
