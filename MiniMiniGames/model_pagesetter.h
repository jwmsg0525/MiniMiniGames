#pragma once

#ifndef __MODEL_PAGESETTER__
#define __MODEL_PAGESETTER__

void INIT_PAGE();
void DRAW_RACT(int y1, int x1, int y2, int x2);
void DRAW_RACT_COLORD(int y1, int x1, int y2, int x2, int colorpair);
void DRAW_LINE_COL(int y1, int x1, int size);
void DRAW_TEXT_COL_CENTER(int y, char* set[], int row);
void DRAW_TEXT_COL_LEFT(int y, char* set[], int row);
void DRAW_TEXT_COL_RIGHT(int y, char* set[], int row);
int LISTEN_MOUSE_CLICK(int* mouse_x, int* mouse_y);


#endif // !__MODULE_PAGESETTER__
