#include <curses.h>
#include "model_pagesetter.h"
#include "preference_page.h"


void INIT_PAGE() {
	clear();
	initscr();
	resize_term(TOTAL_VIEW_ROW, TOTAL_VIEW_COL);
	raw(); nodelay(stdscr, 1); noecho(); curs_set(0); nonl(); keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS, NULL);
}

void DRAW_RACT(int y1, int x1, int y2, int x2)
{
	mvhline(y1, x1, 0, x2 - x1);
	mvhline(y2, x1, 0, x2 - x1);
	mvvline(y1, x1, 0, y2 - y1);
	mvvline(y1, x2, 0, y2 - y1);
	mvaddch(y1, x1, ACS_ULCORNER);
	mvaddch(y2, x1, ACS_LLCORNER);
	mvaddch(y1, x2, ACS_URCORNER);
	mvaddch(y2, x2, ACS_LRCORNER);
}

void DRAW_LINE_COL(int y1, int x1, int size) {
	mvhline(y1, x1, 0, size);
}

void DRAW_TEXT_COL_CENTER(int y, char* set[], int row) {
	for (int i = 0; i < row; i++) {
		int total_len = 0;
		char* text = set[i];
		while (*text != 0) {
			total_len++;
			text++;
		}
		mvprintw(y + i, (MAX_X - total_len) / 2 + 1, "%s", set[i]);
	}
	refresh();
}

void DRAW_TEXT_COL_LEFT(int y, char* set[], int row) {
	for (int i = 0; i < row; i++) {
		int total_len = 0;
		char* text = set[i];
		while (*text != 0) {
			total_len++;
			text++;
		}
		mvprintw(y + i, MIN_X, "%s", set[i]);
	}
	refresh();
}

void DRAW_TEXT_COL_RIGHT(int y, char* set[], int row) {
	for (int i = 0; i < row; i++) {
		int total_len = 0;
		char* text = set[i];
		while (*text != 0) {
			total_len++;
			text++;
		}
		mvprintw(y + i, (MAX_X - total_len), "%s", set[i]);
	}
	refresh();
}

void DRAW_RACT_COLORD(int y1, int x1, int y2, int x2, int colorpair) {
	attrset(COLOR_PAIR(colorpair));
	for (int y = y1; y <= y2; y++) {
		for (int x = x1; x <= x2; x++) {
			mvprintw(y, x, " ");
		}
	}
	attroff(COLOR_PAIR(colorpair));
}

int LISTEN_MOUSE_CLICK(int* mouse_x, int* mouse_y) {
	int input;
	MEVENT mouseinput;

	do { // A nasty 100% resource hogging loop, I know. Sorry about that.
		input = wgetch(stdscr);
		nc_getmouse(&mouseinput); // nc_ is for NCurses compatability, I guess.
		// Aparently moving the mouse isn't a KEY_MOUSE event
		*mouse_x = mouseinput.x;
		*mouse_y = mouseinput.y;
	} while (input != KEY_MOUSE);
	//https://stackoverflow.com/questions/11301883/using-ncurses-to-capture-mouse-clicks-on-a-console-application
	return 0;
}
