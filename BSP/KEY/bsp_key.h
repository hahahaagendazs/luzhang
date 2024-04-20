#ifndef BSP_KEY_H
#define BSP_KEY_H

#include "gpio.h"

// 状态机
typedef enum
{
    key_idle,
    key_pressed
}key_status;

void Key_Loop(void);

#endif


