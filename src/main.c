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

void draw_snowflake(u16 x,u16 y,u16 r){
    int i=0;
    for(i=y-r;i<=y+r;i++){
        LCD_DrawPoint(x,i,BLUE);
    }
    for(i=x-r;i<=x+r;i++){
        LCD_DrawPoint(i,y,BLUE);
    }
    for(i=0;i<2*r;i++){
        LCD_DrawPoint(x-(r-1)+i,y+(r-1)-i,BLUE);
    }
    for(i=0;i<2*r;i++){
        LCD_DrawPoint(x-(r-1)+i,y-(r-1)+i,BLUE);
    }
}
void animation(){
    LCD_Clear(BLACK);
    int start_time = 0;
    //LCD_ShowString(60,25,"Mygame",WHITE);
    int rx,ry,r;
    rx = 10;ry = 10;r=80;
    int dx = 0;int dy=0;
    while(dx<LCD_W){
        LCD_DrawCircle(dx,LCD_H/2,10,BLUE);
        delay_1ms(10);
        dx+=1;
    }
    while(dy<LCD_H){
        LCD_DrawCircle(LCD_W/2,dy,10,BLUE);
        delay_1ms(10);
        dy+=1;
    }
    int rr=0;
    while(rr<LCD_W/2){
        LCD_DrawCircle(LCD_W/2,LCD_H/2,rr,BLACK);
        delay_1ms(20);
        rr+=1;
    }

    LCD_Clear(BLACK);
    dy=20;

    while(dy<60){
        LCD_ShowString(36,50,"Loading ...",RED);
        draw_snowflake(20,dy,6);
        draw_snowflake(50,dy-12,8);
        draw_snowflake(80,dy+20,8);
        draw_snowflake(102,dy+8,6);
        draw_snowflake(120,dy-7,4);
        draw_snowflake(70,dy-2,6);
        delay_1ms(10);
        LCD_Clear(BLACK);
        dy++;
    }
    while(r>0){
        LCD_ShowString(30,25,"Welcome to ...",WHITE);
        LCD_DrawCircle(LCD_W/2,LCD_H/2,r,BLUE);
        LCD_DrawRectangle(LCD_W/2-60, LCD_H/2-20, LCD_W/2+60, LCD_H/2+20,RED);
        delay_1ms(20);
        LCD_Clear(BLACK);
        r-=2;
    }
    while(r<80){
        LCD_ShowString(40,25,"Our game!",WHITE);
        LCD_DrawCircle(LCD_W/2,LCD_H/2,r,BLUE);
        LCD_DrawRectangle(LCD_W/2-60, LCD_H/2-20, LCD_W/2+60, LCD_H/2+20,RED);
        delay_1ms(20);
        LCD_Clear(BLACK);
        r+=2;
    }

    LCD_Clear(BLACK);

}
int main(void) {
    IO_init();         // init OLED

/*TODO：display a smooth animation along with the game's title.*/
    animation();

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