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
    	HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "Mode: Automatic mode\r\n"), 1000);

    	resetLights();
    	/* INACTIVE pedestrian light when in INIT state */
    	pedestrian_status = PEDESTRIAN_INACTIVE;

        traffic_status = RED_GREEN;
        HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "RED   GREEN\r\n"), 1000);

        setTimer(1, green_counter);

		setTimer(3, 250); 		// timer 3 for counting light

        counter_light_1 = red_counter / 1000;
        counter_light_2 = green_counter / 1000;
        counter_lights = READ_UART;

        break;

    case RED_GREEN:
    	setRedLight1(0);
    	setGreenLight2(0);

        if (timer_flag[1] == 1) {
            traffic_status = RED_AMBER;
            HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "RED   AMBER\r\n"), 1000);
            setTimer(1, amber_counter);

            counter_light_2 = amber_counter / 1000;
        }    

        break;

    case RED_AMBER:
    	setRedLight1(0);
    	setAmberLight2(0);

        if (timer_flag[1] == 1) {
            traffic_status = GREEN_RED;
            HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "GREEN   RED\r\n"), 1000);
            setTimer(1, green_counter);

            counter_light_1 = green_counter / 1000;
            counter_light_2 = red_counter / 1000;

            /* INACTIVE pedestrian light when traffic light is backing to GREEN_RED mode */
            pedestrian_status = PEDESTRIAN_INACTIVE;
        }

        break;

    case GREEN_RED:
    	setGreenLight1(0);
    	setRedLight2(0);

        if (timer_flag[1] == 1) {
            traffic_status = AMBER_RED;
            HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "AMBER   RED\r\n"), 1000);
            setTimer(1, amber_counter);

            counter_light_1 = amber_counter / 1000;
        }

        break;

    case AMBER_RED:
    	setAmberLight1(0);
    	setRedLight2(0);

        if (timer_flag[1] == 1) {
            traffic_status = RED_GREEN;
            HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "RED   GREEN\r\n"), 1000);
            setTimer(1, green_counter);

            counter_light_1 = red_counter / 1000;
            counter_light_2 = green_counter / 1000;

            /* If the pedestrian light is PEDESTRIAN_RED, change to PEDESTRIAN_GREEN when the traffic light is backing to RED_GREEN mode */
            /* If the pedestrian light is INACTIVE => no change */
            if(pedestrian_status == PEDESTRIAN_RED){
            	pedestrian_status = PEDESTRIAN_GREEN;
            }
        }
        break;
    }
}
