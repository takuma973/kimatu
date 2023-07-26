#include <stdio.h>
#include <curses.h>
#include <Windows.h>
#include "word.h"

void draw_title(int* startFlag, int* ruleFlag) {	//タイトル画面の描画
	int key;
	int x1 = 58, x2 = 54, y1 = 16, y2 = y1;
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	clear();
	attrset(COLOR_PAIR(1));
	draw_RPG();
	attrset(COLOR_PAIR(2));
	mvaddstr(y2, x2, "→");
	mvaddstr(y1, x1, "play");
	mvaddstr(y1 + 2, x1, "ルール説明");
	refresh();
	while (*startFlag == 0 && *ruleFlag == 0) {
		if(GetKeyState(VK_UP) & 0x80 || GetKeyState(VK_DOWN) & 0x80 || GetKeyState('A') & 0x80){
			key = getch();
			switch (key) {
				case KEY_UP:
					y2 = 16;
					break;
				case KEY_DOWN:
					y2 = 18;
					break;

				case 'a':
					if (y2 == 16) {
						*startFlag = 1;
					}
					else if(y2 == 18) {
						*ruleFlag = 1;
					}
					break;
			}
		}
		clear();
		attrset(COLOR_PAIR(1));
		draw_RPG();
		attrset(COLOR_PAIR(2));
		mvaddstr(y2, x2, "→");
		mvaddstr(y1, x1, "play");
		mvaddstr(y1 + 2, x1, "ルール説明");
		refresh();
	}
}