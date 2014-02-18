CFLAGS = -Wall -pthread
all: s c
s: pthread_socket_server_test1
c: pthread_socket_client_test1
pthread_socket_server_test1: pthread_socket_server_test1.c
pthread_socket_client_test1: pthread_socket_client_test1.c
clean:
	rm -f ./pthread_socket_server_test1
	rm -f ./pthread_socket_client_test1
