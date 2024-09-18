/*
 * ex1.c
 *
 *  Created on: Sep 18, 2024
 *      Author: Admin
 */


#include "ex1.h"

int LED_status = LED_OFF;
void init_ex1(){
}

void led_on(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
}
void led_off(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
}
void run_ex1(){
	switch(LED_status){
		case LED_ON:
			led_on();
			if(1){
				LED_status = LED_OFF;
			}
			break;
		case LED_OFF:
			led_off();
			if(1){
				LED_status = LED_ON;
			}
			break;
		default:
			break;
	}
}
