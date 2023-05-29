#include "utils.h"
#include "gd32vf103_libopt.h"

/* -----------------------------
 Description: Return 1 if button number ch is pressed
 			  Return 0 otherwise
----------------------------- */
int Get_Button(int ch)
{
    /*maybe we can acheive Input Keys Debouncing in the Button_input_update function */
    return (int)(gpio_input_bit_get(GPIOA, ch));
    /*TODO:what's the difference between GPIOA and GPIOC in the above function?*/
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