#include <stdio.h>
#include <curses.h>
#include "word.h"

void draw_gameover(int* titleFlag) {	//ゲームオーバー画面の描画
	int key;
	clear();
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	attrset(COLOR_PAIR(1));
	draw_GAMEOVER();

	attrset(COLOR_PAIR(2));
	mvaddstr(16, 45, "残念！またチャレンジしてください！");
	mvaddstr(17, 47, "Zボタンでタイトル画面に戻る");
	refresh();

	while (*titleFlag == 0) {
		key = getch();
		if (key == 'z') {
			*titleFlag = 1;
		}
	}

}