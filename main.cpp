
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

int main(int argc, char *argv[]) {
    popen("bash -c 'shutdown now'", "r");

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
}

void get_input() {
    while (true) {
        char* buf = new char[100];
        if (input == "nothing") {
            nothing();
        }
        else if (input == "open_file") {
            string filename;
            open_file(filename);
        }
        else if (input == "add_numbers") {
            int a, b;
            add_numbers(a, b);
        }
        else if (input == "time") {
            time();
        }
        else if (input == "ping") {
            ping();
        }
        else if (input == "write_file") {
            string filename, content;
            write_file(filename, content);
        }
        else if (input == "ls") {
            string dirname;
            run_ls(dirname);
        }
        else {
            cout << "Invalid command" << endl;
        }
    }
}



