#include <stdio.h>
#include <curses.h>
#include <Windows.h>
#include "parameter.h"
#include "player.h"
#include "enemy.h"
#include "word.h"

void draw_frame() {	//戦闘画面の枠組みを描画
	int x = 34, y = 19;
	int i;
	attrset(COLOR_PAIR(1));
	//画面左下のコマンドの描画
	for (i = 0; i < 13; i++) {
		mvaddstr(y, x + i, " ");
		mvaddstr(y + 10, x + i, " ");
	}
	for (i = 0; i < 10; i++) {
		mvaddstr(y + i, x, " ");
		mvaddstr(y + i, x + 13, " ");
	}

	attrset(COLOR_PAIR(2));
	mvaddstr(y, 38, "コマンド");
	mvaddstr(y + 2, 38, "こうげき");
	mvaddstr(y + 4, 38, "まほう");
	mvaddstr(y + 6, 38, "ぼうぎょ");
	
	//画面下部のセリフ枠の描画
	attrset(COLOR_PAIR(1));
	x = 50;
	for (i = 0; i < 44; i++) {
		mvaddstr(y, x + i, " ");
		mvaddstr(y +10, x + i, " ");;
	}
	for (i = 0; i < 10; i++) {
		mvaddstr(y + i, x, " ");
		mvaddstr(y + i, x + 44, " ");
	}

	//画面上部の描画
	x = 57, y = 1;
	for (i = 0; i < 16; i++) {
		mvaddstr(y, x + i, " ");
		mvaddstr(y + 6, x + i, " ");
	}
	for (i = 0; i < 6; i++) {
		mvaddstr(y + i, x, " ");
		mvaddstr(y + i, x + 16, " ");
	}
	attrset(COLOR_PAIR(2));
	mvaddstr(y, x + 2, "自分");
	mvaddstr(y + 2, x + 2, "HP ");
	mvaddstr(y + 4, x + 2, "MP ");
	mvaddstr(y, x + 10, "てき");
	mvaddstr(y + 2, x + 10, "HP");
	mvaddstr(y + 4, x + 10, "MP");

	refresh();
}

void clearWord(int *y1) {	//セリフ枠の文字を消す
	int i, j;
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 42; j++) {
			mvaddstr(20 + i, 51 + j, " ");
		}
	}
	*y1 = 21;
}

void draw_battle(struct enemy *en, struct player *p, int* gameOverFlag, int* gameClearFlag) {	//戦闘画面の描画
	int battleWinFlag, commandFlag, levelUpcount;
	battleWinFlag = commandFlag = levelUpcount = 0;
	int x1, x2, x3, y1, y2, y3, y4, key, i, point, pattern, criticalFlag;
	char str[100];
	int defenseM = en->defense, defenseP = p->defense , maxHP = p->hp, maxMP = p->mp;
	x3 = 61, y3 = 3;
	clear();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(14, COLOR_BLACK, COLOR_GREEN);
	init_pair(10, COLOR_BLACK, COLOR_BLUE);
	init_pair(11, COLOR_BLACK, COLOR_YELLOW);
	init_pair(12, COLOR_BLACK, COLOR_RED);
	init_pair(13, COLOR_BLACK, COLOR_MAGENTA);

	attrset(COLOR_PAIR(2));
	if (en->satanFlag == 1) {	//敵が魔王の場合
		sprintf_s(str, "%s属性魔王(%dレベル)があらわれた", en->element, en->level);
		attrset(COLOR_PAIR(13));
		draw_monster();
	}
	else {	//敵が魔王以外の場合
		sprintf_s(str, "%s属性モンスター(%dレベル)があらわれた", en->element, en->level);
		switch (en->level) {
		case 1:
		case 5:
			attrset(COLOR_PAIR(1));
			break;

		case 10:
		case 15:
			attrset(COLOR_PAIR(14));
			break;

		case 20:
		case 25:
			attrset(COLOR_PAIR(10));
			break;

		case 30:
		case 35:
			attrset(COLOR_PAIR(11));
			break;

		case 40:
		case 45:
			attrset(COLOR_PAIR(12));
			break;
		}
		draw_monster();
	}
	x1 = 52, y1 = 21;
	mvaddstr(y1, x1, str);
	//自分と敵のHP、MPを表示
	sprintf_s(str, " %d",p->hp);
	mvaddstr(y3, x3, str);
	sprintf_s(str, " %d", p->mp);
	mvaddstr(y3 + 2, x3, str);
	sprintf_s(str, " %d", en->hp);
	mvaddstr(y3, x3 + 9, str);
	sprintf_s(str, " %d", en->mp);
	mvaddstr(y3 + 2, x3 + 9, str);

	draw_frame();
	x2 = 36, y2 = 21;
	mvaddstr(y2, x2, "-");
	refresh();
	while (*gameOverFlag == 0 && battleWinFlag == 0) {
		if (GetKeyState(VK_UP) & 0x80 || GetKeyState(VK_DOWN) & 0x80 || GetKeyState('A') & 0x80) {
			key = getch();
			switch (key) {
			case KEY_UP:
				mvaddstr(y2, x2, " ");
				if (y2 != 21) {
					y2 = y2 - 2;
				}
				mvaddstr(y2, x2, "-");
				refresh();
				break;

			case KEY_DOWN:
				mvaddstr(y2, x2, " ");
				if (y2 != 25) {
					y2 = y2 + 2;
				}
				mvaddstr(y2, x2, "-");
				refresh();
				break;

			case 'a':
				commandFlag = 1;
				break;
			}
		}

		if (commandFlag == 1) {	//プレイヤーが行動を決定した場合
			clearWord(&y1);
			if (y2 == 23 && p->mp < 5) {	//MP不足で「まほう」を選択した場合
				sprintf_s(str, "MP不足で魔法が使えない");
				mvaddstr(y1, x1, str);
				y1 = y1 + 2;
				p->power = 0;
				refresh();
			}
			else {
				criticalFlag = 0;
				attackMonster(y2, en, p, &criticalFlag);
				en->defense = defenseM;

				switch (y2) {
				case 21:	//「こうげき」を選択した場合
					sprintf_s(str, "自分のこうげき");
					mvaddstr(y1, x1, str);
					y1 = y1 + 2;
					refresh();
					if (criticalFlag == 1) {	//急所に当たった場合
						for (i = 0; i < 1000000000; i++);
						sprintf_s(str, "急所に当たった");
						mvaddstr(y1, x1, str);
						y1 = y1 + 2;
						refresh();
					}
					break;

				case 23:	//「まほう」を選択した場合
					sprintf_s(str, "自分は%sをとなえた", p->magic);
					mvaddstr(y1, x1, str);
					y1 = y1 + 2;

					sprintf_s(str, " %d", p->mp);
					mvaddstr(y3 + 2, x3, "    ");
					mvaddstr(y3 + 2, x3, str);
					refresh();
					break;

				case 25:	//「ぼうぎょ」を選択した場合
					sprintf_s(str, "自分はぼうぎょをつかった");
					mvaddstr(y1, x1, str);
					y1 = y1 + 2;
					refresh();

					for (i = 0; i < 1000000000; i++);
					sprintf_s(str, "ぼうぎょりょくがあがった");
					mvaddstr(y1, x1, str);
					y1 = y1 + 2;
					refresh();
					break;
				}
				for (i = 0; i < 1000000000; i++);
				sprintf_s(str, "モンスターに%dのダメージ", p->power);
				mvaddstr(y1, x1, str);
				y1 = y1 + 2;

				if (en->hp <= 0) {	//敵のHPが0になった場合
					for (i = 0; i < 1000000000; i++);
					sprintf_s(str, "モンスターをたおした");
					mvaddstr(y1, x1, str);
					y1 = y1 + 2;

					mvaddstr(y3, x3 + 9, "   ");
					mvaddstr(y3, x3 + 9, " 0");
					refresh();
					for (i = 0; i < 2000000000; i++);
					clearWord(&y1);

					getEXP(en, p, &levelUpcount);
					if (levelUpcount >= 1) {	//レベルが上がった場合
						//プレイヤーのHPとMPの回復
						p->hp = maxHP;
						p->mp = maxMP;
						y2 = 21;
						sprintf_s(str, "レベルが%dあがった", levelUpcount);
						mvaddstr(y1, x1, str);
						y1 = y1 + 2;

						sprintf_s(str, "強化するステータスを選択してください");
						mvaddstr(y1, x1, str);
						y1 = y1 + 2;

						sprintf_s(str, " 攻撃力");
						mvaddstr(y2, 38, str);
						y2 = y2 + 2;

						sprintf_s(str, " 防御力");
						mvaddstr(y2, 38, str);
						y2 = y2 + 2;

						sprintf_s(str, " MP     ");
						mvaddstr(y2, 38, str);
						y2 = y2 + 2;

						sprintf_s(str, " HP");
						mvaddstr(y2, 38, str);

						y2 = 21;
						point = levelUpcount * 3;
						while (point > 0) {
							sprintf_s(str, "のこり   ");
							mvaddstr(y1, x1, str);
							sprintf_s(str, "のこり %d", point);
							mvaddstr(y1, x1, str);
							sprintf_s(str, "攻撃力: %d 防御力: %d MP: %d HP: %d", p->attack, p->defense, p->mp, p->hp);
							mvaddstr(y1 + 2, x1, str);
							refresh();

							key = getch();
							switch (key) {
							case KEY_UP:
								mvaddstr(y2, x2, " ");
								if (y2 != 21) {
									y2 = y2 - 2;
								}
								mvaddstr(y2, x2, "-");
								refresh();
								break;

							case KEY_DOWN:
								mvaddstr(y2, x2, " ");
								if (y2 != 27) {
									y2 = y2 + 2;
								}
								mvaddstr(y2, x2, "-");
								refresh();
								break;

							case 'a':
								switch (y2) {
								case 21:	//攻撃力を１上げる
									p->attack = p->attack + 1;
									break;

								case 23:	//防御力を１上げる
									p->defense = p->defense + 1;
									break;

								case 25:	//MPを１上げる
									p->mp = p->mp + 1;
									break;

								case 27:	//HPを１上げる
									p->hp = p->hp + 1;
									break;
								}
								point = point - 1;
								break;
							}
						}
						//最大HP、MPを更新
						maxHP = p->hp;
						maxMP = p->mp;
					}
					if (en->satanFlag == 1) {	//倒した敵が魔王の場合
						*gameClearFlag = 1;
					}
					battleWinFlag = 1;
				}
				else {	//敵のHPが0にならなかった場合
					sprintf_s(str, " %d", en->hp);
					mvaddstr(y3, x3 + 9, "   ");
					mvaddstr(y3, x3 + 9, str);
					refresh();
					for (i = 0; i < 2000000000; i++);
					attackPlayer(en, p, &pattern);
					p->defense = defenseP;
					clearWord(&y1);
					switch (pattern) {
					case 1:	//「こうげき」の場合
						sprintf_s(str, "モンスターのこうげき");
						mvaddstr(y1, x1, str);
						y1 = y1 + 2;
						break;

					case 2:	//「まほう」の場合
						sprintf_s(str, "モンスターが%sをとなえた", en->magic);
						mvaddstr(y1, x1, str);
						y1 = y1 + 2;

						sprintf_s(str, " %d", en->mp);
						mvaddstr(y3 + 2, x3 + 9, "   ");
						mvaddstr(y3 + 2, x3 + 9, str);
						break;

					case 3:	//「ぼうぎょ」の場合
						sprintf_s(str, "モンスターはぼうぎょの構えをとった");
						mvaddstr(y1, x1, str);
						y1 = y1 + 2;

						for (i = 0; i < 1000000000; i++);
						sprintf_s(str, "モンスターの防御力があがった");
						mvaddstr(y1, x1, str);
						y1 = y1 + 2;
						break;
					}
					for (i = 0; i < 1500000000; i++);
					sprintf_s(str, "自分に %dのダメージ", en->power);
					mvaddstr(y1, x1, str);
					y1 = y1 + 2;
					refresh();

					if (p->hp > 0) {	//敵の攻撃でプレイヤーのHPが0にならなかった場合
						mvaddstr(y3, x3, "    ");
						sprintf_s(str, " %d", p->hp);
						mvaddstr(y3, x3, str);
						refresh();
						for (i = 0; i < 2000000000; i++);
						clearWord(&y1);
					}
					else if (p->hp <= 0) {
						mvaddstr(y3, x3, "   ");
						sprintf_s(str, " %d", 0);
						mvaddstr(y3, x3, str);
						sprintf_s(str, "自分はたおれた");
						mvaddstr(y1, x1, str);
						refresh();
						*gameOverFlag = 1;
						for (i = 0; i < 2100000000; i++);
					}
				}
			}
			refresh();
			commandFlag = 0;
		}
		refresh();
	}
}