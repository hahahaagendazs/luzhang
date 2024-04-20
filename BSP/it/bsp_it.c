#include "bsp_it.h"
#include "main.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"


/**
 * @brief 串口 重写RX中断事件回调函数
 * @param huart UART handle
 * @param Size  Number of data available in application reception buffer (indicates a position in
 *               reception buffer until which, data are available) 表示接受到不定长数据的长度是Size
 */
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef* huart, uint16_t Size)
{
    // dbg串口
    if (huart == &DBG_UART)
    {   // 做什么 

        // 调试   发送到dbg串口
        // dbg_send2_DMA(dbg_datarev_buff, Size);
        // ble_send((uint8_t*)dbg_datarev_buff );

        // JDY 中断处理 设置标记位 让 JDY 接管
        jdy_it_dbg_handle();

        // 再次开启DMA不定长空闲中断接受
        dbg_recv_start_DMA();
    }
    // ble串口
    else if (huart == &BLE_UART)
    {   // 做什么
        
        // 调试   发送到dbg串口
        dbg_send("\r\n----BT:\r\n");
        dbg_send2_DMA(ble_datarev_buff, Size);

        //JDY 中断处理 让 JDY 接管
        jdy_it_ble_handle();

        // 再次开启DMA不定长空闲中断接受
        ble_recv_start_DMA();
    }
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    UNUSED(htim);
}
