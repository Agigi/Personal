CFLAGS = -Wall -pthread
all: s c
s: pthread_socket_server_test2
c: pthread_socket_client_test2
pthread_socket_server_test2: pthread_socket_server_test2.c
pthread_socket_client_test2: pthread_socket_client_test2.c
clean:
	rm -f ./pthread_socket_server_test2
	rm -f ./pthread_socket_client_test2
