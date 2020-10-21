#pragma once

#define FILE_NOT_FOUND 0xff
#define FILE_PARAM_ERROR 0xAA

int download_file(struct tcp_socket * sock, char* file_name, char* url);
int download_text();
int download_json();
