/*
 * ex3.c
 *
 *  Created on: Sep 18, 2024
 *      Author: Admin
 */
#include "ex3.h"

int led_status_1 = LED_GREEN_ON;
int led_status_2 = LED_RED_ON;
int cnt1 = 0;
int cnt2 = 0;

void straight_green(){
    HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
}

void straight_yellow(){
    HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
}

void straight_red(){
    HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
}

void horizontal_green(){
    HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
}

void horizontal_yellow(){
    HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_SET);
}

void horizontal_red(){
    HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, GPIO_PIN_RESET);
}

void init_ex3(){
}

void run_ex3(){

    switch(led_status_1){
    case LED_GREEN_ON:
        straight_green();
        ++cnt1;
        if(cnt1 == 3){
            cnt1 = 0;
            led_status_1 = LED_YELLOW_ON;
        }
        break;
    case LED_YELLOW_ON:
        straight_yellow();
        ++cnt1;
        if(cnt1 == 2){
            cnt1 = 0;
            led_status_1 = LED_RED_ON;
        }
        break;
    case LED_RED_ON:
        straight_red();
        ++cnt1;
        if(cnt1 == 5){
            cnt1 = 0;
            led_status_1 = LED_GREEN_ON;
        }
        break;
    default:
        break;
    }

    switch(led_status_2){
    case LED_RED_ON:
        horizontal_red();
        ++cnt2;
        if(cnt2 == 5){
            cnt2 = 0;
            led_status_2 = LED_GREEN_ON;
            led_status_1 = LED_RED_ON;
        }
        break;
    case LED_GREEN_ON:
        horizontal_green();
        ++cnt2;
        if(cnt2 == 3){
            cnt2 = 0;
            led_status_2 = LED_YELLOW_ON;
        }
        break;
    case LED_YELLOW_ON:
        horizontal_yellow();
        ++cnt2;
        if(cnt2 == 2){
            cnt2 = 0;
            led_status_2 = LED_RED_ON;
            led_status_1 = LED_GREEN_ON;
        }
        break;
    default:
        break;
    }
}
