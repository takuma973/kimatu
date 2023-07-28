#include <stdio.h>
#include <curses.h>

void draw_rule(int* titleFlag) { //ルール画面の描画
	int key;
	clear();

	while (*titleFlag == 0) {
		mvaddstr(1, 0, "タイトル画面でplayを選択するとフィールドに移動する。フィールド画面には様々な色のドットがあり、各ドットは敵と自分を表して");
		mvaddstr(3, 0, "いる。自分のドットと敵のドットを重ねると戦闘が始まる。コマンドを選択することで戦いを進め敵のHPを0にすると勝利になる。レ");
		mvaddstr(5, 0, "ベルをあげ、最終的に魔王を倒せば勝ちだ！基本的に移動やコマンドの選択は矢印キー、選択はaキー、戻るはzキーである。");
		mvaddstr(7, 0, "zボタンでタイトルに戻る");
		refresh();
		key = getch();
		if (key == 'z') {
			*titleFlag = 1;
		}
	}
}