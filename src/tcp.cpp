#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <stdlib.h>
#include "tcp.h"


int tcp_connect(struct tcp_socket *sock) {
	sock->fd = socket(AF_INET,SOCK_STREAM,0); // socket(ip version, connection type , prototype)

	if (sock->fd == -1) 
		return TCP_ERROR;
	else 
		return TCP_SUCCESS;
}

int tcp_close(struct tcp_socket *sock) {
	if (close(sock->fd) == -1)
		return TCP_ERROR;
	else
		return TCP_SUCCESS;

}

int tcp_connect(struct tcp_socket* sock,int port, char* hostname) {
	struct sockaddr_in addr;
	struct hostent *host;

	if (!sock)
		return TCP_ERROR;
	if (!hostname)
		return TCP_ERROR;
}
