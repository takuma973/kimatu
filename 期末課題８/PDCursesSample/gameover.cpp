#include <stdio.h>
#include <curses.h>
#include "word.h"

void draw_gameover(int* titleFlag) {	//�Q�[���I�[�o�[��ʂ̕`��
	int key;
	clear();
	attrset(COLOR_PAIR(9));
	draw_GAMEOVER();

	attrset(COLOR_PAIR(1));
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