#pragma once
void create_player(struct player* p, int* os);
void attackMonster(int y, struct enemy* en, struct player* p, int* criticalFlag);
void getEXP(struct enemy* en, struct player* p, int* levelUpcount);