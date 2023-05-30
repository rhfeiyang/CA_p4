#include "lcd/lcd.h"
#include <string.h>
#include "utils.h"

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




void Game_init(Game* game){ //make sure all the data and input are plain/zero + level selection
    Button_input_initialize(&game->input);
    game->state = Select_stage;
    /*TODO：and initialize all data……*/
    

    /*level selection */
    //At this stage, we will get the level information, and set (level number+ # of boxes) to our game.
    int level,num_of_boxes;
    /*TODO： get the above two int*/

    game->level = level;
    game->data.num_of_boxes = num_of_boxes;


}
void Game_update(Game* game){
    Button_input_update(game->input);
    /*TODO：and more……*/
}

int main(void) {
    IO_init();         // init OLED

#pragma region welcome
/*TODO：display a smooth animation along with the game's title.*/
#pragma endregion




#pragma region init
/*This includes:initialize the newly created game's data/input + choose level and set the number of boxes*/
    Game game;
    Game* game_ptr = &game;
    Game_init(game_ptr);

#pragma endregion


#pragma region Process_update

    while (1) {
        Game_update(&game);
    }

#pragma endregion

}