#pragma once
#include "preference_page.h"
#include "model_pagesetter.h"

#ifndef __VIEW_MENU__
#define __VIEW_MENU__

void V_SET_MENU_VIEW();
void V_ADD_MENU_ITEM(int pos, char* data, int isSELECTED);
void V_SET_MENU_LIST(char** data, int size, int selectedID);
void V_SET_MENU_COLORPAIR();
int V_SET_MENU_CLICKLISTENER(int* input, int menuSize);

#endif // !__VIEW_MENU__
