#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include "parameter.h"

void create_enemy(struct enemy en[], struct enemy *satan) {	//ゲーム開始時の敵の生成
	int r, min, max, i, parameter;
	satan->attack = satan->defense = satan->mp = satan->hp = 0;
	srand((unsigned int)time(NULL));

	//魔王のパラメータの決定
	satan->x = 5;
	satan->y = 8;
	satan->satanFlag = 1;
	satan->level = 50;
	parameter = satan->level * 3;
	max = 100, min = 0;
	//ステータスの決定
	while (parameter > 0) {
		r = (rand() % (max - min + 1)) + min;
		if (0 <= r && r < 25) {
			satan->attack = satan->attack + 1;
		}
		else if (25 <= r && r < 45) {
			satan->defense = satan->defense + 1;
		}
		else if (45 <= r && r < 60) {
			satan->mp = satan->mp + 1;
		}
		else if (60 <= r && r < 100) {
			satan->hp = satan->hp + 1;
		}
		parameter = parameter - 1;
	}
	max = 90;
	r = (rand() % (max - min + 1)) + min;
	//属性と魔法の決定
	if (0 <= r && r < 30) {
		sprintf_s(satan->element, "火");
		sprintf_s(satan->magic, "ファイヤーボール");
	}
	else if (30 <= r && r < 60) {
		sprintf_s(satan->element, "水");
		sprintf_s(satan->magic, "ウォーターボール");
	}
	else if (60 <= r && r < 90) {
		sprintf_s(satan->element, "木");
		sprintf_s(satan->magic, "エナジーボール");
	}

	//敵のステータスの決定
	//レベルと経験値の決定
	for (i = 0; i < 50; i++) {
		en[i].satanFlag = 0;
		en[i].number = i;
		en[i].attack = en[i].defense = en[i].mp = en[i].hp = 0;
		max = 100;
		r = (rand() % (max - min + 1)) + min;
		if (0 <= r && r <= 21) {
			en[i].level = 1;
			en[i].exp = 1;
		}
		else if (21 < r && r <= 28) {
			en[i].level = 5;
			en[i].exp = 1;
		}
		else if (28 < r && r <= 40) {
			en[i].level = 10;
			en[i].exp = 2;
		}
		else if (40 < r && r <= 50) {
			en[i].level = 15;
			en[i].exp = 2;
		}
		else if (50 < r && r <= 62) {
			en[i].level = 20;
			en[i].exp = 3;
		}
		else if (62 < r && r <= 68) {
			en[i].level = 25;
			en[i].exp = 3;
		}
		else if (68 < r && r <= 83) {
			en[i].level = 30;
			en[i].exp = 4;
		}
		else if (83 < r && r <= 88) {
			en[i].level = 35;
			en[i].exp = 4;
		}
		else if (88 < r && r <= 96) {
			en[i].level = 40;
			en[i].exp = 5;
		}
		else if (96 < r && r <= 100) {
			en[i].level = 45;
			en[i].exp = 5;
		}

		//ステータスの決定
		if (en[i].level == 1) {
			en[i].attack = 1;
			en[i].defense = 0;
			en[i].mp = 0;
			en[i].hp = 1;
		}
		else {
			parameter = en[i].level * 3;
			while (parameter > 0) {
				r = (rand() % (max - min + 1)) + min;
				if (0 <= r && r < 25) {
					en[i].attack = en[i].attack + 1;
				}
				else if (25 <= r && r < 45) {
					en[i].defense = en[i].defense + 1;
				}
				else if (45 <= r && r < 60) {
					en[i].mp = en[i].mp + 1;
				}
				else if (60 <= r && r < 100) {
					en[i].hp = en[i].hp + 1;
				}
				parameter = parameter - 1;
			}
		}

		max = 90;
		r = (rand() % (max - min + 1)) + min;
		//属性と魔法の決定
		if (0 <= r && r < 30) {
			sprintf_s(en[i].element, "火");
			sprintf_s(en[i].magic, "ファイヤーボール");
		}
		else if (30 <= r && r < 60) {
			sprintf_s(en[i].element, "水");
			sprintf_s(en[i].magic, "ウォーターボール");
		}
		else if (60 <= r && r < 90) {
			sprintf_s(en[i].element, "木");
			sprintf_s(en[i].magic, "エナジーボール");
		}
	}
}

void create_Newenemy(struct enemy *en, int* enemynumber) {	//追加の敵の生成
	int r, min, max, parameter;

	en->satanFlag = 0;
	srand((unsigned int)time(NULL));
	min = 0;
	*enemynumber = *enemynumber + 1;
	en->number = *enemynumber;
	en->attack = en->defense = en->mp = en->hp = 0;
	max = 100;
	r = (rand() % (max - min + 1)) + min;
	//レベルと経験値の決定
	if (0 <= r && r <= 21) {
		en->level = 1;
		en->exp = 1;
	}
	else if (21 < r && r <= 28) {
		en->level = 5;
		en->exp = 1;
	}
	else if (28 < r && r <= 40) {
		en->level = 10;
		en->exp = 2;
	}
	else if (40 < r && r <= 50) {
		en->level = 15;
		en->exp = 2;
	}
	else if (50 < r && r <= 62) {
		en->level = 20;
		en->exp = 3;
	}
	else if (62 < r && r <= 68) {
		en->level = 25;
		en->exp = 3;
	}
	else if (68 < r && r <= 83) {
		en->level = 30;
		en->exp = 4;
	}
	else if (83 < r && r <= 88) {
		en->level = 35;
		en->exp = 4;
	}
	else if (88 < r && r <= 96) {
		en->level = 40;
		en->exp = 5;
	}
	else if (96 < r && r <= 100) {
		en->level = 45;
		en->exp = 5;
	}

	//ステータスの決定
	if (en->level == 1) {
		en->attack = 1;
		en->defense = 0;
		en->mp = 0;
		en->hp = 1;
	}
	else {
		parameter = en->level * 3;
		while (parameter > 0) {
			r = (rand() % (max - min + 1)) + min;
			if (0 <= r && r < 25) {
				en->attack = en->attack + 1;
			}
			else if (25 <= r && r < 45) {
				en->defense = en->defense + 1;
			}
			else if (45 <= r && r < 60) {
				en->mp = en->mp + 1;
			}
			else if (60 <= r && r < 100) {
				en->hp = en->hp + 1;
			}
			parameter = parameter - 1;
		}
	}

	max = 90;
	r = (rand() % (max - min + 1)) + min;
	//魔法と属性の決定
	if (0 <= r && r < 30) {
		sprintf_s(en->element, "火");
		sprintf_s(en->magic, "ファイヤーボール");
	}
	else if (30 <= r && r < 60) {
		sprintf_s(en->element, "水");
		sprintf_s(en->magic, "ウォーターボール");
	}
	else if (60 <= r && r < 90) {
		sprintf_s(en->element, "木");
		sprintf_s(en->magic, "エナジーボール");
	}
}

void attackPlayer(struct enemy* en, struct player* p, int *pattern) {	//プレイヤーを攻撃する際のアルゴリズム
	int min = 0, max = 100;
	int r;
	en->power = 0;
	*pattern = 0;
	srand((unsigned int)time(NULL));
	while (*pattern == 0) {
		r = (rand() % (max - min + 1)) + min;
		if (0 <= r && r < 60) {	//通常攻撃
			en->power = (en->attack / 2) - (p->defense) + 1;
			*pattern = 1;
		}
		else if ((60 <= r && r < 90) && en->mp >= 5) {	//魔法攻撃
			en->power = (en->power + 5) / 2 - (p->defense / 4) + 1;
			*pattern = 2;
		}
		else if (90 <= r && r <= 100) {	//防御
			en->defense = en->defense * 2;
			*pattern = 3;
		}
	}
	if (en->power < 0) {
		en->power = 0;
	}
	p->hp = p->hp - en->power;	
}