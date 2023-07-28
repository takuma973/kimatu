// PDCursesSample.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

//x:120 y:30

#include <stdio.h>
#include <curses.h>
#include <time.h>
#include "title.h"
#include "rule.h"
#include "enemy.h"
#include "field.h"
#include "player.h"
#include "gameover.h"
#include "gamaclear.h"
#include <Windows.h>

#define CHARBUFF 124

void getCurrentDirectory(char* currentDirectory) {	//現在のパスを取得
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}

int readInt(const char* section, const char* keyword) {	//iniファイルからパラメータを取得
	char currentDirectory[CHARBUFF];
	getCurrentDirectory(currentDirectory);
	char settingFile[CHARBUFF];
	sprintf_s(settingFile, "%s\\setting.ini", currentDirectory);

	return GetPrivateProfileInt(section, keyword, -1, settingFile);
}

int main()	//メイン関数
{
	int startFlag, ruleFlag, titleFlag, gameOverFlag, gameClearFlag;
	startFlag = ruleFlag = titleFlag = gameOverFlag = gameClearFlag = 0;
	time_t starttime, finishtime;
	initscr();
	start_color();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	erase();

	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_WHITE);
	init_pair(9, COLOR_BLACK, COLOR_GREEN);
	init_pair(10, COLOR_BLACK, COLOR_RED);
	init_pair(11, COLOR_BLACK, COLOR_BLUE);
	init_pair(12, COLOR_BLACK, COLOR_YELLOW);
	init_pair(13, COLOR_BLACK, COLOR_MAGENTA);

	int os[] = { readInt("status", "attack"), readInt("status", "defense"), readInt("status", "hp"), readInt("status", "mp"), readInt("status", "x"), readInt("status", "y") };
	draw_title(&startFlag, &ruleFlag);
	while (1) {
		if (startFlag == 1) {
			time(&starttime);
			draw_field(&gameOverFlag, &gameClearFlag, os, starttime);
			startFlag = 0;
		}
		else if (ruleFlag == 1) {
			draw_rule(&titleFlag);
			ruleFlag = 0;
		}
		else if (titleFlag == 1) {
			draw_title(&startFlag, &ruleFlag);
			titleFlag = 0;
		}
		else if (gameOverFlag == 1) {
			draw_gameover(&titleFlag);
			gameOverFlag = 0;
		}
		else if (gameClearFlag == 1) {
			time(&finishtime);
			draw_gameclear(&titleFlag, starttime, finishtime);
			gameClearFlag = 0;
		}

	}
	refresh();	
}
