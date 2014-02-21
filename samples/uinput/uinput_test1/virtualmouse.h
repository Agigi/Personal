/* Define */
#define MOUSE_LEFT_BTN		(0x1)
#define MOUSE_RIGHT_BTN		(0x2)
#define MOUSE_MIDDLE_BTN	(0x3)

/* Globals */
static int uinp_fd = -1;

/* Functions */
int init_mouse();
void free_mouse();
void send_mouse_press(int mouse_btn, int is_press);
void send_mouse_move(int move_x, int move_y);
