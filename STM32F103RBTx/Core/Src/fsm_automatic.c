/*
 * fsm_automatic.c
 *
 *  Created on: 21 thg 11, 2023
 *      Author: ProX
 */

#include "fsm_automatic.h"

void fsm_automatic_run(UART_HandleTypeDef huart2) {
    /* CHANGE TO MANUAL MODE WHEN BUTTON1 IS PRESSED */
    if (isButtonPressed(1)) {
    	status = MANUAL_MODE;
		traffic_status = INIT;
		return;
    }

    switch (traffic_status) {
    case INIT:
    	/* UART COMMUNICATION */
    	HAL_UART_Transmit(&huart2, (uint8_t *)"Mode: Automatic mode\r\n", 24, 500);

    	resetLights();
    	/* INACTIVE pedestrian light when in INIT state */
    	pedestrian_status = PEDESTRIAN_INACTIVE;

        traffic_status = RED_GREEN;
        HAL_UART_Transmit(&huart2, (uint8_t *)"RED GREEN\r\n", 10, 500);

        setTimer(1, green_counter);

		setTimer(6, 1000); 		// timer 3 for counting light

        counter_light_1 = red_counter / 1000;
        counter_light_2 = green_counter / 1000;
        counter_lights = INIT;

        break;

    case RED_GREEN:
    	Red_Green();

        if (timer_flag[1] == 1) {
            traffic_status = RED_AMBER;
            HAL_UART_Transmit(&huart2, (uint8_t *)"RED AMBER\r\n", 16, 500);
            setTimer(1, amber_counter);

            counter_light_1 = amber_counter / 1000;
            counter_light_2 = amber_counter / 1000;
            counter_lights = INIT;
        }    

        break;

    case RED_AMBER:
    	Red_Amber();

        if (timer_flag[1] == 1) {
            traffic_status = GREEN_RED;
            HAL_UART_Transmit(&huart2, (uint8_t *)"GREEN RED\r\n", 16, 500);
            setTimer(1, green_counter);

            counter_light_1 = green_counter / 1000;
            counter_light_2 = red_counter / 1000;
            counter_lights = INIT;

            /* INACTIVE pedestrian light when traffic light is backing to GREEN_RED mode */
            pedestrian_status = PEDESTRIAN_INACTIVE;
        }

        break;

    case GREEN_RED:
    	Green_Red();

        if (timer_flag[1] == 1) {
            traffic_status = AMBER_RED;
            HAL_UART_Transmit(&huart2, (uint8_t *)"AMBER RED\r\n", 16, 500);
            setTimer(1, amber_counter);

            counter_light_1 = amber_counter / 1000;
            counter_light_2 = amber_counter / 1000;
            counter_lights = INIT;
        }

        break;

    case AMBER_RED:
    	Amber_Red();

        if (timer_flag[1] == 1) {
            traffic_status = RED_GREEN;
            HAL_UART_Transmit(&huart2, (uint8_t *)"RED GREEN\r\n", 16, 500);
            setTimer(1, green_counter);

            counter_light_1 = red_counter / 1000;
            counter_light_2 = green_counter / 1000;
            counter_lights = INIT;

            /* If the pedestrian light is PEDESTRIAN_RED, change to PEDESTRIAN_GREEN when the traffic light is backing to RED_GREEN mode */
            /* If the pedestrian light is INACTIVE => no change */
            if(pedestrian_status == PEDESTRIAN_RED){
            	HAL_UART_Transmit(&huart2, (uint8_t *)"Pedestrian mode: GREEN\r\n", 24, 500);
            	pedestrian_status = PEDESTRIAN_GREEN;
            }
        }
        break;
    }
}
