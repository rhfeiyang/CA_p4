#ifndef WELCOME_H
#define WELCOME_H
#include "game.h"
#include "lcd/lcd.h"

void draw_welcome();
void draw_select(int level, int box_num);
void select_stage(int *level, int *box_num);
int End_stage(Game* game, int scoreboard[3][4]);
void draw_snowflake(u16 x,u16 y,u16 r);
void animation();
#endif