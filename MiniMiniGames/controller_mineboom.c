#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)


#include "controller_mineboom.h"
#include "view_mineboom.h"

void F_MINEBOOM_RUN() {
	V_SET_MINEBOOM_VIEW();
	S_MINEBOOM_BOARD* board = F_MINEBOOM_NEWGAME(_MINEBOOM_COL, _MINEBOOM_COL);
	F_MINEBOOM_RANDOM(board, _MINEBOOM_COL);
	F_MINEBOOM_LOOP_CLICKLISTEN(board);
	
}

void F_MINEBOOM_LOOP_RCLICK(S_MINEBOOM_BOARD* board, int clickx, int clicky) {
	int initx = 22, inity = 1;
	for (int i = 0; i < _MINEBOOM_COL; i++) {
		for (int j = 0; j < _MINEBOOM_COL; j++) {
			int setx = initx + (j * 7);
			int sety = inity + (i * 4);
			if (setx <= clickx && clickx <= setx + 4 && sety <= clicky && clicky <= sety + 2) {
				F_MINEBOOM_CLICKCELL_R(board,j,i);
			}
		}
	}
}

void F_MINEBOOM_LOOP_LCLICK(S_MINEBOOM_BOARD* board, int clickx, int clicky){
	int initx = 22, inity = 1;
	for (int i = 0; i < _MINEBOOM_COL; i++) {
		for (int j = 0; j < _MINEBOOM_COL; j++) {
			int setx = initx + (j * 7);
			int sety = inity + (i * 4);
			if (setx <= clickx && clickx <= setx + 4 && sety <= clicky && clicky <= sety + 2) {
				board->status = F_MINEBOOM_CLICKCELL(board, j, i);
			}
		}
	}
}

void F_MINEBOOM_CELL_UPDATE(S_MINEBOOM_BOARD* board) {
	for (int i = 0; i < _MINEBOOM_COL; i++) {
		for (int j = 0; j < _MINEBOOM_COL; j++) {
			if (board->gameboard[j][i]->opend == 1) {
				if (board->gameboard[j][i]->num != -1) {
					char buff[2];
					itoa(board->gameboard[j][i]->num, buff, 10);
					if (board->gameboard[j][i]->num == 0) {
						buff[0] = ' ';
					}
					V_SET_MINEBOOM_CELLSTATUS(j, i, buff, 7);
				}
				
			}
			else if (board->gameboard[j][i]->opend == 2) {
				V_SET_MINEBOOM_CELLSTATUS(j, i, "?", 3);
			}
			else if (board->gameboard[j][i]->opend == 3) {
				V_SET_MINEBOOM_CELLSTATUS(j, i, "!", 4);
			}
			else if (board->gameboard[j][i]->opend == 0) {
				V_SET_MINEBOOM_CELLSTATUS(j, i, " ", 6);
			}
		}
	}
}

void F_MINEBOOM_LOOP_CLICKLISTEN(S_MINEBOOM_BOARD* board) {
	while (board->status == 0) {
		int x, y, c;
		V_SET_MINEBOOM_CLICK(&x, &y, &c);

		if (c == -1) {
			F_MINEBOOM_LOOP_LCLICK(board, x, y);
		}
		else if (c == 1) {
			F_MINEBOOM_LOOP_RCLICK(board, x, y);
		}
		F_MINEBOOM_CELL_UPDATE(board);
	}
}