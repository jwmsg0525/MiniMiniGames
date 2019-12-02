#include <curses.h>

#include "controller_menu.h"
#include "view_menu.h"

#include "controller_mineboom.h"
#include "controller_baseball.h"
#include "controller_game2048.h"

void F_MENU_RUN() {
	V_SET_MENU_VIEW();
	F_MENU_LOOP();
}

int F_MENU_SET_ITEMS(int selectedID) {
	
	
	return 0;
}

void F_MENU_LOOP() {
	int selected = 0;
	char* data[] = {
					"MINE BOOM",
					"BASE BALL",
					"GAME 2048",
					"VIEW RANK",
					"EXIT GAME"
	};
	V_SET_MENU_LIST(data, sizeof(data) / sizeof(char**), selected);

	while (1) {
		
		int input;
		int rn = V_SET_MENU_CLICKLISTENER(&input, sizeof(data) / sizeof(char**));
		if (input != KEY_MOUSE) {
			continue;
		}
		if (rn == -1){
			continue;
		}
		selected = rn;
		V_SET_MENU_LIST(data, sizeof(data) / sizeof(char**), selected);

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
			return ;
		default:
			break;
		}

		V_SET_MENU_VIEW();
		V_SET_MENU_LIST(data, sizeof(data) / sizeof(char**), selected);
	};
}