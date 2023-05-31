#include "lcd/lcd.h"
#include <string.h>
#include "utils.h"
#include "game.h"
#include "welcome.h"
#include<stdlib.h>
void Inp_init(void)
{
	rcu_periph_clock_enable(RCU_GPIOA);
	rcu_periph_clock_enable(RCU_GPIOC);

    gpio_init(GPIOA, GPIO_MODE_IPD, GPIO_OSPEED_50MHZ, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_6);
    gpio_init(GPIOC, GPIO_MODE_IPD, GPIO_OSPEED_50MHZ, GPIO_PIN_13);
}
void IO_init(void)
{
    Inp_init(); // inport init
    Lcd_Init(); // LCD init
}

int comp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
void update_scoreboard(int scoreboard[3][4], Game* game){
    // lower, better
    int level=game->level;
    int score=game->data.mov_num;
    scoreboard[level-1][3]=score; //use quicksort
    qsort(scoreboard[level-1],4,sizeof(int),comp);
}

int main(void) {
    IO_init();         // init OLED

/*TODO：display a smooth animation along with the game's title.*/

/*This includes:initialize the newly created game's data/input + choose level and set the number of boxes*/
    Game game;
    Game_init(&game);
    int scoreboard[3][4]={999,999,999,999,999,999,999,999,999,999,999,999};
    while(1){
        while (game.state != Winning) {
            Game_update(&game);
        }
        // the scoreboard
        update_scoreboard(scoreboard,&game);
        if(End_stage(&game,scoreboard)==0){
            Game_init(&game);
        }else{
            // if restart?
            game.data.remain_boxes = game.box_num;
            game.data.mov_num = 0;
            game.state = Playing;
            Game_grid_init(&game);
            Game_lcd_draw(&game);
        }
    }
    return 0;
}