/**
  ****************************(C) COPYRIGHT 2019 DJI****************************
  * @file       can_receive.c/h
  * @brief      there is CAN interrupt function  to receive motor data,
  *             and CAN send function to send motor current to control motor.
  *             这里是CAN中断接收函数，接收电机数据,CAN发送函数发送电机电流控制电机.
  * @note       
  * @history
  *  Version    Date            Author          Modification
  *  V1.0.0     Dec-26-2018     RM              1. done
  *
  @verbatim
  ==============================================================================

  ==============================================================================
  @endverbatim
  ****************************(C) COPYRIGHT 2019 DJI****************************
  */

#include "CAN_receive.h"
#include "main.h"
#include "stdio.h"


extern CAN_HandleTypeDef hcan1;


static CAN_TxHeaderTypeDef  arm_tx_message;
uint8_t arm_can_tx_data[8];
static CAN_RxHeaderTypeDef  arm_rx_message;
uint8_t arm_can_rx_data[8];

//上位机发送的步进电机转动角度
static uint8_t can_set_motor_angle[5];
static uint8_t can_motor_angle[5];
/**
  * @brief          hal CAN fifo call back, receive motor data
  * @param[in]      hcan, the point to CAN handle
  * @retval         none
  */
/**
  * @brief          hal库CAN回调函数,接收电机数据
  * @param[in]      hcan:CAN句柄指针
  * @retval         none
  */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    uint8_t rx_data[8];

    HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &arm_rx_message, rx_data);
    
    memcpy(can_set_motor_angle, rx_data, 5);
}



void CAN_feedback_computer(uint8_t test_data)
{
    uint32_t send_mail_box;
    arm_tx_message.StdId = COMPUTER_CAN_ALL_ID;
    arm_tx_message.IDE = CAN_ID_STD;
    arm_tx_message.RTR = CAN_RTR_DATA;
    arm_tx_message.DLC = 0x08;
    arm_can_tx_data[0] = test_data;
    arm_can_tx_data[1] = 0;
    arm_can_tx_data[2] = 0;
    arm_can_tx_data[3] = 0;
    arm_can_tx_data[4] = 0;
    arm_can_tx_data[5] = 0;
    arm_can_tx_data[6] = 0;
    arm_can_tx_data[7] = 0;
    HAL_CAN_AddTxMessage(&COMPUTER_CAN, &arm_tx_message, arm_can_tx_data, &send_mail_box);
}
