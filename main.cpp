
#include <string.h>
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





