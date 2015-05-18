#include "CPU.h"

WORD program[] = {
    SET, 0, A,
    SET, 1, B,
    SET, 101, C,
    ADD, B, A, //Accumulate B values in A
    INC, B,    //Increment B
    CMP, B, C, //See if B is == 101 
    LOG, A,
    JLT, 9,   //Jump to ADD B A
    LOG, A,
	SET, 0xC6E7, C,
	LOGH, C,
	ROTL, C,
	ROTL, C,
	ROTL, C,
	ROTL, C,
	LOGH, C,
	ROTL, C,
	ROTL, C,
	ROTL, C,
	ROTL, C,
	LOGH, C,
	ROTL, C,
	ROTL, C,
	ROTL, C,
	ROTL, C,
	LOGH, C,
	ROTL, C,
	ROTL, C,
	ROTL, C,
	ROTL, C,
	LOGH, C,
	ROTR, C,
	ROTR, C,
	ROTR, C,
	ROTR, C,
	LOGH, C,
	ROTR, C,
	ROTR, C,
	ROTR, C,
	ROTR, C,
	LOGH, C,
	ROTR, C,
	ROTR, C,
	ROTR, C,
	ROTR, C,
	LOGH, C,
	ROTR, C,
	ROTR, C,
	ROTR, C,
	ROTR, C,
	LOGH, C,
	NOP,
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
        case MOV: {
            WORD src = next();
            WORD dst = next();
            registers[dst] = registers[src];
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
		case LOGH: {
			WORD reg = next();
			printf("%x\n", registers[reg]);
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
            registers[FLAGS] = 0;
            if(registers[a] == registers[b])
                registers[FLAGS] = (1<<0);
            if(registers[a] > registers[b])
                registers[FLAGS] = (1<<1);
            if(registers[a] < registers[b])
                registers[FLAGS] = (1<<2);
            break;
        }
        case JE: {
            WORD loc = next();
            WORD flag = registers[FLAGS]&(1<<0);
            if(flag == (1<<0)){
                registers[IP] = loc-1;
            }
            break;
        }
        case JNE: { 
            WORD loc = next();
            WORD flag = registers[FLAGS]&(1<<0);
            if(flag != (1<<0)){
                registers[IP] = loc-1;
            }
            break;
        }
        case JGT: { 
            WORD loc = next();
            WORD flag = registers[FLAGS]&(1<<1);
            if(flag == (1<<1)){
                registers[IP] = loc-1;
            }
            break;
        }
        case JLT: { 
            WORD loc = next();
            WORD flag = registers[FLAGS]&(1<<2);
            if(flag == (1<<2)){
                registers[IP] = loc-1;
            }
            break;
        }
        case JGE: { 
            WORD loc = next();
            WORD flag = registers[FLAGS]&(1<<2);
            if(flag != (1<<2)){ //Is NOT less than
                registers[IP] = loc-1;
            }
            break;
        }
        case JLE: { 
            WORD loc = next();
            WORD flag = registers[FLAGS]&(1<<1);
            if(flag != (1<<1)){ // Is NOT greater than
                registers[IP] = loc-1;
            }
            break;
        }
        case INC: {
            WORD reg = next();
            registers[reg]++;
            break;
        }
        case DEC: {
            WORD reg = next();
            registers[reg]--;
            break;
        }
		case NOP: {
			next(); // SCHKIIIIIPPP!!!
			break;
		}
		case ROTL: {
			WORD reg = next();
			WORD rotate = (registers[reg] << 1) & 0xFFFE; // get the logical rotate
			WORD last = ((registers[reg] & (1 << 15)) >> 15); // get the bit rotated off
			WORD final = rotate | last; // or them together
			registers[reg] = final;
			break;
		}
		case ROTR: {
			WORD reg = next();
			WORD rotate = (registers[reg] >> 1) & 0x7FFF; // get the logical rotate
			WORD last = ((registers[reg] & 1) << 15); // get the bit rotated off
			WORD final = rotate | last; // or them together
			registers[reg] = final;
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
