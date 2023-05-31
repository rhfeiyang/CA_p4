// Here empty must be 0
#ifndef GAME_H
#define GAME_H
#include "utils.h"

#define Board_w 20+2
#define Board_h 10+2
#define block_size 8
#define play_pos_x 10
#define play_pos_y 10

typedef enum {
    e=0,  //empty
    pla,    //player
    box,    //box
    obs, //obstacle, Only obstacle will not change in a certain level
    tar,    //target
    box_target, //there is a box on a target
    player_box_target //player and a box on a target
    //and more? blank cell? or footprint?
}Item_type;



typedef struct{
    int down;
    int right;
    int left;
    int up;//CTR
    int confirm;//sw1
    int isPulled; //whether a button is pulled down or not
} Button_input;

typedef struct{
    Item_type grid[Board_h][Board_w]; //How to manage these items?
    int player_pos[2]; //player position
    int remain_boxes;
    int mov_num;
    //And more?
}Data;


typedef enum {
    Select_stage,
    Playing,
    Winning
    //Losing?
}State;

typedef struct{
    int px;  //position
    int py;
    Item_type type;
}Item;

typedef struct{
    Button_input input; //This is the struct which stores whether a certain kind of button is pulled.
    Data data;// game data(box character target…… )
    State state; //game state(win or lose……）
    int level; //game level
    int box_num; //number of boxes
}Game;



void Button_input_initialize(Button_input* input);
void Button_input_update(Button_input* input);
void Game_init(Game* game);
void Game_update(Game* game);

void Data_initialize(Data* data);
void Data_update(Data* data);
void Game_grid_init(Game* game);
void Game_lcd_draw(Game* game);
#endif