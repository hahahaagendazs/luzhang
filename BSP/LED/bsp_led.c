#include "bsp_led.h"

#define led_lightting  GPIO_PIN_RESET
#define led_extinguish GPIO_PIN_SET

// 状态机
typedef enum
{
    init,
    idle,
    lightting
}led_status;

// 初始状态是 init 
led_status led_s = init;

// 超时
uint16_t led_time = 0x0000;

led_status getStatus(void)
{
    return led_s;
};

void led_setLedMode_lightting_1s(void)
{
    led_time = 0x0000;
    led_s=lightting;
    HAL_GPIO_WritePin(LED_MODE_GPIO_Port,  LED_MODE_Pin,  led_lightting);
}

void led_main(void)
{
    HAL_GPIO_WritePin(LED_POWER_GPIO_Port, LED_POWER_Pin, led_lightting);
    HAL_GPIO_WritePin(LED_MODE_GPIO_Port,  LED_MODE_Pin,  led_lightting);
}
/**
 * @brief loop中不能加延时
 */
void Led_Loop(void)
{     
    static uint8_t led_idle_time = 0x00;

    if (led_s == init)
    {
        if ( ++led_time == 0xFFFF )
        {
            led_s = idle;
            led_time = 0x0000;
            // 熄灭
            HAL_GPIO_WritePin(LED_POWER_GPIO_Port, LED_POWER_Pin, led_extinguish);
            HAL_GPIO_WritePin(LED_MODE_GPIO_Port, LED_MODE_Pin, led_extinguish);
        }
    }
    else if(led_s==lightting)
    {
        if( ++led_time == 0xFFFF )
        {
            led_s=idle;
            led_time = 0x0000;
            // 熄灭
            HAL_GPIO_WritePin(LED_POWER_GPIO_Port, LED_POWER_Pin, led_extinguish);
            HAL_GPIO_WritePin(LED_MODE_GPIO_Port, LED_MODE_Pin, led_extinguish);
        }
    }
    else if(led_s ==idle)
    {
        if( ++led_time == 0xFFFF )
        {
            led_time = 0x0000;
            HAL_GPIO_WritePin(LED_POWER_GPIO_Port, LED_POWER_Pin, led_extinguish);
            if( ++led_idle_time == 0x6F )
            {
                led_idle_time = 0x00;
                HAL_GPIO_WritePin(LED_POWER_GPIO_Port, LED_POWER_Pin, led_lightting);
            }
        }
    }
}
