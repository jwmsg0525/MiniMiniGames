#pragma once
#include "preference_page.h"
#include "model_pagesetter.h"

#ifndef __VIEW_BASEBALL__
#define __VIEW_BASEBALL__

void V_SET_BASEBALL_VIEW();
void V_SET_BASEBALL_COLORPAIR();
void V_SET_BASEBALL_BOARD(int minesizeX);
void V_SET_BASEBALL_NUM(int pos, int key, int cpair);
void V_SET_BASEBALL_CHECKER(int isOut, char* ball, int strike);
void V_SET_BASEBALL_STATUS(char* count);
int V_SET_BASEBALL_EXITVIEW();


#endif // !__VIEW_BASEBALL__
