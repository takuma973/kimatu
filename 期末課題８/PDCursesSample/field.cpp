#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "enemy.h"
#include "player.h"
#include "parameter.h"
#include "battle.h"

void shuffle(int all[], int size) {	//配列の要素の順番のシャッフル
	int i, j;
	int tmp;

	i = size - 1;
	srand((unsigned int)time(NULL));
	while (i > 0) {
		j = rand() % (i + 1);
		tmp = all[j];
		all[j] = all[i];
		all[i] = tmp;
		i--;
	}
}

void setEnemy(struct enemy en[], struct player *p, struct enemy *satan, int coordinate[]) {	//敵の配置と色の決定
	int i, j, x, y, a;
	char str[100];

	//魔王のドットを表示する
	attrset(COLOR_PAIR(7));
	mvaddstr(satan->y, satan->x, ".");

	//レベルに応じてドットの色を決める
	for (int i = 0; i < 50; i++) {
		a = en[i].number;
		switch (en[i].level) {
		case 1:
		case 5:
			attrset(COLOR_PAIR(1));
			break;

		case 10:
		case 15:
			attrset(COLOR_PAIR(2));
			break;

		case 20:
		case 25:
			attrset(COLOR_PAIR(4));
			break;

		case 30:
		case 35:
			attrset(COLOR_PAIR(6));
			break;

		case 40:
		case 45:
			attrset(COLOR_PAIR(3));
			break;
		}
		x = coordinate[a] % 110;
		y = coordinate[a] / 110;
		en[i].x = x + 10;
		en[i].y = y + 6;
		mvaddstr(en[i].y, en[i].x, ".");
	}

	attrset(COLOR_PAIR(8));
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 120; j++) {
			mvaddstr(i, j, " ");
		}
	}
	//プレイヤーのレベルと所有している魔法を表示する
	sprintf_s(str, "レベル： %d", p->level);
	mvaddstr(1, 1, str);
	sprintf_s(str, "魔法： %s", p->magic);
	mvaddstr(3, 1, str);

	sprintf_s(str, "紫色：魔王(50レベル)　白色：1 or 5レベル　緑色：10 or 15レベル　青色：20 or 25レベル");
	mvaddstr(1, 32, str);
	sprintf_s(str, "黄色：30 or 35レベル　赤色：40 or 45レベル");
	mvaddstr(3, 32, str);
	refresh();
}

void draw_field(int* gameOverFlag, int* gameClearFlag, int *os, time_t starttime) {	//フィールド画面を描画する
	const int point = 2640;
	int coordinate[point], i, j, key;
	int enemyNumber = 49;
	char str[100];
	enemy en[50], satan;
	player p;
	time_t nowtime;
	clear();

	for (i = 0; i < point; i++) {
		coordinate[i] = i;
	}
	shuffle(coordinate, point);

	create_player(&p, os);
	create_enemy(en, &satan);

	setEnemy(en, &p, &satan, coordinate);
	attrset(COLOR_PAIR(5));
	mvaddstr(p.y, p.x, ".");
	refresh();

	while (*gameOverFlag == 0 && *gameClearFlag == 0) {
		time(&nowtime);
		attrset(COLOR_PAIR(8));
		sprintf_s(str, "現在のタイム: %d", (int)difftime(nowtime, starttime));
		mvaddstr(1, 14, str);
		if (GetKeyState(VK_UP) & 0x80 || GetKeyState(VK_DOWN) & 0x80 ||
			GetKeyState(VK_RIGHT) & 0x80 || GetKeyState(VK_LEFT)) {
			attrset(COLOR_PAIR(5));
			refresh();
			key = getch();
			mvaddstr(p.y, p.x, " ");
			switch (key) {
			case KEY_UP:
				if (p.y != 5) {
					p.y = p.y - 1;
				}
				break;

			case KEY_DOWN:
				if (p.y != 29) {
					p.y = p.y + 1;
				}
				break;

			case KEY_RIGHT:
				if (p.x != 119) {
					p.x = p.x + 1;
				}
				break;

			case KEY_LEFT:
				if (p.x != 0) {
					p.x = p.x - 1;
				}
				break;
			}
		}
		attrset(COLOR_PAIR(5));
		mvaddstr(p.y, p.x, ".");
		refresh();
		for (i = 0; i < 50; i++) {
			if (en[i].y == p.y && en[i].x == p.x) {	//敵（魔王を除く）とプレイヤーがぶつかったら
				draw_battle(&en[i], &p, gameOverFlag, gameClearFlag);
				clear();
				create_Newenemy(&en[i], &enemyNumber);
				setEnemy(en, &p, &satan, coordinate);
				attrset(COLOR_PAIR(5));
				mvaddstr(p.y, p.x, ".");
				refresh();
			}
		}
		if (satan.y == p.y && satan.x == p.x) {	//魔王とプレイヤーがぶつかったら
			draw_battle(&satan, &p, gameOverFlag, gameClearFlag);
			clear();
			refresh();
		}
	}
}