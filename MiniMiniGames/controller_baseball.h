#pragma once
#include "model_baseball.h"

#ifndef __CONTROLLER_BASEBALL__
#define __CONTROLLER_BASEBALL__

void F_BASEBALL_RUN();
int F_BASEBALL_INPUT();
void F_BASEBALL_LOOP(S_BASEBALL_GAME* gameboard, S_BASEBALL_RECVSTAT* stat);

#endif // !__CONTROLLER_BASEBALL__
