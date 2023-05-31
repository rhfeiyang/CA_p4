#ifndef WELCOME_H
#define WELCOME_H
#include "game.h"

void draw_welcome();
void draw_select(int level, int box_num);
void select_stage(int *level, int *box_num);
int End_stage(Game* game, int scoreboard[3][4]);

#endif