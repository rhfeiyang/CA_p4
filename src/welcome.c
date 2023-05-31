#include "welcome.h"
#include "lcd/lcd.h"
#include "utils.h"
void draw_select(int level, int box_num){
    LCD_ShowNum(90,20,level,2,WHITE);
    LCD_ShowNum(90,40,box_num,2,WHITE);
}
void select_stage(int *level_ret, int *box_num_ret){
    int level=1;
    int box_num=1;
    LCD_Clear(BLACK);
    draw_select(level,box_num); // draw the select
    LCD_ShowString(40,20,"Level:",WHITE);
    LCD_ShowString(40,40,"Box:",WHITE);
    LCD_ShowNum(90,20,level,2,WHITE);
    LCD_ShowNum(90,40,box_num,2,WHITE);
    while(Get_BOOT0()==0){
        if(Get_Button(JOY_CTR)){
            level++;
            if(level>3) level=1;
            draw_select(level,box_num);
            // delay_ms(200);
        }
        if(Get_Button(JOY_DOWN)){
            level--;
            if(level<1) level=3;
            draw_select(level,box_num);
            // delay_ms(200);
        }
        if(Get_Button(JOY_RIGHT)){
            box_num++;
            if(box_num>5) box_num=1;
            draw_select(level,box_num);
            // delay_ms(200);
        }
        if(Get_Button(JOY_LEFT)){
            box_num--;
            if(box_num<1) box_num=5;
            draw_select(level,box_num);
            // delay_ms(200);
        }
    }
    *level_ret=level;
    *box_num_ret=box_num;
}

int End_stage(Game* game, int scoreboard[3][4]){
    LCD_Clear(BLACK);
    // LCD_ShowString(0,10,"Steps:",WHITE);
    // LCD_ShowNum(50,10,game->data.mov_num,4,WHITE);
    LCD_ShowString(0,0,"LV1:",WHITE); //scoreboard
    if(scoreboard[0][0]!=999)  LCD_ShowNum(30,0, scoreboard[0][0],3,WHITE);
    if(scoreboard[0][1]!=999)  LCD_ShowNum(60,0, scoreboard[0][1],3,WHITE);
    if(scoreboard[0][2]!=999)  LCD_ShowNum(90,0, scoreboard[0][2],3,WHITE);
    LCD_ShowString(0,20,"LV2:",WHITE); //scoreboard
    if(scoreboard[1][0]!=999)  LCD_ShowNum(30,20,scoreboard[1][0],3,WHITE);
    if(scoreboard[1][1]!=999)  LCD_ShowNum(60,20,scoreboard[1][1],3,WHITE);
    if(scoreboard[1][2]!=999)  LCD_ShowNum(90,20,scoreboard[1][2],3,WHITE);
    LCD_ShowString(0,40,"LV3:",WHITE); //scoreboard
    if(scoreboard[2][0]!=999)  LCD_ShowNum(30,40,scoreboard[2][0],3,WHITE);
    if(scoreboard[2][1]!=999)  LCD_ShowNum(60,40,scoreboard[2][1],3,WHITE);
    if(scoreboard[2][2]!=999)  LCD_ShowNum(90,40,scoreboard[2][2],3,WHITE);

    LCD_ShowString(0,60,"Back(any dir)",WHITE);
    // LCD_ShowString(0,50,"Quit(sw1)",WHITE);
    while(1){
        int down = Get_Button(JOY_DOWN);
        int right = Get_Button(JOY_RIGHT);
        int left = Get_Button(JOY_LEFT);
        int up = Get_Button(JOY_CTR);
        int confirm = Get_Button(BUTTON_1);
        int isPulled = (down || right || left || up||confirm);
        // if(confirm){
        //     // sw1
        //     return 0;
        // }
        if(isPulled){
            // new game
            return 0;
        }
    }
}