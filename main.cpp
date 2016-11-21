#include <iostream>
#include <fstream>
#include "CPU.h"
#include "TestFile.h"
using namespace std;

void display_instructions(char* filename){
    cout << "Valid commands are:" << endl;
    cout << "To run a file:  " << filename << " -r [FILENAME]" << endl;
    cout << "To run the test: " << filename << " -t" << endl;
    cout << "To write test file: " << filename << " -o [FILENAME]" << endl;
}

int main(int argc, char* argv[]) {
    if(argc == 3){
        if(strcmp(argv[1], "-r") == 0){
            char* file;
            streampos size;
            ifstream in(argv[2], ios::in|ios::binary|ios::ate);
            if(in.is_open()){
                size = in.tellg();
                file = new char[size];
                in.seekg(0, ios::beg);
                in.read(file, size);
                in.close();
                CPU* vm = new CPU(file, size);
                vm->run();
            } else {
                cout << "Sorry, that file was inaccessible\n";
            }
        } else if(strcmp(argv[1], "-o") == 0){ 
            string filename = argv[2];
            if(filename == ""){
                filename = "out.avm";
            }
            ofstream out(filename, ios::out|ios::binary);
            out.write(
                ((char*)(&TestProgram[0])), 
                sizeof(TestProgram) * sizeof(TestProgram[0])
            );
            out.close();
            cout << "Test Program written to " << filename << endl;
        } else {
            display_instructions(argv[0]);
        }
    } else if(argc == 2){
        if(strcmp(argv[1], "-t") == 0){
            CPU* vm = new CPU(((char*)(&TestProgram[0])), sizeof(TestProgram));
            vm->run();
        }
        else {
            display_instructions(argv[0]);
        }
    } else {
        display_instructions(argv[0]);
    }
#ifdef _WIN32
        cin.get();
#endif
    return 0;
}
