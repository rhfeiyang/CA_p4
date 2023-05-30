#include "utils.h"
#include "gd32vf103_libopt.h"
#include "sys/time.h"
/* -----------------------------
 Description: Return 1 if button number ch is pressed
 			  Return 0 otherwise
----------------------------- */
struct timeval timstr;
float get_time(void)
{
  gettimeofday(&timstr, NULL);
  return (timstr.tv_sec + (timstr.tv_usec / 1000000.0));
}

int last = -1;
float last_time = 0;
int Get_Button(int ch)
{
  /*TODO: unchecked*/
  /* hack for new board*/
  /* if same button and in 0.3s, not trigger */
  if (ch == last && get_time() - last_time < 0.3) {
    return 0;
  }
  int ret;
  /* special judge for PIN*/
  if (ch != GPIO_PIN_13) {
    int ret= (int) (gpio_input_bit_get(GPIOA, ch));
  }
  else{
    int ret=(int)(gpio_input_bit_get(GPIOC, ch));
  }
  /*update last button and time*/
  if(ret){
    last = ch;
    last_time = get_time();
  }
  return ret;
}

/* -----------------------------
 Description: Return 1 if button BOOT0 ch is pressed
 			  Return 0 otherwise
----------------------------- */
int Get_BOOT0(void)
{
    return (int)(gpio_input_bit_get(GPIOA, GPIO_PIN_8));
}

#pragma region Button_input
void Button_input_initialize(Button_input* input){
    input->down = 0;
    input->right = 0;
    input->left = 0;
    input->up = 0;
    input->confirm = 0;
    input->isPulled = 0;
}
void Button_input_update(Button_input* input){
    if(input->isPulled){
        delay_1ms(300); // this should solve Input Keys Debouncing
    }
    input->down = Get_Button(JOY_DOWN);
    input->right = Get_Button(JOY_RIGHT);
    input->left = Get_Button(JOY_LEFT);
    input->up = Get_Button(JOY_CTR);
    input->confrim = Get_Button(BUTTON_1);
    if(input->down || input->right || input->left || input->up || input->confirm){
        input->isPulled = 1;
    }else{
        input->isPulled = 0;
    }
}
#pragma endregion

#pragma region Data


#pragma endregion