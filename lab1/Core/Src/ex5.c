/*
 * ex5.c
 *
 *  Created on: Sep 18, 2024
 *      Author: Admin
 */
#include "ex5.h"

int led_status_1 = LED_GREEN_ON;
int led_status_2 = LED_RED_ON;
int countdown1 = 3;
int countdown2 = 5;

const uint8_t digits[10][7] = {
    {0, 0, 0, 0, 0, 0, 1},  // 0
    {1, 0, 0, 1, 1, 1, 1},  // 1
    {0, 0, 1, 0, 0, 1, 0},  // 2
    {0, 0, 0, 0, 1, 1, 0},  // 3
    {1, 0, 0, 1, 1, 0, 0},  // 4
    {0, 1, 0, 0, 1, 0, 0},  // 5
    {0, 1, 0, 0, 0, 0, 0},  // 6
    {0, 0, 0, 1, 1, 1, 1},  // 7
    {0, 0, 0, 0, 0, 0, 0},  // 8
    {0, 0, 0, 0, 1, 0, 0}   // 9
};

void setDigit_1(int digit) {
    HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, digits[digit][0] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, digits[digit][1] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, digits[digit][2] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, digits[digit][3] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, digits[digit][4] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, digits[digit][5] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, digits[digit][6] ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void setDigit_2(int digit) {
    HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, digits[digit][0] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, digits[digit][1] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, digits[digit][2] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, digits[digit][3] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, digits[digit][4] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, digits[digit][5] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, digits[digit][6] ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void setLED(int state, GPIO_TypeDef* green, GPIO_TypeDef* yellow, GPIO_TypeDef* red, uint16_t greenPin, uint16_t yellowPin, uint16_t redPin) {
    HAL_GPIO_WritePin(green, greenPin, state == LED_GREEN_ON ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(yellow, yellowPin, state == LED_YELLOW_ON ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(red, redPin, state == LED_RED_ON ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void init_ex5() {
    countdown1 = 3;
    countdown2 = 5;
}

void run_ex5() {

    setDigit_1(countdown1);
    setDigit_2(countdown2);

    setLED(led_status_1, LED1_GPIO_Port, LED2_GPIO_Port, LED3_GPIO_Port, LED1_Pin, LED2_Pin, LED3_Pin);
    setLED(led_status_2, LED4_GPIO_Port, LED5_GPIO_Port, LED6_GPIO_Port, LED4_Pin, LED5_Pin, LED6_Pin);

    if (--countdown1 == 0) {
        switch (led_status_1) {
            case LED_GREEN_ON: countdown1 = 2; led_status_1 = LED_YELLOW_ON; break;
            case LED_YELLOW_ON: countdown1 = 5; led_status_1 = LED_RED_ON; break;
            case LED_RED_ON: countdown1 = 3; led_status_1 = LED_GREEN_ON; break;
        }
    }

    if (--countdown2 == 0) {
        switch (led_status_2) {
            case LED_GREEN_ON: countdown2 = 2; led_status_2 = LED_YELLOW_ON; break;
            case LED_YELLOW_ON: countdown2 = 5; led_status_2 = LED_RED_ON; break;
            case LED_RED_ON: countdown2 = 3; led_status_2 = LED_GREEN_ON; break;
        }
    }
}
