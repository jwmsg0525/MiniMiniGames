#include "controller_menu.h"
#include "view_menu.h"

#include "controller_mineboom.h"
#include "controller_baseball.h"
#include "controller_game2048.h"

void F_MENU_RUN() {
	V_SET_MENU_VIEW();
	int selected = 0;
	while (1) {
		selected = F_MENU_SET_ITEMS(selected);
		switch (selected)
		{
		case 0:
			F_MINEBOOM_RUN();
			break;

		case 1:
			F_BASEBALL_RUN();
			break;
		case 2:
			F_GAME2048_RUN();
		case 3:
		case 4:
		default:
			break;
		}
		V_SET_MENU_VIEW();
	};
}


int F_MENU_SET_ITEMS(int selectedID) {
	char* data[] = { 
					"MINE BOOM",
					"BASE BALL",
					"GAME 2048",
					"VIEW RANK",
					"EXIT GAME"
					};
	V_SET_MENU_LIST(data, sizeof(data) / sizeof(char**), selectedID);
	return V_SET_MENU_CLICKLISTENER(sizeof(data) / sizeof(char**));
}
