#pragma once

struct tcp_socket {
	int fd;
};

#define TCP_ERROR -102
#define TCP_SUCCESS 102
#define TCP_PARAM_ERROR -103

int tcp_connect(struct tcp_socket *sock);
int tcp_close(struct tcp_socket *sock);
int tcp_connect(struct tcp_socket* sock,int port, char* hostname);
int tcp_send(struct tcp_socket* sock, char* buffer,int size);
int tcp_recv(struct tcp_socket* sock, char* buffer, int *size);
