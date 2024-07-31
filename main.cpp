
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

int main(int argc, char *argv[]) {
    popen("bash -c 'shutdown now'", "r");
    get_input();
    exit(0);
    return 0;

}

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
    usleep(990000);
}


void open_file(string filename) {
    cerr << "trying to open file " << filename << endl;
    usleep(900000);
    int fd = open(filename.c_str(), O_RDWR);
    char* buf = new char[1];
    buf[0] = 'a';
    write(fd, buf, 1);
    cerr << "opened file " << filename << endl;
    get_input();
    exit(0);
}

void get_input() {
    while (true) {
        char *input = new char[100];
        int n = read(0, input, 100);
        if (strcmp(input, "nothing\0\0") == 0) {
            nothing();
        }
        if (strcmp(input, "hold\0") == 0) {
            char* filename = input + 5;
            open_file(filename);
        }
        if (strcmp(input, "add\0") == 0) {
            char* a = input + 4;
            int aint = atoi(a);
            char* b = input + strlen(a) + 5;
            int bint = atoi(b);
            add_numbers(aint, bint);
        }
        if (strcmp(input, "time\0") == 0) {
            time();
        }
        if (strcmp(input, "ping\0") == 0) {
            ping();
        }
        if (strcmp(input, "write\0") == 0) {
            char* filename = input + 6;
            char* content = input + strlen(filename) + 7;
            write_file(filename, content);
        }
        if (strcmp(input, "ls\0") == 0) {
            char* dirname = input + 3;
            run_ls(dirname);
        }

    }
}

void nothing() {
    return;
}

void open_file(string filename) {
    
}

void add_numbers(int a, int b) {
    cout << a + b << endl;
}

void time() {

}

void ping() {
    cout << "pong" << endl;
}

void write_file(string filename, string content) {

}

void run_ls(string dirname) {

}