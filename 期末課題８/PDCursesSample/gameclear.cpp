#include <stdio.h>
#include <curses.h>
#include <time.h>
#include <stdlib.h>
#include "word.h"

#define BUFFSIZE 1024

void draw_gameclear(int* titleFlag, time_t starttime, time_t finishtime) {	//�N���A��ʂ̕`��
	int key, score[4], minutes, seconds, j, tmp;
	int i = 0;
	char str[100];
	FILE* fp;
	char s[BUFFSIZE];
	errno_t error;

	clear();
	attrset(COLOR_PAIR(9));
	draw_GMAECLEAR();

	attrset(COLOR_PAIR(1));
	sprintf_s(str, "���Ȃ��̃N���A�^�C���� %d���@%d�b�ł�", (int)difftime(finishtime, starttime) / 60, (int)difftime(finishtime, starttime) % 60);
	mvaddstr(16, 43, "���߂łƂ��I�Q�[���N���A�ł��I");
	mvaddstr(17, 43, str);
	mvaddstr(18, 45, "Z�{�^���Ń^�C�g����ʂɖ߂�");

	//csv�t�@�C���̓ǂݍ���
	error = fopen_s(&fp, "ranking.csv", "r");
	if (error != 0) {
		fprintf_s(stderr, "failed to open");
	}
	else {
		while (fgets(s, BUFFSIZE, fp) != NULL) {
			score[i] = atoi(s);
			i = i + 1;
		}
		fclose(fp);
	}

	for (i = 0; i < 3; i++) {
		if (score[i] == 2100000000) {
			sprintf_s(str, "%d��:  -���@-�b", i + 1);
			mvaddstr(20 + 2 * i, 50, str);
		}
		else {
			minutes = score[i] / 60;
			seconds = score[i] % 60;
			sprintf_s(str, "%d��:  %d���@%d�b", i + 1, minutes, seconds);
			mvaddstr(20 + 2 * i, 50, str);
		}
	}

	score[3] = (int)difftime(finishtime, starttime);
	//��ʂR�ʂ܂ł̃^�C�����X�V
	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 4; j++)
		{
			if (score[i] > score[j])
			{
				tmp = score[i];
				score[i] = score[j];
				score[j] = tmp;
			}
		}
	}
	//csv�t�@�C���ւ̏�������
	error = fopen_s(&fp, "ranking.csv", "w");
	if (error != 0) {
		fprintf_s(stderr, "failed to open");
	}
	else {
		for (i = 0; i < 3; i++) {
			fprintf(fp, "%d\n", score[i]);
		}
		fclose(fp);
	}

	refresh();

	while (*titleFlag == 0) {
		key = getch();
		if (key == 'z') {
			*titleFlag = 1;
		}
	}
}