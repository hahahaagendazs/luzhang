#include "bsp_key.h"
#include "bsp_led.h"
#include "bsp_dbg.h"
#include "ble_at.h"

#define KEY_ON  0
#define KEY_OFF 1



uint32_t    key_time = 0x00000000;
extern uint32_t    clk ;
extern uint16_t    flag;
key_status  key_s = key_idle;

void timeout(void)
{
    key_time += 1;
    // 超时 20ms 之内只能被按一次 防止出错 主频32MHz 
    if(key_time >= 0x00013880)
    {
        key_s = key_idle;
        key_time = 0x0000;
    }
}



/**
 * @brief   检测是否有按键按下
 * @param  GPIOx:具体的端口, x可以是（A...K）
 * @param  GPIO_PIN:具体的端口位， 可以是GPIO_PIN_x（x可以是0...15）
 * @retval  按键的状态
 *     @arg KEY_ON:按键按下
 *     @arg KEY_OFF:按键没按下
*/
uint8_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    /*检测是否有按键按下 */
    if (HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == KEY_ON)
    {
        /*等待按键释放 */
        while (HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == KEY_ON);
        return  KEY_ON;
    }
    else
        return KEY_OFF;
}

/**
 * @brief loop 放在main的while中，不能有延时
 *        查询的方式进行按键检测(非中断的方式)
 * @param
 */
void Key_Loop(void)
{
    if (key_s == key_idle)
    {
        // 上下左右
        if (Key_Scan(KEY_UP_GPIO_Port, KEY_UP_Pin) == KEY_ON)
        {
            key_s = key_pressed;
            dbg_send_DMA((uint8_t*)"/up");
            
            // 测试 触发 
            // jdy_AT_OKcheck();
            
        }

        else if (Key_Scan(KEY_DOWN_GPIO_Port, KEY_DOWN_Pin) == KEY_ON)
        {
            key_s = key_pressed;
            dbg_send_DMA((uint8_t*)"/down");
        }

//        else if (Key_Scan(KEY_LEFT_GPIO_Port, KEY_LEFT_Pin) == KEY_ON)
//        {
//            key_s = key_pressed;
//            dbg_send_DMA((uint8_t*)"/Left");
//        }

        else if (Key_Scan(KEY_RIGHT_GPIO_Port, KEY_RIGHT_Pin) == KEY_ON)
        {
            key_s = key_pressed;
            dbg_send_DMA((uint8_t*)"/right");
        }

        // 左边四个按键 
        else if (Key_Scan(KEY_FORK_GPIO_Port, KEY_FORK_Pin) == KEY_ON)
        {
            key_s = key_pressed;
            dbg_send_DMA((uint8_t*)"/Fork");
        }

        else if (Key_Scan(KEY_CIRCLE_GPIO_Port, KEY_CIRCLE_Pin) == KEY_ON)
        {
            key_s = key_pressed;
            dbg_send_DMA((uint8_t*)"/Circle");
        }

        else if (Key_Scan(KEY_SQUARE_GPIO_Port, KEY_SQUARE_Pin) == KEY_ON)
        {
            key_s = key_pressed;
            dbg_send_DMA((uint8_t*)"/Square");
        }

        else if (Key_Scan(KEY_TRIANGLE_GPIO_Port, KEY_TRIANGLE_Pin) == KEY_ON)
        {
            key_s = key_pressed;
            dbg_send_DMA((uint8_t*)"/Triangle");
        }

        // 中间三个按键
        else if (Key_Scan(KEY_MODE_GPIO_Port, KEY_MODE_Pin) == KEY_ON)
        {
            key_s = key_pressed;
            led_setLedMode_lightting_1s();
            dbg_send_DMA((uint8_t*)"/Mode");
        }

        else if (Key_Scan(KEY_SELECT_GPIO_Port, KEY_SELECT_Pin) == KEY_ON)
        {
            key_s = key_pressed;
            dbg_send_DMA((uint8_t*)"/Select");
        }

        else if (Key_Scan(KEY_START_GPIO_Port, KEY_START_Pin) == KEY_ON)
        {
            key_s = key_pressed;
            dbg_send_DMA((uint8_t*)"/Start");
        }

        // 旋钮上两个按键 R3 L3
        else if (Key_Scan(KEY_R3_GPIO_Port, KEY_R3_Pin) == KEY_ON)
        {
            key_s = key_pressed;
            dbg_send_DMA((uint8_t*)"/R3");
        }

        else if (Key_Scan(KEY_L3_GPIO_Port, KEY_L3_Pin) == KEY_ON)
        {
            key_s = key_pressed;
            dbg_send_DMA((uint8_t*)"/L3");
        }

        // 扳机 R1 R2 L1 L2
        else if (Key_Scan(KEY_L1_GPIO_Port, KEY_L1_Pin) == KEY_ON)
        {
            key_s = key_pressed;
            dbg_send_DMA((uint8_t*)"/L1");
        }

        else if (Key_Scan(KEY_L2_GPIO_Port, KEY_L2_Pin) == KEY_ON)
        {
            key_s = key_pressed;
            dbg_send_DMA((uint8_t*)"/L2");
        }

        else if (Key_Scan(KEY_R1_GPIO_Port, KEY_R1_Pin) == KEY_ON)
        {
            key_s = key_pressed;
            dbg_send_DMA((uint8_t*)"/R1");
        }

        else if (Key_Scan(KEY_R2_GPIO_Port, KEY_R2_Pin) == KEY_ON)
        {
            key_s = key_pressed;
            dbg_send_DMA((uint8_t*)"/R2");
        }
        else
        {
            clk+=1;
            if(clk>=0x000000FF)
            {
                flag=0x0001;
            }
        }
    }
    else if (key_s == key_pressed)
    {
        timeout();
    }

}




/**
 * @brief 虚函数回调函数重写，外部中断发生时执行，中断（非阻塞性）
 * @param GPIO_Pin
 */
 // void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
 // {
 // if (GPIO_Pin == KEY_GPIO_PIN)
 // {
 //   HAL_TIM_Base_Start_IT(&htim1);
 // }
 // }


