#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include<time.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include<netinet/in.h> 

void error(const char *msg) { 
perror(msg); 
exit(1); 
} 

int main() { 
int sock_fd, new_sock; 
struct sockaddr_in server_address, client_address; 
int random_num; 
char buffer[256]; 
int x; 
sock_fd = socket(AF_INET, SOCK_STREAM, 0); 

if (sock_fd < 0) 
error("socket error"); 
server_address.sin_family = AF_INET; 
server_address.sin_addr.s_addr = INADDR_ANY; 
server_address.sin_port = htons(1234); 

if (bind(sock_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) 
error("Socket error to bind"); 
listen(sock_fd, 5); 
socklen_t client_length = sizeof(client_address); 
new_sock = accept(sock_fd, (struct sockaddr *) &client_address, &client_length); 

if (new_sock < 0) 
error("Error to accept"); 
srand(time(NULL)); 
random_num = (rand() % 999) + 100; 
sprintf(buffer, "%d", random_num); 
printf(“Successfully send to client\n”); 
x = write(new_sock, buffer, sizeof(buffer)); 

if (x < 0) error("Socket error to execute"); 
close(new_sock); 
close(sock_fd); 
return 0; 
}
