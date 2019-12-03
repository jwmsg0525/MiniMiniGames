#include <curses.h>
#include "view_baseball.h"


void V_SET_BASEBALL_VIEW() {
	INIT_PAGE();

	V_SET_BASEBALL_COLORPAIR();
	DRAW_RACT_COLORD(0, MAX_X - 30, MAX_Y, MAX_X, 7);
	V_SET_BASEBALL_BOARD(4);
	
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

void V_SET_BASEBALL_BOARD(int minesizeX) {
	int initx = 9, inity = 3;
	for (int j = 0; j < minesizeX; j++) {
		int setx = initx + (j * 23);
		int sety = inity + (0 * 15);
		DRAW_RACT_COLORD(sety, setx, sety + 13, setx + 20, 7);
	}
	refresh();
}

void V_SET_BASEBALL_NUM(int pos, int key, int cpair) {

	char data[10][14][20] = {
		{
			"###################",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"###################"
			
		},
		{
			"         ##        ",
			"       ####        ",
			"     ##  ##        ",
			"         ##        ",
			"         ##        ",
			"         ##        ",
			"         ##        ",
			"         ##        ",
			"         ##        ",
			"         ##        ",
			"         ##        ",
			"         ##        ",
			"         ##        ",
			"      ########     "
		},
		{
			"###################",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"###################",
			"##                 ",
			"##                 ",
			"##                 ",
			"##                 ",
			"##                 ",
			"###################"
		},
		{
			"###################",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"###################",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"###################"
		},
		{
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"###################",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##"
		},
		{
			"###################",
			"##                 ",
			"##                 ",
			"##                 ",
			"##                 ",
			"##                 ",
			"##                 ",
			"###################",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"###################"
		},
		{
			"###################",
			"##                 ",
			"##                 ",
			"##                 ",
			"##                 ",
			"##                 ",
			"##                 ",
			"###################",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"###################"
		},
		{
			"###################",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##"
		},
		{
			"###################",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"###################",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"###################"
		},
		{
			"###################",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"##               ##",
			"###################",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"                 ##",
			"###################"
		},
	};

	int initx = 9, inity = 3;
	int setx = initx + (pos * 23);
	int sety = inity + (0 * 15);
	DRAW_RACT_COLORD(sety, setx, sety + 13, setx + 20, cpair);
	attrset(COLOR_PAIR(cpair));
	for (int i = 0; i < 14; i++) {
		mvprintw(i+sety, setx+1, data[key][i]);
	}
	attroff(COLOR_PAIR(cpair));
	refresh();


}


void V_SET_BASEBALL_CHECKER(int isOut, char* ball, int strike ) {
	DRAW_RACT_COLORD(MAX_Y-20, 33, MAX_Y - 10, 75, 3);
	if (!isOut) {
		mvprintw(MAX_Y - 19, 34, "              ");
		mvprintw(MAX_Y - 18, 34, "BALL   :      ");
		mvprintw(MAX_Y - 17, 34, "STRIKE :      ");
		mvprintw(MAX_Y - 18, 43, ball);
		mvprintw(MAX_Y - 17, 43, strike);
		mvprintw(MAX_Y - 16, 34, "              ");
	}
	else {
		mvprintw(MAX_Y - 19, 34, "              ");
		mvprintw(MAX_Y - 18, 34, "     OUT      ");
		mvprintw(MAX_Y - 17, 34, "              ");
		mvprintw(MAX_Y - 16, 34, "              ");
	}
	
}

void V_SET_BASEBALL_STATUS(char* count) {
	DRAW_RACT_COLORD(5, MAX_X - 29, 5, MAX_X - 1, 1);
	mvprintw(5, MAX_X - 29, "COUNT: ");
	mvprintw(5, MAX_X - 22, count);
}
int V_SET_BASEBALL_EXITVIEW() {
	DRAW_RACT_COLORD(((MAX_Y - 8) / 2), (MAX_X - 40) / 2, ((MAX_Y - 8) / 2) + 8, ((MAX_X - 40) / 2) + 40, 2);
	mvprintw(((MAX_Y - 8) / 2) + 2, ((MAX_X - 40) / 2) + 16, "GAMEOVER");

	int x, y;
	LISTEN_MOUSE_CLICK(&x, &y);

	return 0;
}