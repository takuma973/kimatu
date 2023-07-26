#include <stdio.h>
#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "parameter.h"

void create_player(struct player *p, int *os) {	//�v���C���[�̐���
	int min = 0, max = 90;
	int r;
	char str[10];

	srand((unsigned int)time(NULL));
	//�e��p�����[�^�̑��
	p->attack = os[0];
	p->defense = os[1];
	p->hp = os[2];
	p->mp = os[3];
	p->x = os[4];
	p->y = os[5];
	p->level = 1;
	p->exp = 0;

	r = (rand() % (max - min + 1)) + min;
	//���@�̌���
	if (0 <= r && r < 30) {
		sprintf_s(p->magic, "�t�@�C���[�{�[��");
	}
	else if (30 <= r && r < 60) {
		sprintf_s(p->magic, "�E�H�[�^�[�{�[��");
	}
	else if (60 <= r && r < 90) {
		sprintf_s(p->magic, "�G�i�W�[�{�[��");
	}
}

void attackMonster(int y, struct enemy* en, struct player* p, int* criticalFlag) {	//�G���U������ۂ̏���
	int min = 0, max = 100;
	int r;
	p->power = 0;
	switch (y) {
		case 21:	//�ʏ�U��
			srand((unsigned int)time(NULL));
			r = (rand() % (max - min + 1)) + min;
			if (r <= 10) {	//�}���ɓ��������ꍇ
				p->power = (p->attack) - (en->defense / 4) + 1;
				*criticalFlag = 1;
			}
			else {
				p->power = (p->attack / 2) - (en->defense / 4) + 1;
			}
			break;

		case 23:	//���@�U��
			p->mp = p->mp - 5;
			if (strcmp(p->magic, "�t�@�C���[�{�[��") == 0) {
				if (strcmp(en->element, "��") == 0) {
					p->power = (p->attack + 5);
				}
				else if (strcmp(en->element, "��") == 0) {
					p->power = (double)(p->attack + 5) * 0.8;
				}
				else if (strcmp(en->element, "��") == 0) {
					p->power = (double)(p->attack + 5) * 1.2;
				}
			}
			else if (strcmp(p->magic, "�E�H�[�^�[�{�[��") == 0) {
				if (strcmp(en->element, "��") == 0) {
					p->power = (p->attack + 5);
				}
				else if (strcmp(en->element, "��") == 0) {
					p->power = (double)(p->attack + 5) * 0.8;
				}
				else if (strcmp(en->element, "��") == 0) {
					p->power = (double)(p->attack + 5) * 1.2;
				}
			}
			else if (strcmp(p->magic, "�G�i�W�[�{�[��") == 0) {
				if (strcmp(en->element, "��") == 0) {
					p->power = (p->attack + 5);
				}
				else if (strcmp(en->element, "��") == 0) {
					p->power = (double)(p->attack + 5) * 0.8;
				}
				else if (strcmp(en->element, "��") == 0) {
					p->power = (double)(p->attack + 5) * 1.2;
				}
			}
			p->power = (p->power / 2) - (en->defense / 4) + 1;
			break;

		case 25:	//�h��
			p->defense = p->defense * 2;
			break;
	}
	if (p->power < 0) {
		p->power = 0;
	}
	en->hp = en->hp - p->power;
}

void getEXP(struct enemy *en, struct player *p, int *levelUpcount) {	//�o���l���擾�����Ƃ��̏���
	int maxexp = 0;
	*levelUpcount = 0;
	//�v���C���[�̂����Ă���o���l�̌v�Z
	p->exp = p->exp + en->exp;
	do {	//���x���A�b�v�ł���܂Ń��x���A�b�v���s��
		if (p->level < 5) {
			maxexp = 1;
		}
		else if (5 <= p->level && p->level < 10) {
			maxexp = 2;
		}
		else if (10 <= p->level && p->level < 15) {
			maxexp = 3;
		}
		else if (15 <= p->level && p->level < 20) {
			maxexp = 4;
		}
		else if (20 <= p->level && p->level < 25) {
			maxexp = 5;
		}
		else if (25 <= p->level && p->level < 30) {
			maxexp = 6;
		}
		else if (30 <= p->level && p->level < 35) {
			maxexp = 7;
		}
		else if (35 <= p->level && p->level < 40) {
			maxexp = 8;
		}
		else if (40 <= p->level && p->level < 45) {
			maxexp = 9;
		}
		else if (45 <= p->level && p->level < 50) {
			maxexp = 10;
		}
		else if (50 <= p->level && p->level < 55) {
			maxexp = 11;
		}
		else if (55 <= p->level && p->level < 60) {
			maxexp = 12;
		}

		if (p->exp >= maxexp) {	//���x���A�b�v
			p->level = p->level + 1;
			p->exp = p->exp - maxexp;
			*levelUpcount = *levelUpcount + 1;
		}
	} while (p->exp >= maxexp);
}