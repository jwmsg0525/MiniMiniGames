#include <curses.h>
#include "controller_main.h"
#include "view_main.h"


void F_MAIN_RUN() {
	V_SET_MAIN_VIEW();
	V_VIEW_MAIN_WELCOME();
}