#include <iostream>
#include <fstream>
#include "CPU.h"
using namespace std;

int main(int argc, char* argv[]) {
    if(argc == 2){
        char* file;
        streampos size;
        ifstream in(argv[1], ios::in|ios::binary|ios::ate);
        if(in.is_open()){
            size = in.tellg();
            file = new char[size];
            in.seekg(0, ios::beg);
            in.read(file, size);
            in.close();
            cout << file << endl;
            cout << &file << endl;
            CPU* vm = new CPU(file);
            vm->run();
        } else {
            cout << "Sorry, that file was inaccessible\n";
        }
    }else {
        cout << "Sorry, you did not input valid data, format:  run.out [FILENAME]\n";
    }
#ifdef _WIN32
        cin.get();
#endif
    return 0;
}
