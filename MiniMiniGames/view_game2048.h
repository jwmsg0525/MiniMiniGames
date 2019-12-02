#pragma once
#include "preference_page.h"
#include "model_pagesetter.h"

#ifndef __VIEW_GAME2048_
#define __VIEW_GAME2048_

void V_SET_GAME2048_VIEW();
void V_SET_GAME2048_COLORPAIR();
void V_SET_GAME2048_BOARD(int minesizeX, int minesizeY);
void V_SET_GAME2048_ITEM(int X, int Y, char* data, int chrsize, int colorpair);
void V_SET_GAME2048_STATUS(char* time, char* point);
int V_SET_GAME2048_EXITVIEW();


#endif // !__VIEW_GAME2048_
