#include <curses.h>

#include "view_menu.h"


void V_SET_MENU_VIEW() {
	INIT_PAGE();
	V_SET_MENU_COLORPAIR();
	DRAW_RACT_COLORD(0, 30, MAX_Y, MAX_X, 3);
	refresh();
}

void V_ADD_MENU_ITEM(int pos, char * data, int isSELECTED) {
	if (isSELECTED == 1) {
		DRAW_RACT_COLORD((pos * 3), 0,(pos * 3)+2, 29, 2);
		attrset(COLOR_PAIR(2));
	}
	else {
		attrset(COLOR_PAIR(1));
	}
	mvprintw(1+(pos * 3), 2, data);

	if (isSELECTED == 1) {
		attroff(COLOR_PAIR(2));
	}
	else {
		attroff(COLOR_PAIR(1));
	}
	refresh();
}

void V_SET_MENU_LIST(char** data, int size, int selectedID) {
	DRAW_RACT_COLORD(0, 0, MAX_Y, 29, 1);
	for (int i = 0; i < size; i++) {
		if (i == selectedID) {
			V_ADD_MENU_ITEM(i, data[i], 1);
		}
		else {
			V_ADD_MENU_ITEM(i, data[i], 0);
		}
	}
}

void V_SET_MENU_COLORPAIR() {
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_CYAN);
	init_pair(2, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
}

int V_SET_MENU_CLICKLISTENER(int menuSize){
	int mx, my;
	LISTEN_MOUSE_CLICK(&mx,&my);
	if (mx<29 && 0 <= ((my)/3) && ((my) / 3) < menuSize  ) {
		return ((my) / 3);
	}
	return -1;
}