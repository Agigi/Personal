#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/uinput.h>
#include "virtualmouse.h"

/* Setup the uinput device */
int init_mouse()
{
	// Temporary variable
	//int i = 0;
	struct uinput_user_dev uinp; // uInput device structure
	
	// Open the input device
	uinp_fd = open("/dev/uinput", O_WRONLY | O_NDELAY);
	if (uinp_fd < 0) {
		//printf("Unable to open /dev/uinput\n");
		return -1;
	}
	
	memset(&uinp,0,sizeof(uinp)); // Intialize the uInput device to NULL
	strncpy(uinp.name, "Virtual Mouse", UINPUT_MAX_NAME_SIZE);
	uinp.id.version = 4;
	uinp.id.bustype = BUS_USB;
	
	// Setup the uinput device
	// Enable it to send events of pressing down/up some key/button
	ioctl(uinp_fd, UI_SET_EVBIT, EV_KEY);
	ioctl(uinp_fd, UI_SET_EVBIT, EV_REL);
	
	// Enable it to send events of the mouse relative position
	ioctl(uinp_fd, UI_SET_RELBIT, REL_X);
	ioctl(uinp_fd, UI_SET_RELBIT, REL_Y);
	
	// Enable it to send events of pressing down/up a specific key of a keyboard 
	//for (i = 0; i < 256; i++) {
	//	ioctl(uinp_fd, UI_SET_KEYBIT, i);
	//}
	
	// Enable it to send events of pressing down/up a specific button of a touchpad 
	//ioctl(uinp_fd, UI_SET_KEYBIT, BTN_MOUSE);
	//ioctl(uinp_fd, UI_SET_KEYBIT, BTN_TOUCH);
	
	// Enable it to send events of pressing down/up a specific button of a mouse 
	ioctl(uinp_fd, UI_SET_KEYBIT, BTN_MOUSE);
	ioctl(uinp_fd, UI_SET_KEYBIT, BTN_LEFT);
	ioctl(uinp_fd, UI_SET_KEYBIT, BTN_MIDDLE);
	ioctl(uinp_fd, UI_SET_KEYBIT, BTN_RIGHT);
	ioctl(uinp_fd, UI_SET_KEYBIT, BTN_FORWARD);
	ioctl(uinp_fd, UI_SET_KEYBIT, BTN_BACK);
	
	/* Create input device into input sub-system */
	if(write(uinp_fd, &uinp, sizeof (uinp)) != sizeof(uinp)) {
		//printf("First write returned fail.\n");
		return -1;
	}
	
	if (ioctl(uinp_fd, UI_DEV_CREATE)) {
		//printf("Unable to create UINPUT device.");
		return -1;
	}
	
	return 0;
}

void free_mouse()
{
	if(uinp_fd >= 0) {
		/* Destroy the input device */
		ioctl(uinp_fd, UI_DEV_DESTROY);
	
		/* Close the UINPUT device */
		close(uinp_fd);
	
		/* Reset the file descriptor */
		uinp_fd = -1;
	}
}

void send_mouse_press(int mouse_btn, int is_press)
{
	struct input_event event; // Input device structure
	int event_code = BTN_LEFT;
	int event_value = (is_press) ? 1 : 0;
	
	if(uinp_fd >= 0) {
		switch(mouse_btn) {
		case MOUSE_LEFT_BTN:
			event_code = BTN_LEFT;
			break;
		case MOUSE_RIGHT_BTN:
			event_code = BTN_RIGHT;
			break;
		case MOUSE_MIDDLE_BTN:
			event_code = BTN_MIDDLE;
			break;
		default: //Set Button left by default
			event_code = BTN_LEFT;
			break;
		}

		// Report BUTTON CLICK - PRESS or RELEASE event
		memset(&event, 0, sizeof(event));
		gettimeofday(&event.time, NULL);
	
		event.type = EV_KEY;
		event.code = event_code;
		event.value = event_value;
		write(uinp_fd, &event, sizeof(event));
	
		event.type = EV_SYN;
		event.code = SYN_REPORT;
		event.value = 0;
		write(uinp_fd, &event, sizeof(event));
	}
}

void send_mouse_move(int move_x, int move_y)
{
	struct input_event event; // Input device structure
	
	if(uinp_fd >= 0) {
		// Move the pointer by vector (move_x, move_y)
		memset(&event, 0, sizeof(event));
		gettimeofday(&event.time, NULL);
	
		event.type = EV_REL;
		event.code = REL_X;
		event.value = move_x;
		write(uinp_fd, &event, sizeof(event));
	
		event.type = EV_REL;
		event.code = REL_Y;
		event.value = move_y;
		write(uinp_fd, &event, sizeof(event));
	
		event.type = EV_SYN;
		event.code = SYN_REPORT;
		event.value = 0;
		write(uinp_fd, &event, sizeof(event));
	}
}
