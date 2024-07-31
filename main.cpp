
#include <string>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

int main(int argc, char *argv[]) {
    return 0;

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

void add_numbers(int a, int b) {

}

void time() {


}

void ping() {

}

void write_file(string filename, string content) {
}

void run_ls(string dirname) {

}