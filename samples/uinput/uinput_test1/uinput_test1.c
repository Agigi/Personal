#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "virtualmouse.h"

int main(int argc, char* argv[]) {
	int move_x = 0;
	int move_y = 0;
	int i;
	
	if (argc != 3) {
		printf("Usage:\n");
		printf("   %s [X Move] [Y Move]\n", argv[0]);
		exit(1);
	}
	
	move_x = atoi(argv[1]);
	move_y = atoi(argv[2]);
	
	init_mouse();
	sleep(5); //init_mouse() needs some time to work! Important!!
	send_mouse_move(move_x, move_y);
	free_mouse();
	
	return 0;
}
