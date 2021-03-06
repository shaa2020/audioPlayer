#pragma once

struct tcp_socket {
	int fd;
};

#define TCP_ERROR -102
#define TCP_SUCCESS 102
#define TCP_PARAM_ERROR -103
#define TCP_CONNECT_ERROR -104
#define TCP_RECV_ERROR -105

int tcp_connect(struct tcp_socket *sock);
int tcp_close(struct tcp_socket *sock);
int tcp_connect(struct tcp_socket* sock,int port, char* hostname);
int tcp_send(struct tcp_socket* sock, char* buffer,int size);
int tcp_recv(struct tcp_socket* sock, char* buffer, int *size);
int tcp_recv_wait(struct tcp_socket *sock, char* buffer, int *size, int buffer_size, unsigned int timeout_ms);
