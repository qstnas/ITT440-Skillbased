#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

void error(const char *msg) { 
perror(msg); 
exit(1); 
} 

int main() { 
int sock_fd; 
struct sockaddr_in server_address; 
char buffer[256]; 
int x; 

sock_fd = socket(AF_INET, SOCK_STREAM, 0); 
if (sock_fd < 0) 
error("Unable to create socket"); 
server_address.sin_family = AF_INET; 
server_address.sin_addr.s_addr = inet_addr("10.0.2.15"); 
server_address.sin_port = htons(8888); 
if (connect(sock_fd, (struct sockaddr *) &server_address, sizeof(server_add> 
error("Error connecting"); 
bzero(buffer, sizeof(buffer)); 
x = read(sock_fd, buffer, sizeof(buffer)-1); 
if (x < 0) 
error("Unable to read the socket"); 
printf("Random number from server : %s\n", buffer); 
close(sock_fd); 
return 0; 
}

 
