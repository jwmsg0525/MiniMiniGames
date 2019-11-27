#pragma once

#ifndef __MODEL_MINEBOOM__
#define __MODEL_MINEBOOM__

typedef struct S_MINEBOOM_CELL {
	int num : 16;
	int opend : 16;
}S_MINEBOOM_CELL;

typedef struct S_MINEBOOM_BOARD {
	S_MINEBOOM_CELL*** gameboard;
	int X_MAX;
	int Y_MAX;
	int status;
}S_MINEBOOM_BOARD;


S_MINEBOOM_BOARD* F_MINEBOOM_NEWGAME(int X_MAX, int Y_MAX);
void F_MINEBOOM_DELGAME(S_MINEBOOM_BOARD* board);
void F_MINEBOOM_RANDOM(S_MINEBOOM_BOARD* board, int mines);
int F_MINEBOOM_CLICKCELL(S_MINEBOOM_BOARD* board, int posX, int posY);
void F_MINEBOOM_PRINTCELL(S_MINEBOOM_BOARD* board);
void F_MINEBOOM_PRINTCELL_S(S_MINEBOOM_BOARD* board);




#endif // !__MODEL_MINEBOOM__
