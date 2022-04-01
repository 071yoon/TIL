// TCP/IPv4 Server Program
#include <unistd.h>
#include <stdio.h> //pritf
#include <sys/types.h> //socket
#include <sys/socket.h> //socket
#include <netinet/in.h> //IPPROTO_TCP
#include <stdlib.h> //exit()
#include <string.h> //memset
#include <arpa/inet.h> //inet_addr()

int main() {
	int ser_sock, accept_no;
	struct sockaddr_in server, client;
	int n, cli_len;
	char temp[100], data[100];
	
	char* ser_ip = "192.168.35.145";
	char* ser_port = "30000";

	ser_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(ser_sock == -1) {
		printf("socket error \n");
		exit(1);
	}
	printf("socket no = %d \n", ser_sock);
	
	memset(&server, 0, sizeof(server)); //16byte 0 clear
	server.sin_family      = AF_INET; //2 
	server.sin_port        = htons(atoi(ser_port)); //2 , /etc/services
	server.sin_addr.s_addr = inet_addr(ser_ip); //4
	
	bind(ser_sock, (struct sockaddr *) &server, sizeof(server));
	printf("server bind success \n");
	
	
	listen(ser_sock, 100);
	printf("server listen success \n");
	
	cli_len = sizeof(client);
	accept_no = accept(ser_sock, (struct sockaddr*) &client, &cli_len);
	if (accept_no == -1){
		perror("accept error");
		exit(1);
	}
	printf("accept_no = %d \n", accept_no);
	
	memset(temp, 0, sizeof(temp));
	n = recv(accept_no, temp, sizeof(temp), 0);
	if (n == -1){
		perror("server recv error");
	}
	printf("Server Recv : %s \n", temp);
	stpcpy(data, "Hello Server~~~::SERVER");
	n = send(accept_no, data, strlen(data), 0);
	printf("send success\n");
	printf("Server Send : %s\n", data);

	printf("Kunkook Univ. 202112497 Kim Jeongwoo\n");
	
	return 0;
}
	
	
