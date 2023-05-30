#include "utils.h"
#include "gd32vf103_libopt.h"

#include <stdio.h>
/* -----------------------------
 Description: Return 1 if button number ch is pressed
 			  Return 0 otherwise
----------------------------- */

uint64_t get_time(void)
{
  uint64_t start_mtime, delta_mtime;
  // Don't start measuruing until we see an mtime tick
  uint64_t tmp = get_timer_value();
  return tmp;
//
//  do {
//    start_mtime = get_timer_value();
//  } while (start_mtime == tmp);
//
//  do {
//    delta_mtime = get_timer_value() - start_mtime;
//  }while(delta_mtime <(SystemCoreClock/4000.0 *count ));
}
float delta_time(uint64_t start) {
  /*return in s*/
  uint64_t delta_mtime;
  delta_mtime=get_time() - start;

  return delta_mtime/(SystemCoreClock/4.0);
}


char test[50];
int last = -1;
uint64_t last_time = 0;
int Get_Button(int ch)
{
  /*TODO: unchecked*/
  /* hack for new board*/
  /* if same button and in 0.3s, not trigger */
  if (ch != GPIO_PIN_13)
    return (int)(gpio_input_bit_get(GPIOA, ch));
  else
    return (int)(gpio_input_bit_get(GPIOC, ch));

  if (ch == last && delta_time(last_time) < 0.3) {
    return 0;
  }
  int ret;
  /* special judge for PIN*/
  if (ch != GPIO_PIN_13) {
    ret= (int) (gpio_input_bit_get(GPIOA, ch));
  }
  else{
    ret=(int)(gpio_input_bit_get(GPIOC, ch));
  }
  /*update last button and time*/
  if(ret){
    last = ch;
    last_time = get_time();
  }
//  sprintf(test, "ret: %d", ret);
//  LCD_ShowString(70,25,test,0xFFFF);
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