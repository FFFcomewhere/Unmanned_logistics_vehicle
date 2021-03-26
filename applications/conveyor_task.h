#ifndef  CONVEYOR_TASK_H
#define CONVEYOR_TASK_H

#include "struct_typedef.h"
#include "arm_task.h"

//任务开始空闲一段时间
#define CONVEYOR_TASK_INIT_TIME 350
//交互任务控制间隔 2ms
#define CONVEYOR_CONTROL_TIME_MS 2

//传送带电磁阀 遥控器控制按键通道
#define CONVEYOR_CHANNEL 0



typedef struct 
{
    bool_t convetor_status; //传送带运动状态，是否开启
    bool_t convertor_set;   //控制传送带上的电磁阀 
    bool_t light_sensor; //光电传感器状态

}conveyor_control_t;



/**
  * @brief          传送带任务，间隔 CONVEYOR_CONTROL_TIME_MS 2ms
  * @param[in]      pvParameters: 空
  * @retval         none
  */
void conveyor_task(); 


/**
  * @brief          传送带任务初始化
  * @param[out]      conveyor_init: 空
  * @retval         none
  */
static void conveyor_init(conveyor_control_t *init);




/**
  * @brief          传送带任务数据更新
  * @param[out]      conveyor_data_updata: 空
  * @retval         none
  */
static void conveyor_feedback_update(conveyor_control_t *feedback_update);


/**
  * @brief           传送带任务设置控制值
  * @param[out]      converyor_set: 空
  * @retval         none
  */
static void conveyor_set_control(conveyor_control_t *set_control);





/**
  * @brief           传送带任务输出控制值
  * @param[out]      interactive_data_display: 空
  * @retval         none
  */
static void conveyor_cmd_control(conveyor_control_t *cmd_control);






#endif
