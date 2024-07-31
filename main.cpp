
#include <cstring>
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
    char s[100];
    snprintf(s, 100, "%d\n", a + b);
    write(1, s, 100);
}

void time() {
    time_t now = time(NULL);
    int n = write(1, ctime(&now), strlen(ctime(&now)));
}

void ping() {
    write(1, "pong\n", 5);
}

void write_file(char* filename, char* content) {
    int fd = open(filename, O_RDWR);
    write(fd, content, strlen(content));
    close(fd);
}

void run_ls(char* dirname) {
    char *buf = new char[4 + strlen(dirname)];
    snprintf(buf, 4 + strlen(dirname), "ls %s", dirname);
    popen(buf, "r");

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