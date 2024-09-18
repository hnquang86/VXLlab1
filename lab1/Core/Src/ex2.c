/*
 * ex2.c
 *
 *  Created on: Sep 18, 2024
 *      Author: Admin
 */

#include "ex2.h"

int led_status = LED_GREEN_ON;
int cnt = 0;

void init_ex2(){
}
void led_red_on()
{
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_SET);
}

void led_yellow_on()
{
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_SET);
}

void led_GREEN_on()
{
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
}
void run_ex2()
{
	switch(led_status){
		case LED_RED_ON:
			led_red_on();
			++cnt;
			if(cnt == 5){
				cnt = 0;
				led_status = LED_GREEN_ON;
			}
			break;
		case LED_GREEN_ON:
			led_GREEN_on();
			++cnt;
			if(cnt == 3){
				cnt = 0;
				led_status = LED_YELLOW_ON;
			}
			break;
		case LED_YELLOW_ON:
			led_yellow_on();
			++cnt;
			if(cnt == 2){
				cnt = 0;
				led_status = LED_RED_ON;
			}
			break;
		default:
			break;
	}


}
