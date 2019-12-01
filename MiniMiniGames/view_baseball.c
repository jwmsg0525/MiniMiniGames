#include <curses.h>
#include "view_baseball.h"

void V_SET_BASEBALL_VIEW() {
	INIT_PAGE();
	V_SET_BASEBALL_COLORPAIR();
	V_SET_BASEBAL_BOARD(4, 4);
	DRAW_RACT_COLORD(0, MAX_X - 30, MAX_Y, MAX_X, 7);
	int x, y;
	LISTEN_MOUSE_CLICK(&x, &y);
}

void V_SET_BASEBALL_COLORPAIR() {
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK); // GAMEBOARD
	init_pair(2, COLOR_WHITE, COLOR_GREEN); //LV1
	init_pair(3, COLOR_WHITE, COLOR_CYAN); // LV2
	init_pair(4, COLOR_WHITE, COLOR_YELLOW); // LV3
	init_pair(5, COLOR_WHITE, COLOR_MAGENTA); //LV4
	init_pair(7, COLOR_BLACK, COLOR_WHITE); // 0
}

void V_SET_BASEBAL_BOARD(int minesizeX) {
	int initx = 9, inity = 3;
	for (int j = 0; j < minesizeX; j++) {
		int setx = initx + (j * 23);
		int sety = inity + (0 * 15);
		DRAW_RACT_COLORD(sety, setx, sety + 13, setx + 20, 7);
	}
	refresh();
}

void V_SET_BASEBALL_NUM(int pos, int key) {

	char data[10][14][22] = {
		{
			"#####################",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"#####################",
			
		},
		{
			"          ##         ",
			"        ####         ",
			"      ##  ##         ",
			"          ##         ",
			"          ##         ",
			"          ##         ",
			"          ##         ",
			"          ##         ",
			"          ##         ",
			"          ##         ",
			"          ##         ",
			"          ##         ",
			"          ##         ",
			"       ########      ",
		},
		{
			"#####################",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"#####################",
			"##                   ",
			"##                   ",
			"##                   ",
			"##                   ",
			"##                   ",
			"#####################",
		},
		{
			"#####################",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"#####################",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"#####################",
		},
		{
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"#####################",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
		},
		{
			"#####################",
			"##                   ",
			"##                   ",
			"##                   ",
			"##                   ",
			"##                   ",
			"##                   ",
			"#####################",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"#####################",
		},
		{
			"#####################",
			"##                   ",
			"##                   ",
			"##                   ",
			"##                   ",
			"##                   ",
			"##                   ",
			"#####################",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"#####################",
		},
		{
			"#####################",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
		},
		{
			"#####################",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"#####################",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"#####################",
		},
		{
			"#####################",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"##                 ##",
			"#####################",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"                   ##",
			"#####################",
		},

	};


}