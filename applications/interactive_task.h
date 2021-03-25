#ifndef  INTERACTIVE_TASK_H
#define INTERACTIVE_TASK_H

#include "struct_typedef.h"
#include "arm_task.h"

//任务开始空闲一段时间
#define INTERACTIVE_TASK_INIT_TIME 350
//交互任务控制间隔 2ms
#define INTERACTIVE_CONTROL_TIME_MS 2







//LCD显示数据结构体：
typedef struct 
{
    bool_t light_sensor;          //光电传感器状态
    fp32 battery_vltage;           //电池电压
    arm_behaviour_e arm_behaviour; //机械臂行为机设置值
    

} lcd_display_t;

//交互数据结构体
typedef struct 
{
    bool_t  stop_switch; //急停开关标志位
    lcd_display_t oled_display;
} interactive_data_t;





/**
  * @brief          底盘任务，间隔 CHASSIS_CONTROL_TIME_MS 2ms
  * @param[in]      pvParameters: 空
  * @retval         none
  */
extern void interactive_task(); 





#endif

