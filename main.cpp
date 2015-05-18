#include <iostream>
#include "CPU.h"
using namespace std;

int main() {
    CPU* vm = new CPU();
    vm->run();
#ifdef _WIN32
	cin.get();
#endif
    return 0;
}
