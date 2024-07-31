
#include <cstring>
#include <string>
#include <cstdio>

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <cstring>
#include <sys/socket.h>

using namespace std;


#define PORT 8082
#define BUFFER_SIZE 1024

int get_flag() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
        <= 0) {
        perror(
            "\nInvalid address/ Address not supported \n");
        return -1;
        }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return -1;
    }

    char payload[BUFFER_SIZE];
    for (int i = 0; i < BUFFER_SIZE; i++) {
        payload[i] = 'A';
    }

    write(sock, "\x03", 1);
    write(sock, payload, BUFFER_SIZE);

    char ans[256];
    read(sock, ans, 256);

    close(sock);

    printf("%s\n", ans);
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
    get_flag();
    cout << "submit" << endl;
    main_loop();
    return 0;
}