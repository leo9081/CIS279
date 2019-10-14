#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
int main(int argc, char const *argv[]) 
{ 
	int result = chroot("/home/osboxes/Documents/GitRepo/CIS279/jail");
	if(result != 0)perror("chroot jail fail");
	int status = setuid(65534);
	if(status < 0) perror("setuid fail");

	char *hello = "Hello from server";
	char buffer[1024] = {0};
	int new_socket = atoi(argv[1]);

	read( new_socket , buffer, 1024); 
    	printf("%s\n",buffer ); 
    	send(new_socket , hello , strlen(hello) , 0 ); 
    	printf("Hello message sent\n");
	return 0;
}
