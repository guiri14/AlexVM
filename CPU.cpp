#include "CPU.h"

WORD program[] = {
    SET, 999, B,
    SET, 1, D,
    SET, 0, C,
    SET, 4, A,
    SUB, D, A,
    LOG, A,
    CMP, A, C,
    JNE, 12,
    LOG, B,
    END
};

CPU::CPU(){
    running = false;
    for(int i = 0; i < NUM_OF_REGS; i++) {
        registers[i] = 0;
    }//Clear all of the registers
}

WORD CPU::fetch(){
    return program[registers[IP]];
}

WORD CPU::next() {
    return program[++registers[IP]];
}


void CPU::execute(WORD op) {
    switch(op) {
        case END: {
            running = false;
            for(int i = 0; i < NUM_OF_REGS; i++) {
                registers[i] = 0;
            }//Clear all of the registers
            break;
        }
        case SET: {
            WORD val = next();
            WORD reg = next();
            registers[reg] = val;
            break;
        }
        case ADD: {
            WORD src = next();
            WORD dst = next();
            registers[dst] += registers[src];
            break;
        }
        case SUB: {
            WORD src = next();
            WORD dst = next();
            registers[dst] -= registers[src];
            break;
        }
        case MUL: {
            WORD src = next();
            WORD dst = next();
            registers[dst] *= registers[src];
            break;
        }
        case DIV: {
            WORD src = next();
            WORD dst = next();
            registers[dst] /= registers[src];
            break;
        }
        case LOG: {
            WORD reg = next();
            cout << registers[reg] << endl;
            break;
        }
        case JMP: {
            WORD loc = next();
            registers[IP] = loc-1;
            break;
        }
        case CMP: {
            WORD a = next();
            WORD b = next();
            WORD c = registers[a]-registers[b];
            registers[EQ] = c;
            break;
        }
        case JE: {
            WORD loc = next();
            if(registers[EQ] == 0)
                registers[IP] = loc-1;
            break;
        }
        case JNE: { 
            WORD loc = next();
            if(registers[EQ] != 0)
                registers[IP] = loc-1;
            break;
        }
    }
}

void CPU::run() {
    running = true;
    while(running) {
        WORD op = fetch();
        execute(op);
        registers[IP]++;
    }
}
