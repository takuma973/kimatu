#include <stdio.h>
#include <curses.h>

void draw_RPG() {	//RPG‚Ì•`‰æ
	int i, j;
	int x = 53;
	int y = 8;
	//R‚Ì•`‰æ
	for (i = 0; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");

	x = x + 1;
	y = y + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 3, x, " ");

	//P‚Ì•`‰æ
	x = x + 2;
	y = y - 1;
	for (i = 0; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");

	for (i = 0; i < 3; i++) {
		mvaddstr(y + i, x, " ");
	}

	//G‚Ì•`‰æ
	x = x + 2;
	for (i = 1; i < 4; i++) {
		mvaddstr(y + i, x, " ");
	}

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 4, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 4, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	for (i = 2; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}
	refresh();
}

void draw_GAMEOVER() {	//GAMEOVER‚Ì•`‰æ
	int x, y, i, j;
	x = 40, y = 8;
	//G‚Ì•`‰æ
	for (i = 1; i < 4; i++) {
		mvaddstr(y + i, x, " ");
	}

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 4, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 4, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	for (i = 2; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	//A‚Ì•`‰æ
	x = x + 2;
	for (i = 1; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");

	x = x + 1;
	for (i = 1; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	//M‚Ì•`‰æ
	x = x + 2;
	for (i = 0; i < 5; i++) {
		mvaddstr(y + i, x, " ");
		mvaddstr(y + i, x + 4, " ");
	}

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y, x + 2, " ");

	x = x + 1;
	for (i = 1; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	//E‚Ì•`‰æ
	x = x + 4;
	for (i = 0; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 4, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 4, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 4, x, " ");

	//O‚Ì•`‰æ
	x = x + 2;
	for (i = 1; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 4, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 4, x, " ");

	x = x + 1;
	for (i = 0; i < 4; i++) {
		mvaddstr(y + i, x, " ");
	}

	//V‚Ì•`‰æ
	x = x + 2;
	for (i = 0; i < 4; i++) {
		mvaddstr(y + i, x, " ");
		mvaddstr(y + i, x + 3, " ");
	}

	x = x + 1;
	mvaddstr(y + 4, x, " ");
	mvaddstr(y + 4, x + 1, " ");

	//E‚Ì•`‰æ
	x = x + 4;
	for (i = 0; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 4, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 4, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 4, x, " ");

	//R‚Ì•`‰æ
	x = x + 2;
	for (i = 0; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");

	x = x + 1;
	y = y + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 3, x, " ");

	refresh();
}

void draw_GMAECLEAR() {	//GAMECLEAR‚Ì•`‰æ
	int x, y, i, j;
	x = 38, y = 8;
	//G‚Ì•`‰æ
	for (i = 1; i < 4; i++) {
		mvaddstr(y + i, x, " ");
	}

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 4, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 4, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	for (i = 2; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	//A‚Ì•`‰æ
	x = x + 2;
	for (i = 1; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");

	x = x + 1;
	for (i = 1; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	//M‚Ì•`‰æ
	x = x + 2;
	for (i = 0; i < 5; i++) {
		mvaddstr(y + i, x, " ");
		mvaddstr(y + i, x + 4, " ");
	}

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y, x + 2, " ");

	x = x + 1;
	for (i = 1; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	//E‚Ì•`‰æ
	x = x + 4;
	for (i = 0; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 4, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 4, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 4, x, " ");

	//C‚Ì•`‰æ
	x = x + 2;
	for (i = 1; i < 4; i++) {
		mvaddstr(y + i, x, " ");
	}

	x = x + 1;
	for (i = 0; i < 3; i++) {
		mvaddstr(y, x + i, " ");
		mvaddstr(y + 4, x + i, " ");
	}

	//L‚Ì•`‰æ
	x = x + 4;
	for (i = 0; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	x = x + 1;
	for (i = 0; i < 3; i++) {
		mvaddstr(y + 4, x + i, " ");
	}

	//E‚Ì•`‰æ
	x = x + 4;
	for (i = 0; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 4, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 4, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 4, x, " ");

	//R‚Ì•`‰æ
	x = x + 2;
	for (i = 0; i < 5; i++) {
		mvaddstr(y + i, x, " ");
	}

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");

	x = x + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");

	x = x + 1;
	y = y + 1;
	mvaddstr(y, x, " ");
	mvaddstr(y + 2, x, " ");
	mvaddstr(y + 3, x, " ");
	refresh();
}

void draw_monster() {	//“G‚Ì•`‰æ
	int x, y, i;
	x = 60, y = 8;
	for (i = 0; i < 2; i++) {
		y = y + 1;
		mvaddstr(y, x, " ");
	}

	for (i = -1; i < 2; i++) {
		mvaddstr(y, x + i, " ");
	}
	y = y + 1;

	for (i = -2; i < 3; i++) {
		mvaddstr(y, x + i, " ");
	}
	y = y + 1;

	for (i = -3; i < 4; i++) {
		mvaddstr(y, x + i, " ");
	}
	y = y + 1;


	for (i = -4; i < 5; i++) {
		mvaddstr(y, x + i, " ");
	}
	y = y + 1;

	for (i = -4; i < 5; i++) {
		mvaddstr(y, x + i, " ");
	}
	y = y + 1;

	for (i = -4; i < 5; i++) {
		mvaddstr(y, x + i, " ");
	}
	y = y + 1;

	attrset(COLOR_PAIR(2));
	mvaddstr(13, 59, " ");
	mvaddstr(13, 61, " ");
	mvaddstr(15, 60, " ");
}