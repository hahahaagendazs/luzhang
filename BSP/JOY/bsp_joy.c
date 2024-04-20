#include "bsp_joy.h"
#include "bsp_dbg.h"
#include <stdlib.h>

uint8_t    joy_LX;
uint8_t    joy_LY;
uint8_t    joy_RX;
uint8_t    joy_RY;

uint32_t joy_time = 0;

#define  ADC_MAX_NUM  (uint8_t)30U
uint16_t ADC_Values[ADC_MAX_NUM] = { 0U };

// uint16_t joy_adc_value = (uint8_t) 0x0000U;
// uint16_t joy_adc_value_IT[ADC_MAX_NUM] = { 0x0000 };
// uint8_t  joy_adc_value_IT_count = 0;
// uint8_t  joy_adc_value_IT_flag = 0;
// uint8_t  str[11] = "";

// blocking赋值
// uint16_t joy_get_adc(void)
// {
//     //开启ADC1
//     HAL_ADC_Start(&hadc);
//     //等待ADC转换完成，超时为30ms
//     HAL_ADC_PollForConversion(&hadc, 30);
//     //判断ADC是否转换成功
//     if (HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc), HAL_ADC_STATE_REG_EOC))
//     {
//         //读取值
//         return (uint16_t) HAL_ADC_GetValue(&hadc);
//     }
//     //关闭ADC1
//     // HAL_ADC_Stop(&hadc);
//     return (uint32_t) 0;
// }

//启动函数，需要在main中调用一次
void joy_adc_start_DMA(void)
{
    //启动DMA
    HAL_ADC_Start_DMA(&hadc, (uint32_t*) ADC_Values, ADC_MAX_NUM);
    // HAL_DMA_GetState(DMA1);
}


void joy_main(void)
{
    joy_adc_start_DMA();
    HAL_TIM_Base_Start_IT(&htim6);
}

// void uint32_to_str(uint32_t number, char* str, uint8_t base)
// {
//     // itoa(number, str, base);
// }

void joy_loop(void)
{
    // static uint8_t i = 0;
    if (++joy_time >= 0x000E0000)
    {
        joy_time = 0;
        // joy_adc_value = joy_get_adc();
    }
    // if (joy_adc_value_IT_flag == 1)
    // {
    //     joy_adc_value_IT_flag = 0;
    // }
}

//ADC转换完成自动调用函数
// void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
// {
//     static uint8_t  i = 0;
//     //获取值并存储
//     joy_adc_value[&i] = (uint16_t)HAL_ADC_GetValue(hadc);

//     if (++i == ADC_MAX_NUM)
//     {
//         //清零下标
//         i = 0;
//         //次数统计
//         if(++joy_adc_value_IT_count >= 0x0A)
//         {
//             // 在main-while中清零
//             joy_adc_value_IT_flag = 1;
//         };
//     }
// }


// void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
// {
    // uart_send((uint8_t*)"1121\n");
    // HAL_ADC_Stop(hadc);
// }
// HAL_ADC_PollForConversion();
// HAL_ADC_GetValue();




