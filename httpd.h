#ifndef _HTTPD_H
#define _HTTPD_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include<sys/types.h>
#include<sys/socket.h>
//#include<linux/in.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>
#include<pthread.h>

#include<sys/sendfile.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#define _BACK_LOG_    5
#define _COMM_SIZE_ 1024
#define MAIN_PAGE "index.html"
#define HTTP_VERSION "HTTP/1.0"

#endif
