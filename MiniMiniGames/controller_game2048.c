#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "controller_game2048.h"
#include "view_game2048.h"
#include "model_game2048.h"


void F_GAME2048_RUN() {
	V_SET_GAME2048_VIEW();
	S_GAME2048_BOARD* board = F_GAME2048_NEWGAME();
	F_GAME2048_UPDATE(board);
	F_GAME2048_KBDLISTEN(board);
}
void F_GAME2048_UPDATE(S_GAME2048_BOARD * board) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			char buff[16];
			int dt = board->board[i][j];
			itoa(dt, buff, 10);
			int c = 0;
			switch (dt) {
			case 0:
				c = 12;
				break;
			case 2:
				c = 2;
				break;
			case 4:
				c = 3;
				break;
			case 8:
				c = 4;
				break;
			case 16:
				c = 5;
				break;
			case 32:
				c = 6;
				break;
			case 64:
				c = 7;
				break;
			case 128:
				c = 8;
				break;
			case 256:
				c = 9;
				break;
			case 512:
				c = 10;
				break;
			default:
				c = 11;
				break;
			}
			V_SET_GAME2048_ITEM(j,i,buff,strlen(buff),c);
		}
	}
}

void F_GAME2048_KBDLISTEN(S_GAME2048_BOARD* board) {
	while (!board->gameover) {
		char c = getch();
		if (c == KEY_LEFT) {
			F_GAME2048_MOVE_LEFT(board);
		}
		else if (c == KEY_RIGHT) {
			F_GAME2048_MOVE_RIGHT(board);
		}
		else if (c == KEY_UP) {
			F_GAME2048_MOVE_UP(board);
		}
		else if (c == KEY_DOWN) {
			F_GAME2048_MOVE_DOWN(board);
		}

		F_GAME2048_CHECK_GAMEOVER(board);

		if (!F_GAME2048_ALLSTACKFULL(board)) {
			F_GAME2048_NEWRANDOM(board);
		}

		F_GAME2048_UPDATE(board);
		
	}
}