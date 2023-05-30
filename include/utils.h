#ifndef __UTILS_H
#define __UTILS_H

#define BOARD_VER 0/*fill in your board version here. i.e. 0 or 1*/

#if BOARD_VER < 0 || BOARD_VER > 1
#error INVALID_BOARD_VER
#endif

#if BOARD_VER == 0

#define JOY_LEFT GPIO_PIN_0
#define JOY_DOWN GPIO_PIN_1
#define JOY_RIGHT GPIO_PIN_2
#define JOY_UP GPIO_PIN_5
#define JOY_CTR GPIO_PIN_4

#define BUTTON_1 GPIO_PIN_6
#define BUTTON_2 GPIO_PIN_7

#define Board_w 20
#define Board_h 10
#define block_size 8
#define play_pos_x 10
#define play_pos_y 10
// Here empty must be 0
Item_type level1[Board_h][Board_w]={
    {0  ,0  ,0  ,0  ,0  ,0  ,tar,0  ,0  ,0  ,0  ,0  ,0  ,0  ,tar,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,obs,0  ,0  ,0  ,0  ,0  ,box,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,obs,box,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
};
Item_type level2[Board_h][Board_w]={
    {0  ,0  ,0  ,0  ,0  ,0  ,tar,0  ,0  ,0  ,tar  ,0  ,0  ,0  ,tar,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,obs,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,obs,0  ,0  ,0  ,0  ,obs,box,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,obs,box,0  ,0  ,0  ,obs,obs,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,box,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
};

Item_type level3[Board_h][Board_w]={
    {0  ,0  ,0  ,0  ,0  ,0  ,tar,0  ,0  ,0  ,tar  ,0  ,0  ,0  ,tar,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,obs,0  ,0  ,0  ,0  ,0},
    {tar,0  ,0  ,0  ,0  ,0  ,0  ,obs,0  ,0  ,0  ,0  ,obs,box,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,obs,obs,box,0  ,0  ,0  ,obs,obs,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,obs,0  ,0  ,0  ,0  ,0  ,0  ,0  ,box,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,obs,box,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
    {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0},
};

typedef struct{
    Button_input input; //This is the struct which stores whether a certain kind of button is pulled.
    Data data;// game data(box character target…… )
    State state; //game state(win or lose……）
    int level; //game level
}Game;

typedef struct{
    int down;
    int right;
    int left;
    int up;//CTR
    int confirm;//sw1
    int isPulled; //whether a button is pulled down or not
} Button_input;


void Button_input_initialize(Button_input* input);
void Button_input_update(Button_input* input);


typedef enum{
    emp=0,  //0ty
    pla,    //player
    box,    //box
    obs, //obstacle, Only obstacle will not change in a certain level
    tar,    //target
    box_target
    //and more? blank cell? or footprint?
}Item_type;

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
    Item* items; //How to manage these items?
    int num_of_boxes;
    //And more?
}Data;


void Data_initialize(Data* data);
void Data_update(Data* data);









#elif BOARD_VER == 1

#define JOY_LEFT GPIO_PIN_13
#define JOY_DOWN GPIO_PIN_0
#define JOY_RIGHT GPIO_PIN_1
#define JOY_UP GPIO_PIN_5
#define JOY_CTR GPIO_PIN_4

#define BUTTON_1 GPIO_PIN_6
#define BUTTON_2 GPIO_PIN_7

#endif


int Get_Button(int ch);
int Get_BOOT0(void);

#endif