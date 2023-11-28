/*
 * fsm_manual.c
 *
 *  Created on: 21 thg 11, 2023
 *      Author: ProX
 */

#include "fsm_manual.h"

void fsm_manual_run(void) {
	switch (traffic_status) {
	case MAN_RED:
		/* TURN OFF LIGHTS */
		light_Off();
		setTimer(1, 500);

		/* BLINK LEDs */
		if (timer_flag[1] == 1) {
			HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
			HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin);
			setTimer(1, 500);
		}

		/* OUT OF TIME FOR MANUAL EVENTS */
		if (timer_flag[0] == 1) {
			status = AUTOMATIC_MODE;
			traffic_status = INIT;
		}

		/* CHANGE MODE = 3 (MAN_AMBER) WHEN BUTTON1 IS PRESSED */
		if (isButtonPressed(1)) {
			traffic_status = MAN_AMBER;
			setTimer(0, 5000);	// reuse timer 0 to 5 seconds for manual event
		}

		/* MODIFY TIME LENGTH */
		if (isButtonPressed(2)) {
			status = TUNING_MODE;
		}

		/* CONFIRM TIME LENGTH */
		if (isButtonPressed(3)) {
			red_counter = time_modify_counter;
		}

		break;

	case MAN_AMBER:
		/* TURN OFF LIGHTS */
		light_Off();
		setTimer(1, 500);

		/* BLINK LEDs */
		if (timer_flag[1] == 1) {
			HAL_GPIO_TogglePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin);
			HAL_GPIO_TogglePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin);
			setTimer(1, 500);
		}

		/* OUT OF TIME FOR MANUAL EVENTS */
		if (timer_flag[0] == 1) {
			status = AUTOMATIC_MODE;
			traffic_status = INIT;
		}

		/* CHANGE MODE = 4 (MAN_GREEN) WHEN BUTTON1 IS PRESSED */
		if (isButtonPressed(1)) {
			traffic_status = MAN_GREEN;
			setTimer(0, 5000);	// reuse timer 0 to 5 seconds for manual event
		}

		/* MODIFY TIME LENGTH */
		if (isButtonPressed(2)) {
			status = TUNING_MODE;
		}

		/* CONFIRM TIME LENGTH */
		if (isButtonPressed(3)) {
			amber_counter = time_modify_counter;
		}

		break;

	case MAN_GREEN:
		/* TURN OFF LIGHTS */
		light_Off();
		setTimer(1, 500);

		/* BLINK LEDs */
		if (timer_flag[1] == 1) {
			HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
			HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin);
			setTimer(1, 500);
		}

		/* OUT OF TIME FOR MANUAL EVENTS */
		if (timer_flag[0] == 1) {
			status = AUTOMATIC_MODE;
			traffic_status = INIT;
		}

		/* CHANGE MODE = 1 (AUTOMATIC) WHEN BUTTON1 IS PRESSED */
		if (isButtonPressed(1)) {
			status = AUTOMATIC_MODE;
			traffic_status = INIT;
		}

		/* MODIFY TIME LENGTH */
		if (isButtonPressed(2)) {
			status = TUNING_MODE;
		}

		/* CONFIRM TIME LENGTH */
		if (isButtonPressed(3)) {
			green_counter = time_modify_counter;
		}
		break;
	default: // change traffic state to MAN_RED when change from AUTOMATIC to MANUAL
		traffic_status = MAN_RED;
		break;
	}
}
