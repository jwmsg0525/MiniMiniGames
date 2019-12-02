#pragma once
#include "preference_page.h"
#include "model_pagesetter.h"

#ifndef __VIEW_MINEBOOM__
#define __VIEW_MINEBOOM__

void V_SET_MINEBOOM_VIEW();
void V_SET_MINEBOOM_COLORPAIR();
void V_SET_MINEBOOM_BOARD(int minesizeX, int minesizeY);
void V_SET_MINEBOOM_CELLSTATUS(int x, int y, char* c, int color);
void V_SET_MINEBOOM_CLICK(int* x, int* y, int* clickinfo, int* input);
void V_SET_MINEBOOM_STATUS(char* time, char* finds);

#endif // !__VIEW_MINEBOOM__
