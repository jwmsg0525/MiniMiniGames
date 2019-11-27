#pragma once


#ifndef __MODEL_BASEBALL__
#define __MODEL_BASEBALL__

typedef struct S_BASEBALL_GAME {
	int randomNums[4];
	int tryCnt;
	int outCnt;
	int gamestat; // 0: NOWRUNNING, -1: LOSE, 1: WIN
}S_BASEBALL_GAME;

typedef struct S_BASEBALL_RECVSTAT {
	int isERR : 1;
	int isOUT : 1;
	int STRIKE : 3;
	int BALL : 3;
}S_BASEBALL_RECVSTAT;

S_BASEBALL_GAME* F_BASEBALL_NEWGAME();
S_BASEBALL_RECVSTAT* F_BASEBALL_NEWSTAT();
void F_BASEBALL_CHECK_CORRECT( S_BASEBALL_GAME* gameboard, S_BASEBALL_RECVSTAT* stat,  char * input);
void F_BASEBALL_ENDSTAT(S_BASEBALL_RECVSTAT* stat);
void F_BASEBALL_ENDGAME(S_BASEBALL_GAME* gamebard);
int F_BASEBALL_CHECK_INPUT(char* input);

#endif // __MODEL_BASEBALL__