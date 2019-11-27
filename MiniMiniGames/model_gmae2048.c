#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "model_game2048.h"

S_GAME2048_BOARD* F_GAME2048_NEWGAME() {
	S_GAME2048_BOARD* gameboard = malloc(sizeof(S_GAME2048_BOARD));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			gameboard->board[i][j] = 0;
		}
	}
	gameboard->gameover = 0;
	gameboard->point = 0;

	F_GAME2048_NEWRANDOM(gameboard);
	F_GAME2048_NEWRANDOM(gameboard);

	return gameboard;
}
void F_GAME2048_NEWRANDOM(S_GAME2048_BOARD* gameboard) {
	srand(time(NULL));
	int x = rand() % 4;
	int y = rand() % 4;
	if (gameboard->board[x][y] == 0) 
		gameboard->board[x][y] = 2;
	else 
		F_GAME2048_NEWRANDOM(gameboard);
	
}

void F_GAME2048_MOVE_LEFT(S_GAME2048_BOARD* gameboard) {
	F_GAME2048_ALIGN_LEFT(gameboard);
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 3; k++) {
			if (gameboard->board[i][k] == gameboard->board[i][k + 1]) {
				gameboard->board[i][k] += gameboard->board[i][k + 1];
				gameboard->board[i][k + 1] = 0;
				gameboard->point+= gameboard->board[i][k + 1];
				k++;
			}
		}
	}
	F_GAME2048_ALIGN_LEFT(gameboard);
}
void F_GAME2048_MOVE_RIGHT(S_GAME2048_BOARD* gameboard) {
	F_GAME2048_ALIGN_RIGHT(gameboard);
	for (int i = 0; i < 4; i++) {
		for (int k = 3; k > 0; k--) {
			if (gameboard->board[i][k] == gameboard->board[i][k - 1]) {
				gameboard->board[i][k] += gameboard->board[i][k - 1];
				gameboard->board[i][k - 1] = 0;
				gameboard->point += gameboard->board[i][k - 1];
				k--;
			}
		}
	}
}

void F_GAME2048_MOVE_UP(S_GAME2048_BOARD* gameboard);
void F_GAME2048_MOVE_DOWN(S_GAME2048_BOARD* gameboard);

void F_GAME2048_ALIGN_LEFT(S_GAME2048_BOARD* gameboard) { // move Zero cells to right side
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (gameboard->board[i][k] == 0) {
					gameboard->board[i][k] = gameboard->board[i][k + 1];
					gameboard->board[i][k + 1] = 0;
				}
			}
		}
	}
}

void F_GAME2048_ALIGN_RIGHT(S_GAME2048_BOARD* gameboard) {// move Zero cells to left side
	for (int i = 0; i < 4; i++) {
		for (int j = 3; j > 0; j--) {
			for (int k = 3; k > 0; k--) {
				if (gameboard->board[i][k] == 0) {
					gameboard->board[i][k] = gameboard->board[i][k - 1];
					gameboard->board[i][k + 1] = 0;
				}
			}
		}
	}
}

void F_GAME2048_ALIGN_UP(S_GAME2048_BOARD* gameboard) { // move Zero cells to down side
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (gameboard->board[k][i] == 0) {
					gameboard->board[k][i] = gameboard->board[k+1][i];
					gameboard->board[k + 1][i] = 0;
				}
			}
		}
	}
}

void F_GAME2048_ALIGN_DOWN(S_GAME2048_BOARD* gameboard) { // move Zero cells to up side
	for (int i = 0; i < 4; i++) {
		for (int j = 3; j > 0; j--) {
			for (int k = 3; k > 0; k--) {
				if (gameboard->board[k][i] == 0) {
					gameboard->board[k][i] = gameboard->board[k - 1][i];
					gameboard->board[k - 1][i] = 0;
				}
			}
		}
	}
}

void F_GAME2048_CHECK_GAMEOVER(S_GAME2048_BOARD* gameboard);

