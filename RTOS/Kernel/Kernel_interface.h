#ifndef KERNEL_INTERFACE_H
#define KERNEL_INTERFACE_H

void RTOS_voidStart (void);
uint8 Rtos_u8CreateTask(uint8 copy_u8Periority,uint16 copy_u16Periodicity,void(*copy_pvTaskFunction)(void));

#endif