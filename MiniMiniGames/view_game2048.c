#include <curses.h>
#include "view_game2048.h"



void V_SET_GAME2048_VIEW() {
	INIT_PAGE();

	V_SET_GAME2048_COLORPAIR();

	DRAW_RACT_COLORD(0, 0, MAX_Y, MAX_X, 1);
	DRAW_RACT_COLORD(0, MAX_X - 30, MAX_Y, MAX_X,12);

	V_SET_GAME2048_BOARD(4, 4);
}

void V_SET_GAME2048_COLORPAIR() {
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK); // GAMEBOARD
	init_pair(2, COLOR_WHITE, COLOR_GREEN); //LV1
	init_pair(3, COLOR_WHITE, COLOR_CYAN); // LV2
	init_pair(4, COLOR_WHITE, COLOR_BLUE); // LV3
	init_pair(5, COLOR_WHITE, COLOR_YELLOW); //LV4
	init_pair(6, COLOR_WHITE, COLOR_MAGENTA); //LV4
	init_pair(7, COLOR_WHITE, COLOR_RED); //LV4
	init_pair(8, COLOR_GREEN, COLOR_WHITE); //LV4
	init_pair(9, COLOR_CYAN, COLOR_WHITE); //LV4
	init_pair(10, COLOR_BLUE, COLOR_WHITE); //LV4
	init_pair(11, COLOR_RED, COLOR_WHITE); // 0
	init_pair(12, COLOR_BLACK, COLOR_WHITE); // 0
}

void V_SET_GAME2048_BOARD(int minesizeX, int minesizeY) {
	int initx = 35, inity = 9;
	for (int i = 0; i < minesizeY; i++) {
		for (int j = 0; j < minesizeX; j++) {
			int setx = initx + (j * 11);
			int sety = inity + (i * 6);
			DRAW_RACT_COLORD(sety, setx, sety + 4, setx + 8, 12);
		}
	}
	refresh();
}

void V_SET_GAME2048_ITEM(int X, int Y,char * data,int chrsize, int colorpair) {
	int initx = 35, inity = 9;
	int setx = initx + (X * 11);
	int sety = inity + (Y * 6);
	DRAW_RACT_COLORD(sety, setx, sety + 4, setx + 8, colorpair);
	attrset(COLOR_PAIR(colorpair));
	mvprintw(sety + 2, setx + (((9) - chrsize) / 2), data);
	attroff(COLOR_PAIR(colorpair));
	refresh();
}