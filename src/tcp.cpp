#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/select.h>
#include "tcp.h"
#include <netdb.h>
#include <unistd.h>

/**********************************************************************
 *	Function section started
 * ********************************************************************/

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
		return TCP_PARAM_ERROR;
	if (!hostname)
		return TCP_PARAM_ERROR;

	if (sock->fd < 0)
		return TCP_ERROR;
	host = gethostbyname(hostname);
	
	addr.sin_addr.s_addr = *(unsigned long*)host->h_addr_list[0];
	addr.sin_family = AF_INET;
	addr.sin_port = htons((unsigned short)port);
	
	if (connect(sock->fd, (struct sockaddr* )&addr,sizeof(addr)))
		return TCP_CONNECT_ERROR;

	return TCP_SUCCESS;
}

int tcp_send(struct tcp_socket* sock, char* buffer, int size) {
	if (!sock)
		return TCP_PARAM_ERROR;
	if (sock->fd == -1)
		return TCP_ERROR;
	if (write(sock->fd,buffer,size) < 0) {
		return TCP_ERROR;
	}
	return TCP_SUCCESS;
}

int tcp_recv(struct tcp_socket* sock,char* buffer,int *size,int buffer_size) {
	ssize_t rxsize;
	int errcode;

	if (!sock)
		return TCP_PARAM_ERROR;

	if (!size)
		return TCP_PARAM_ERROR;

	if (sock->fd == -1)
		return TCP_ERROR;

	if (buffer_size == 0)
		return TCP_PARAM_ERROR;

	rxsize = read(sock->fd,buffer, buffer_size);
	errcode = errno; // errno is automatically filled by read() function
	*size = (int)rxsize;

	return TCP_SUCCESS;
	
}
