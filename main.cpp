#include <iostream>
#include "CPU.h"
using namespace std;

int main() {
    CPU* vm = new CPU();
    vm->run();
    return 0;
}
