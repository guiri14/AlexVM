#ifndef CPU_H
#define CPU_H

#include "ops.h"
#include <iostream>
using namespace std;
class CPU {
    bool running;

    WORD fetch();
    void execute(WORD op);
    WORD next();
    
    WORD registers[NUM_OF_REGS];

public:
    CPU();

    void run();
};

#endif
