#pragma once
struct enemy {
	int number;
	int level;
	int attack;
	int defense;
	int hp;
	int mp;
	int power;
	int exp;
	int satanFlag;
	char magic[20];
	char element[10];
	int x;
	int y;
};

struct player {
	int level;
	int attack;
	int defense;
	int hp;
	int mp;
	int power;
	int exp;
	char magic[20];
	int x;
	int y;
};