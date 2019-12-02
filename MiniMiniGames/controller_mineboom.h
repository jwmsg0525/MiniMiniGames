#pragma once
#include "model_mineboom.h"
#include <stdint.h>

#ifndef __CONTROLLER_MINEBOOM__
#define __CONTROLLER_MINEBOOM__

#define _MINEBOOM_COL 10

void F_MINEBOOM_RUN();
void F_MINEBOOM_CELL_UPDATE(S_MINEBOOM_BOARD* board);
void F_MINEBOOM_LOOP_RCLICK(S_MINEBOOM_BOARD* board, int clickx, int clicky);
void F_MINEBOOM_LOOP_LCLICK(S_MINEBOOM_BOARD* board, int clickx, int clicky);
void F_MINEBOOM_LOOP_CLICKLISTEN(S_MINEBOOM_BOARD* board,int64_t now);
int V_SET_MINEBOOM_EXITVIEW();
int F_MINEBOOM_FINDMINE(S_MINEBOOM_BOARD* board);
#endif // !__CONTROLLER_MINEBOOM__
