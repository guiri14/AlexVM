#ifndef CPU_H
#define CPU_H

#include "ops.h"
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
class CPU {
    bool useFile;
    bool running;

    WORD* file;

    WORD fetch();
    void execute(WORD op);
    WORD next();
    
    WORD registers[NUM_OF_REGS];

public:
    CPU(char* file);

    void run();
};

#endif
