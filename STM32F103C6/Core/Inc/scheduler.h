/*
 * scheduler.h
 *
 *  Created on: Dec 7, 2023
 *      Author: HP
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>



void SCH_Update(void);
void SCH_Add_Task(void (*funcPointer)(), uint32_t delay, uint32_t period);
void SCH_Delete_Task(uint32_t);
void SCH_Dispatch_Tasks(void);

#endif /* INC_SCHEDULER_H_ */
