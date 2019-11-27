#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <Windows.h>

#include "model_mineboom.h"

void F_MINEBOOM_PRINTCELL(S_MINEBOOM_BOARD* board) {
	for (int i = 0; i < board->X_MAX; i++) {
		for (int j = 0; j < board->Y_MAX; j++) {
			printf("[%2d ] ", board->gameboard[i][j]->num);
		}
		printf("\n");
	}
}
void F_MINEBOOM_PRINTCELL_S(S_MINEBOOM_BOARD* board) {
	for (int i = 0; i < board->X_MAX; i++) {
		for (int j = 0; j < board->Y_MAX; j++) {
			if (board->gameboard[i][j]->opend) {
				printf("[%2d ] ", board->gameboard[i][j]->num);
			}
			else {
				printf("[   ] ");
			}

		}
		printf("\n");
	}
}
int F_MINEBOOM_CLICKCELL(S_MINEBOOM_BOARD* board, int posX, int posY) {
	if (!((0 <= posX) &&
		(posX < board->X_MAX) &&
		(0 <= posY) &&
		(posY < board->Y_MAX)
		))
		return 0;

	if (!board->gameboard[posX][posY]->opend) {

		if (board->gameboard[posX][posY]->num == -1) {
			return -1;

		}
		else {
			board->gameboard[posX][posY]->opend = 1;
		}

		if (board->gameboard[posX][posY]->num) {
			return 0;
		}

		F_MINEBOOM_CLICKCELL(board, posX - 1, posY);
		F_MINEBOOM_CLICKCELL(board, posX + 1, posY);
		F_MINEBOOM_CLICKCELL(board, posX, posY - 1);
		F_MINEBOOM_CLICKCELL(board, posX, posY + 1);

		return 0;
	}
	else {
		return 1;
	}
	return 0;
}
void F_MINEBOOM_RANDOM(S_MINEBOOM_BOARD* board, int mines) {
	srand(time(NULL));

	for (int i = 0; i < mines; i++) {

		int x = rand() % board->X_MAX;
		int y = rand() % board->Y_MAX;

		if (board->gameboard[x][y]->num == -1) {
			i--;
			continue;
		}

		//지뢰할당.
		board->gameboard[x][y]->num = -1;

		//지뢰 주변 가중치 처리
		for (int nx = -1; nx <= 1; nx++) {
			for (int ny = -1; ny <= 1; ny++)
			{
				int nnx = x - nx;
				int nny = y - ny;
				if ((0 <= nnx) &&
					(nnx < board->X_MAX) &&
					(0 <= nny) &&
					(nny < board->Y_MAX))
					if (board->gameboard[nnx][nny]->num != -1)
						board->gameboard[nnx][nny]->num += 1;
			}
		}

	}
}
S_MINEBOOM_BOARD* F_MINEBOOM_NEWGAME(int X_MAX, int Y_MAX) {

	S_MINEBOOM_BOARD* board = malloc(sizeof(S_MINEBOOM_BOARD));

	if(board == NULL){
		board = F_MINEBOOM_NEWGAME(X_MAX, Y_MAX);
	}

	board->X_MAX = X_MAX;
	board->Y_MAX = Y_MAX;

	board->gameboard = malloc(sizeof(S_MINEBOOM_CELL**) * X_MAX);

	S_MINEBOOM_CELL*** prtn = board->gameboard;

	for (int i = 0; i < X_MAX; i++) {
		S_MINEBOOM_CELL** celline = malloc(sizeof(S_MINEBOOM_CELL*) * Y_MAX);
		S_MINEBOOM_CELL** pCelline = celline;
		if(celline == NULL || pCelline == NULL){
			i--; continue;
		}
		for (int j = 0; j < Y_MAX; j++) {
			S_MINEBOOM_CELL* cell = malloc(sizeof(S_MINEBOOM_CELL));
			if (cell == NULL) {
				j--; continue;
			}
			cell->num = 0;
			cell->opend = 0;
			*pCelline = cell;
			pCelline++;
		}
		*prtn = celline;
		prtn++;
	}

	return board;
}
void F_MINEBOOM_DELGAME(S_MINEBOOM_BOARD* board) {
	for (int i = 0; i < board->X_MAX; i++) {
		for (int j = 0; j < board->Y_MAX; j++) {
			free(board->gameboard[i][j]);
		}
		free(board->gameboard[i]);
	}
	free(board->gameboard);
	free(board);
}
//int main() {
//
//	BOARD* board = newGameBoard(COL, COL);
//	randBOOM(board, 10);
//
//	printHidden(board);
//	clickCell(board, 0, 1);
//
//	system("cls");
//	printHidden(board);
//	delGameBoard(board);
//
//	return 0;
//}