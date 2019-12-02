#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)
#include "controller_baseball.h"
#include "view_baseball.h"
#include "model_baseball.h"

void F_BASEBALL_RUN() {
	S_BASEBALL_GAME* gameboard = F_BASEBALL_NEWGAME();
	S_BASEBALL_RECVSTAT* stat = F_BASEBALL_NEWSTAT();
	V_SET_BASEBALL_VIEW();
	while (!gameboard->gamestat) {
		char input[5];
		itoa(F_BASEBALL_INPUT(), input, 10);
		F_BASEBALL_CHECK_CORRECT(gameboard, stat, input);

	}

}

int F_BASEBALL_INPUT() {
	char ch;
	int cnt = 0 , data = 0;
	while (ch = getch()) {
		if ('0' < ch && ch <= '9') {
			if (cnt == 0) {
				V_SET_BASEBALL_BOARD(4);
			}
			V_SET_BASEBALL_NUM(cnt, ch - 0x30, 2);
			cnt++;
			data *= 10;
			data += ch - 0x30;
		}
		if (cnt == 4) {
			break;
		}
	}
	return data;
}