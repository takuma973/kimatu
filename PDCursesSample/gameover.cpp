#include <stdio.h>
#include <curses.h>
#include "word.h"

void draw_gameover(int* titleFlag) {	//�Q�[���I�[�o�[��ʂ̕`��
	int key;
	clear();
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	attrset(COLOR_PAIR(1));
	draw_GAMEOVER();

	attrset(COLOR_PAIR(2));
	mvaddstr(16, 45, "�c�O�I�܂��`�������W���Ă��������I");
	mvaddstr(17, 47, "Z�{�^���Ń^�C�g����ʂɖ߂�");
	refresh();

	while (*titleFlag == 0) {
		key = getch();
		if (key == 'z') {
			*titleFlag = 1;
		}
	}

}