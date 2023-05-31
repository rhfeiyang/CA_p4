#include "lcd/lcd.h"
#include <string.h>
#include "utils.h"
#include "game.h"
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



int main(void) {
    IO_init();         // init OLED

/*TODO：display a smooth animation along with the game's title.*/

/*This includes:initialize the newly created game's data/input + choose level and set the number of boxes*/
    Game game;
    Game_init(&game);

    // while (1) {
    //     Game_update(&game);
    // }


}