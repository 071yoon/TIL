// TCP/IPv4 Client Program
#include <unistd.h>
#include <stdio.h> //pritf
#include <sys/types.h> //socket
#include <sys/socket.h> //socket
#include <netinet/in.h> //IPPROTO_TCP
#include <stdlib.h> //exit()
#include <string.h> //memset
#include <arpa/inet.h> //inet_addr()

int main() {
	int sock_cli;
	
	struct sockaddr_in server;
	int n;
	
	char* server_IP = "192.168.35.145";
	char* server_PORT = "30000";
	char data[100];
	
	//1. socket create
	sock_cli = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(sock_cli == -1) {
		perror("socket error \n");
		exit(1);
		}
	printf("sock_cli = %d \n", sock_cli);
	
	memset(&server, 0, sizeof(server)); //16byte 0 clear
	server.sin_family      = AF_INET; //2 
	server.sin_port        = htons(atoi(server_PORT)); //2 , /etc/services
	server.sin_addr.s_addr = inet_addr(server_IP); //4
	
	if(connect(sock_cli, (struct sockaddr*) &server, sizeof(server)) == -1){
		perror("connect error");
		exit(1);
	}
	printf("connect OK \n");
	
	stpcpy(data, "Hello Server~~~");
	n = send(sock_cli, data, strlen(data), 0);
	if(n != strlen(data)){
		perror("send error");
		exit(1);
	}
	printf("Client Send : %s\n", data);
	printf("send success\n");
	memset(data, 0, sizeof(data));
	n = recv(sock_cli, data, sizeof(data), 0);
	if (n == -1){
		perror("server recv error");
	}
	printf("Client Recv : %s \n", data);

	printf("Kunkook Univ. 202112497 Kim Jeongwoo\n");

	return 0;
}
	
	
