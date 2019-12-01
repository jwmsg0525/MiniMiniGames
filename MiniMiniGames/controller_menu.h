#pragma once

#ifndef __CONTROLLER_MENU__
#define __CONTROLLER_MENU__
void F_MENU_RUN();
int F_MENU_SET_ITEMS(int selectedID);

typedef struct S_MENU_VALUES {
	int selectedID;
}S_MENU_VALUES;


#endif // !__CONTROLLER_MENU__
