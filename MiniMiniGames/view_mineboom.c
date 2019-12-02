#include <curses.h>

#include "view_mineboom.h"

void V_SET_MINEBOOM_VIEW() {
	INIT_PAGE();
	V_SET_MINEBOOM_COLORPAIR();
	DRAW_RACT_COLORD(0, 0, MAX_Y,MAX_X,1);
	DRAW_RACT_COLORD(0, MAX_X-30, MAX_Y, MAX_X, 5);
	V_SET_MINEBOOM_BOARD(10,10);
	V_SET_MINEBOOM_STATUS("0","0");
}
void V_SET_MINEBOOM_COLORPAIR() {
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK); // GAMEBOARD
	init_pair(2, COLOR_WHITE, COLOR_RED); // MINE
	init_pair(3, COLOR_WHITE, COLOR_CYAN); // I Dont Know
	init_pair(4, COLOR_WHITE, COLOR_MAGENTA); // I THINK It is MINE
	init_pair(5, COLOR_BLACK, COLOR_WHITE); //STATUS PANNEL
	init_pair(6, COLOR_GREEN, COLOR_GREEN); //DEFAULT CELL;
	init_pair(7, COLOR_BLACK, COLOR_YELLOW); //OPEND CELL;
}

void V_SET_MINEBOOM_BOARD(int minesizeX, int minesizeY) {
	int initx=22, inity=1;
	for (int i = 0; i < minesizeY; i++) {
		for (int j = 0; j < minesizeX; j++) {
			int setx = initx + (j * 7);
			int sety = inity + (i * 4);
			DRAW_RACT_COLORD(sety, setx, sety+2, setx+4, 6);
		}
	}
	refresh();
}

void V_SET_MINEBOOM_CELLSTATUS(int x, int y, char * c, int color) {
	int initx = 22, inity = 1;
	int setx = initx + (x * 7);
	int sety = inity + (y * 4);
	DRAW_RACT_COLORD(sety, setx, sety + 2, setx + 4, color);
	attrset(COLOR_PAIR(color));
	mvprintw(sety + 1, setx + 2, c);
	attroff(COLOR_PAIR(color));
}

void V_SET_MINEBOOM_CLICK(int *x, int *y, int *clickinfo, int *input) {
	MEVENT mouseinput;
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
	*input = wgetch(stdscr);
	nc_getmouse(&mouseinput); // nc_ is for NCurses compatability, I guess.
	// Aparently moving the mouse isn't a KEY_MOUSE event
	*x = mouseinput.x;
	*y = mouseinput.y;
	if (mouseinput.bstate & BUTTON1_CLICKED) 
		*clickinfo = -1;
	else if (mouseinput.bstate & BUTTON3_CLICKED)
		*clickinfo = 1;
	else
		*clickinfo = 0;
}

void V_SET_MINEBOOM_STATUS(char* time, char* finds) {
	DRAW_RACT_COLORD(5, MAX_X - 29, 6, MAX_X - 1, 1);
	mvprintw(5, MAX_X - 29, "TIME : ");
	mvprintw(6, MAX_X - 29, "MINE : ");
	mvprintw(5, MAX_X - 22, time);
	mvprintw(6, MAX_X - 22, finds);
}

int V_SET_MINEBOOM_EXITVIEW() {
	DRAW_RACT_COLORD(((MAX_Y-8)/2), (MAX_X-40)/2, ((MAX_Y - 8) / 2)+8,((MAX_X - 40) / 2)+40, 2);
	mvprintw(((MAX_Y - 8) / 2)+2, ((MAX_X - 40) / 2 )+16, "GAMEOVER");

	int x, y;
	LISTEN_MOUSE_CLICK(&x, &y);

	return 0;
}