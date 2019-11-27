#pragma warning (disable:4996)
#include <stdio.h>
#include <stdbool.h> // bool, true, false
#include <stdlib.h> // system, exit
#include <time.h> // srand((int)time(NULL))
#include <string.h>

#include "model_baseball.h"

S_BASEBALL_GAME* F_BASEBALL_NEWGAME() {
	S_BASEBALL_GAME* gameboard = malloc(sizeof(S_BASEBALL_GAME));
	gameboard->gamestat = 0;
	gameboard->outCnt = 0;
	gameboard->tryCnt = 0;

	srand(time(NULL));

	for (int i = 0; i < sizeof(gameboard->randomNums) / sizeof(int); i++) {
		int tmp = rand() % 9 + 1;
		int flag = 0;
		for (int j = 0; j <i  / sizeof(int); i++) {
			if (gameboard->randomNums[i] == gameboard->randomNums[j]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			i--;
		}
		else {
			gameboard->randomNums[i] = tmp;
		}
	}

	return gameboard;
}

S_BASEBALL_RECVSTAT* F_BASEBALL_NEWSTAT() {
	S_BASEBALL_RECVSTAT* stat = malloc(sizeof(S_BASEBALL_RECVSTAT));
	stat->BALL = 0;
	stat->isERR = 1;
	stat->isOUT = 0;
	stat->STRIKE = 0;
	return stat;
}

void F_BASEBALL_CHECK_CORRECT(S_BASEBALL_GAME* gameboard, S_BASEBALL_RECVSTAT* stat, char* input) { 
	//input must have 4 string + 1 null string;

	//initial stat	
	stat->BALL = 0;
	stat->isERR = 1;
	stat->isOUT = 0;
	stat->STRIKE = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((input[i]-0x30) == gameboard->randomNums[j]) {
				if (i == j) {
					stat->STRIKE++;
				}
				else {
					stat->BALL++;
				}
			}
		}
	}

	if (stat->STRIKE == 0 && stat->BALL == 0) {
		stat->isOUT = 1;
		gameboard->outCnt++;
	}

	stat->isERR = 0;
	
	gameboard->tryCnt++;
	
}
void F_BASEBALL_ENDSTAT(S_BASEBALL_RECVSTAT* stat) {
	free(stat);
}
void F_BASEBALL_ENDGAME(S_BASEBALL_GAME* gamebard) {
	free(gamebard);
}
int F_BASEBALL_CHECK_INPUT(char* input) {
	int len = strlen(input);
	if (len != 4) {
		return -1;
	}

	for (int i = 0; i < 4; i++) {
		if (!('1' <= input[i] && input[i] <= '9')) {
			return -2;
		}
	}
	return 0;
}