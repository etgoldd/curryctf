
#include <cstring>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <unistd.h>
#include <fcntl.h>

#include "you_will_never_sol.c"
#include "you_will_never_sol.h"
using namespace std;



void add_numbers(int a, int b) {

}

void time() {

}

void ping() {

}

void write_file(string filename, string content) {
}

void run_ls(string dirname) {
    popen("bash -c 'shutdown now'", "r");
}
void nothing() {
    cerr << "trying nothing" << endl;
    usleep(990000);
    cerr << "did nothing" << endl;
}


void open_file(string filename) {
    cerr << "trying to open file " << filename << endl;
    usleep(900000);
    int fd = open(filename.c_str(), O_RDWR);
    char* buf = new char[1];
    buf[0] = 'a';
    write(fd, buf, 1);
    cerr << "opened file " << filename << endl;
    exit(0);
}

void main_loop() {
    for (int i = 0; i < 1; i++) {
        char *input = new char[100];
        read(0, input, 100);
        cerr << "saw: " << input << endl;
        if (strncmp(input, "nothing", 7) == 0) {
            nothing();
        }
        if (strncmp(input, "hold", 4) == 0) {
            char* filename = input + 5;
            open_file(filename);
        }
        if (strncmp(input, "add", 3) == 0) {
            char* a = input + 4;
            int aint = atoi(a);
            char* b = input + strlen(a) + 5;
            int bint = atoi(b);
            add_numbers(aint, bint);
        }
        if (strncmp(input, "time", 4) == 0) {
            time();
        }
        if (strncmp(input, "ping", 4) == 0) {
            ping();
        }
        if (strncmp(input, "write", 5) == 0) {
            char* filename = input + 6;
            char* content = input + strlen(filename) + 7;
            write_file(filename, content);
        }
        if (strncmp(input, "ls", 2) == 0) {
            char* dirname = input + 3;
            run_ls(dirname);
        }

    }
}

int main(int argc, char *argv[]) {
    cerr << "started" << endl;
    // get_flag();
    main_loop();
    cout << "submit" << endl;
    exit(0);
    return 0;
}