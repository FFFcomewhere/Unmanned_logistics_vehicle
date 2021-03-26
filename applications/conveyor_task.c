#include "conveyor_task.h"


#include "main.h"



#include "detect_task.h"
#include "arm_task.h"
#include "interactive_task.h"


#include "remote_control.h"
#include "struct_typedef.h"
#include "gpio.h"
#include "OLED.h"

extern RC_ctrl_t rc_ctrl;

conveyor_control_t conveyor_control;



/**
  * @brief          传送带任务，间隔 CONVEYOR_CONTROL_TIME_MS 2ms
  * @param[in]      pvParameters: 空
  * @retval         none
  */
void conveyor_task()
{
    //空闲一段时间
    vTaskDelay(CONVEYOR_TASK_INIT_TIME);
    //传送带任务初始化
    conveyor_init(&conveyor_control);
    
    while (1)
    {
        //更新数据
        conveyor_feedback_update(&conveyor_control);
        //设置控制量
        conveyor_set_control(&conveyor_control);
        //传送带任务输出控制值
        conveyor_cmd_control(&conveyor_control);
        //系统延时
        vTaskDelay(CONVEYOR_CONTROL_TIME_MS);
    }
}









/**
  * @brief          传送带任务初始化
  * @param[out]      conveyor_init: 空
  * @retval         none
  */
static void conveyor_init(conveyor_control_t *init)
{
    ;
}



/**
  * @brief          传送带任务数据更新
  * @param[out]      conveyor_data_updata: 空
  * @retval         none
  */
static void conveyor_feedback_update(conveyor_control_t *feedback_update)
{
    feedback_update->light_sensor = !HAL_GPIO_ReadPin(light_sensor_GPIO_Port, light_sensor_Pin);
    feedback_update->convetor_status = feedback_update->convertor_set;
}



/**
  * @brief           传送带任务设置控制值
  * @param[out]      converyor_set: 空
  * @retval         none
  */
static void conveyor_set_control(conveyor_control_t *set_control)
{

    //遥控器测试
    if (switch_is_up(rc_ctrl.rc.s[CONVEYOR_CHANNEL]))
        set_control->convertor_set = TRUE;
    else 
        set_control->convertor_set = FALSE;

    //光电传感器识别到目标时， 传送带停止
    if (set_control->light_sensor == TRUE)
        set_control->convertor_set = FALSE;

}

/**
  * @brief           传送带任务输出控制值
  * @param[out]      interactive_data_display: 空
  * @retval         none
  */
static void conveyor_cmd_control(conveyor_control_t *cmd_control)
{
    HAL_GPIO_WritePin(switch_conveyor_GPIO_Port, switch_conveyor_Pin, cmd_control->convertor_set);
}