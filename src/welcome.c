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
    LCD_ShowString(40,20,(const u8*)"Level:",WHITE);
    LCD_ShowString(40,40,(const u8*)"Box:",WHITE);
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
    LCD_ShowString(0,0,(const u8*)"LV1:",WHITE); //scoreboard
    if(scoreboard[0][0]!=999)  LCD_ShowNum(30,0, scoreboard[0][0],3,WHITE);
    if(scoreboard[0][1]!=999)  LCD_ShowNum(60,0, scoreboard[0][1],3,WHITE);
    if(scoreboard[0][2]!=999)  LCD_ShowNum(90,0, scoreboard[0][2],3,WHITE);
    LCD_ShowString(0,20,(const u8*)"LV2:",WHITE); //scoreboard
    if(scoreboard[1][0]!=999)  LCD_ShowNum(30,20,scoreboard[1][0],3,WHITE);
    if(scoreboard[1][1]!=999)  LCD_ShowNum(60,20,scoreboard[1][1],3,WHITE);
    if(scoreboard[1][2]!=999)  LCD_ShowNum(90,20,scoreboard[1][2],3,WHITE);
    LCD_ShowString(0,40,(const u8*)"LV3:",WHITE); //scoreboard
    if(scoreboard[2][0]!=999)  LCD_ShowNum(30,40,scoreboard[2][0],3,WHITE);
    if(scoreboard[2][1]!=999)  LCD_ShowNum(60,40,scoreboard[2][1],3,WHITE);
    if(scoreboard[2][2]!=999)  LCD_ShowNum(90,40,scoreboard[2][2],3,WHITE);

    LCD_ShowString(0,60,(const u8*)"Back(any dir)",WHITE);
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
    //LCD_ShowString(60,25,"Mygame",WHITE);
    int r = 80;
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
        LCD_ShowString(36,50,(const u8*)"Loading ...",RED);
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
        LCD_ShowString(30,25,(const u8*)"Welcome to ...",WHITE);
        LCD_DrawCircle(LCD_W/2,LCD_H/2,r,BLUE);
        LCD_DrawRectangle(LCD_W/2-60, LCD_H/2-20, LCD_W/2+60, LCD_H/2+20,RED);
        delay_1ms(20);
        LCD_Clear(BLACK);
        r-=2;
    }
    while(r<80){
        LCD_ShowString(40,25,(const u8*)"Our game!",WHITE);
        LCD_DrawCircle(LCD_W/2,LCD_H/2,r,BLUE);
        LCD_DrawRectangle(LCD_W/2-60, LCD_H/2-20, LCD_W/2+60, LCD_H/2+20,RED);
        delay_1ms(20);
        LCD_Clear(BLACK);
        r+=2;
    }

    LCD_Clear(BLACK);

}