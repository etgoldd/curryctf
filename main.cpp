
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main(int argc, char *argv[]) {
    return 0;
}

void get_input() {
    while (true) {
        string input;
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