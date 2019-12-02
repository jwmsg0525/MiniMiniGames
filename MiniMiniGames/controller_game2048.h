#pragma once
#include "model_game2048.h"
#include <stdint.h>

#ifndef __CONTROLLER_GAME2048__
#define __CONTROLLER_GAME2048__

void F_GAME2048_RUN();
void F_GAME2048_UPDATE(S_GAME2048_BOARD* board);
void F_GAME2048_KBDLISTEN(S_GAME2048_BOARD* board, int64_t now);

//#define KEY_LEFT 75
//#define KEY_RIGHT 77
//#define KEY_UP 72
//#define KEY_DOWN 80

#endif // !__CONTROLLER_GAME2048__
