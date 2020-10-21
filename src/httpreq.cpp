#include <stdlib.h>
#include <string.h>
#include "tcp.h"
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

int download_file(struct tcp_socket* sock, char* file_name, char* url,char* method) {
	char *header = (char*)malloc(sizeof(char)*2048);
	char *path = (char*)malloc(sizeof(char)*1024);

	extractThePath(header,path);

	method = toupper(method); // Converting the method in upper case character
	strcpy(header, method); // Copying the method type into the header buffer
	strcat(header, " HTTP/1.1");
	strcat(header,path);
	strcat(header,"\r\nHost:");
	strcat(header, " ");
	strcat(header,url);
	strcat(header, "\r\n");
	if (!sock)
		return TCP_ERROR;

	if (file_name[0] == '\0')
		return FILE_PARAM_ERROR;

	if (url[0] == '\0')
		return FILE_PARAM_ERROR;

	// sending http download request to the server
	int send_header = tcp_send(sock->fd, header, strlen(header));

	// Receiving the data from the server 
	int file_recv = tcp_recv(sock->fd, file_name, 1024); // receiving data by 1kb per chunks
}
