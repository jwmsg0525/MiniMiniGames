#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>

#pragma warning (disable:4996)

#include "controller_baseball.h"
#include "view_baseball.h"
#include "model_baseball.h"

void F_BASEBALL_RUN() {
	S_BASEBALL_GAME* gameboard = F_BASEBALL_NEWGAME();
	S_BASEBALL_RECVSTAT* stat = F_BASEBALL_NEWSTAT();

	V_SET_BASEBALL_VIEW();
	F_BASEBALL_LOOP(gameboard, stat);
	V_SET_BASEBALL_EXITVIEW();



}

int F_BASEBALL_INPUT() {
	char ch;
	int cnt = 0 , data = 0;
	
	while (ch = getch()) {
		if ('0' < ch && ch <= '9') {	
			if (cnt == 0) {
				V_SET_BASEBALL_BOARD(4);
			}
			V_SET_BASEBALL_NUM(cnt, ch - 0x30, 3);
			data *= 10;
			data += ch - 0x30;
			cnt++;
			if (cnt == 4) {
				break;
			}
		}
	}
	return data;
}

void F_BASEBALL_LOOP(S_BASEBALL_GAME* gameboard, S_BASEBALL_RECVSTAT* stat) {
	while (!gameboard->gamestat) {
		char input[5];
		itoa(F_BASEBALL_INPUT(), input, 10);
		F_BASEBALL_CHECK_CORRECT(gameboard, stat, input);

		char cball[3];
		itoa(stat->BALL, cball, 10);
		char cstrike[3];
		itoa(stat->STRIKE, cstrike, 10);

		if (stat->STRIKE == 4) {
			gameboard->gamestat = 1;
		}




		V_SET_BASEBALL_CHECKER(stat->isOUT, cball, cstrike);
		char ccount[3];
		itoa(gameboard->tryCnt, ccount, 10);
		V_SET_BASEBALL_STATUS(ccount);
	}
}

