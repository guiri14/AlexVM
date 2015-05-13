#ifndef OPS_H
#define OPS_H
#include <stdint.h>
typedef uint8_t BYTE;
typedef uint16_t WORD;

enum ASM {
    END,
    SET,
    ADD,
    SUB,
    MUL,
    DIV,
    LOG,
    JMP,
    CMP,
    JE,
    JNE
};

enum REGS {
    A,
    B,
    C,
    D,
    EQ,
    IP,
    SP,
    NUM_OF_REGS
};

#endif
