#include <curses.h>
#include "view_main.h"


void V_SET_MAIN_VIEW() {
	INIT_PAGE();
}

void V_VIEW_MAIN_WELCOME() {
	char* main_ASCII[] = {
	"  ********** ********     **     ****     ****        ****   ****   ****   **** ",
	" /////**/// /**/////     ****   /**/**   **/**       */// * *///** */// * */// *",
	"     /**    /**         **//**  /**//** ** /**      /    /*/*  */*/    /*/    /*",
	"     /**    /*******   **  //** /** //***  /**         *** /* * /*   ***    *** ",
	"     /**    /**////   **********/**  //*   /**        *//  /**  /*  *//    *//  ",
	"     /**    /**      /**//////**/**   /    /**       *     /*   /* *      *     ",
	"     /**    /********/**     /**/**        /**      /******/ **** /******/******",
	"     //     //////// //      // //         //       //////  ////  ////// ////// ",

		"",
		"CLICK TO START!",
	};
	DRAW_TEXT_COL_CENTER(MAX_Y - sizeof(main_ASCII) / sizeof(char*), main_ASCII, sizeof(main_ASCII) / sizeof(char*));
	int mx, my;
	LISTEN_MOUSE_CLICK(&mx, &my);
	refresh();
}