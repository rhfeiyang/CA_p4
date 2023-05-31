#include "game.h"
#include "lcd/lcd.h"
#include "welcome.h"
// init level1
const Item_type level1[Board_h][Board_w]={
    {obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs}, //comment 
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs}, //comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs}, //comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs}, //comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs}, //comment
    {obs,e  ,e  ,e  ,e  ,e  ,obs,e  ,e  ,e  ,e  ,e  ,e  ,obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs}, //comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs}, //comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs}, //comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,pla,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs}, //comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs}, //comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs}, //comment
    {obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs}
};
// init level2
const Item_type level2[Board_h][Board_w]={
    {obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs},  //comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs},  //comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs},  //comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs,e  ,e  ,e  ,e  ,e  ,obs},  //comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs},  //comment
    {obs,e  ,e  ,e  ,e  ,e  ,obs,e  ,e  ,e  ,e  ,obs,obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs},  //comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs,e  ,e  ,e  ,e  ,e  ,e  ,obs},  //comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs},  //comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,pla,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs},  //comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs},  //comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs},  //comment
    {obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs}
};
// init level3
const Item_type level3[Board_h][Board_w]={
    {obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs},//comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs},//comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs},//comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs,e  ,obs,e  ,e  ,e  ,e  ,e  ,obs},//comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs,e  ,e  ,obs},//comment
    {obs,e  ,e  ,e  ,e  ,obs,obs,e  ,e  ,e  ,e  ,obs,obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs},//comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs,e  ,e  ,e  ,e  ,obs},//comment
    {obs,e  ,obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs},//comment
    {obs,e  ,e  ,e  ,obs,e  ,e  ,e  ,e  ,e  ,e  ,pla,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs},//comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs},//comment
    {obs,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,e  ,obs},//comment
    {obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs,obs}
};

void Button_input_initialize(Button_input* input){
    //init
    input->down = 0;
    input->right = 0;
    input->left = 0;
    input->up = 0;
    input->confirm = 0;
    // input->isPulled = 0;
}
void Game_grid_init(Game* game){
    int level=game->level;
    int box_num=game->box_num;
    int i,j;
    const Item_type (*ref_grid) [Board_w]=NULL;
    switch (level)
    { //init
    case 1:
        ref_grid=level1;
        break;
    case 2:
        ref_grid=level2;
        break;
    case 3:
        ref_grid=level3;
        break;
    default:
        break;
    }
    // copy grid
    for(i=0;i<Board_h;i++){
        for(j=0;j<Board_w;j++){
            game->data.grid[i][j]=ref_grid[i][j];
            if(ref_grid[i][j]==pla){
                game->data.player_pos[0]=j;
                game->data.player_pos[1]=i;
            }
        }
    }
    // randomly generate boxes and targets
    int x,y;
    for(i=0;i<box_num;i++){
        do{
            x=rand()%(Board_w-4)+2;
            y=rand()%(Board_h-4)+2;
        }while(game->data.grid[y][x]!=e);
        game->data.grid[y][x]=box;
        //generate target
        do{
            x=rand()%(Board_w-4)+2;
            y=rand()%(Board_h-4)+2;
        }while(game->data.grid[y][x]!=e);
        game->data.grid[y][x]=tar;
    }
}
// draw 8x8
void GamePoint2LCD(int x, int y, u16 color){
    LCD_DrawPoint_8x8((x-1)*block_size,(y-1)*block_size,color);
}

void Game_lcd_draw(Game* game){
    int i,j;
    LCD_Clear(BLACK);
    for(i=1;i<Board_h-1;i++){
        for(j=1;j<Board_w-1;j++){
            switch (game->data.grid[i][j]) // draw the whole game
            {
            case obs:
                LCD_ShowPicture8x8((j-1)*block_size,(i-1)*block_size,obs);
                break;
            case pla:
            case player_box_target:
                LCD_ShowPicture8x8((j-1)*block_size,(i-1)*block_size,pla);
                break;
            case box:
                LCD_ShowPicture8x8((j-1)*block_size,(i-1)*block_size,box);
                // GamePoint2LCD(j,i,RED);
                break;
            case tar:
                LCD_ShowPicture8x8((j-1)*block_size,(i-1)*block_size,tar);
                // GamePoint2LCD(j,i,BLUE);
                break;
            case box_target:
                LCD_ShowPicture8x8((j-1)*block_size,(i-1)*block_size,box_target);
                // GamePoint2LCD(j,i,GREEN);
                break;
            default:
                break;
            }
        }
    }
}

void Game_lcd_single_draw(Game* game,int x,int y){
    switch (game->data.grid[y][x])
    { //draw the updated part
    case obs:
        LCD_ShowPicture8x8((x-1)*block_size,(y-1)*block_size,obs);
        break;
    case pla:
    case player_box_target:
        LCD_ShowPicture8x8((x-1)*block_size,(y-1)*block_size,pla);
        break;
    case box:
        LCD_ShowPicture8x8((x-1)*block_size,(y-1)*block_size,box);
        // GamePoint2LCD(x,y,RED);
        break;
    case tar:
        LCD_ShowPicture8x8((x-1)*block_size,(y-1)*block_size,tar);
        // GamePoint2LCD(x,y,BLUE);
        break;
    case box_target:
        LCD_ShowPicture8x8((x-1)*block_size,(y-1)*block_size,box_target);
        // GamePoint2LCD(x,y,GREEN);
        break;
    case e:
        GamePoint2LCD(x,y,BLACK);
        break;
    default:
        break;
    }
}

void Game_init(Game* game){ //make sure all the data and input are plain/zero + level selection
    Button_input_initialize(&game->input);
    game->state = Select_stage;
    /*TODO：and initialize all data……*/
    
    /*level selection */
    //At this stage, we will get the level information, and set (level number+ # of boxes) to our game.
    int level,boxes;
    /*TODO： get the above two int*/
    select_stage(&level,&boxes);
    game->level = level;
    game->box_num=boxes;
    game->data.remain_boxes = boxes;
    game->data.mov_num = 0;
    Game_grid_init(game);
    Game_lcd_draw(game);
}

void Button_input_update(Button_input* input){
    input->down = Get_Button(JOY_DOWN);
    input->right = Get_Button(JOY_RIGHT);
    input->left = Get_Button(JOY_LEFT);
    input->up = Get_Button(JOY_CTR);
    input->confirm = Get_Button(BUTTON_1);
    //if dir is pulled
    input->isPulled = (input->down || input->right || input->left || input->up);
}

void Game_update(Game* game){
    Button_input_update(&game->input);
    int x=game->data.player_pos[0];
    int y=game->data.player_pos[1];
    int dx=0,dy=0;
    /*TODO：and more……*/
    if(game->input.isPulled){
        game->data.mov_num++;
        if(game->input.down){
            /*TODO：*/
            dy=1;
        }
        else if(game->input.up){
            /*TODO：*/
            dy=-1;
        }
        else if(game->input.left){
            /*TODO：*/
            dx=-1;
        }
        else if(game->input.right){
            /*TODO：*/
            dx=1;
        }
        int nx=x+dx,ny=y+dy;
        if(game->data.grid[ny][nx]==e || game->data.grid[ny][nx]==box_target){
            // go to an empty cell or a target cell with a box
            game->data.grid[y][x]-=1;
            game->data.grid[ny][nx]+=1;
            game->data.player_pos[0]=nx;
            game->data.player_pos[1]=ny;
            Game_lcd_single_draw(game,x,y);
            Game_lcd_single_draw(game,nx,ny);
        }
        else if(game->data.grid[ny][nx]==box){
            int nnx=nx+dx,nny=ny+dy;
            if(game->data.grid[nny][nnx]==e || game->data.grid[nny][nnx]==tar){
                // push a box to an empty cell or a target cell
                game->data.grid[y][x]-=1;
                game->data.grid[ny][nx]-=1; //box->player
                if (game->data.grid[nny][nnx]==e)
                    game->data.grid[nny][nnx]=box;
                else if (game->data.grid[nny][nnx]==tar){
                    game->data.grid[nny][nnx]=box_target;
                    game->data.remain_boxes--;
                }
                game->data.player_pos[0]=nx;
                game->data.player_pos[1]=ny;
                //only draw updated part
                Game_lcd_single_draw(game,x,y);
                Game_lcd_single_draw(game,nx,ny);
                Game_lcd_single_draw(game,nnx,nny);
                if(game->data.remain_boxes==0){
                    game->state = Winning;
                }
            }
        }
        int len=1;// show the number of moves
        if(game->data.mov_num>9)    len=2;
        else if (game->data.mov_num>99)   len=3;
        else if (game->data.mov_num>999)   len=4;
        LCD_ShowNum(100,0,game->data.mov_num,len,WHITE);
    }
    /*TODO：and more……*/
}