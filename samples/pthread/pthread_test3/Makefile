CFLAGS = -Wall -pthread
all: s c
s: pthread_socket_server_test3
c: pthread_socket_client_test3
pthread_socket_server_test3: pthread_socket_server_test3.c
pthread_socket_client_test3: pthread_socket_client_test3.c
clean:
	rm -f ./pthread_socket_server_test3
	rm -f ./pthread_socket_client_test3
