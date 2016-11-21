#include "ops.h"

WORD TestProgram[] = {
    SET, 0, A,
    SET, 1, B,
    SET, 5, C,
    ADD, B, A, //Accumulate B values in A
    INC, B,    //Increment B
    CMP, B, C, //See if B is == 101 
    LOG, A,
    JLT, 18,   //Jump to ADD B A
    END
};
