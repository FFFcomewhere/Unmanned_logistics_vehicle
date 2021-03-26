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
  * @brief          交互任务，间隔 INTERACTIVE_CONTROL_TIME_MS 2ms
  * @param[in]      pvParameters: 空
  * @retval         none
  */
void interactive_task(); 


/**
  * @brief          交互任务初始化
  * @param[out]      interactive_data_init: 空
  * @retval         none
  */
static void interactive_init(interactive_data_t *init);




/**
  * @brief          交互任务数据更新
  * @param[out]      interactive_data_updata: 空
  * @retval         none
  */
static void interactive_feedback_update(interactive_data_t *feedback_update);



/**
  * @brief          在OLED屏上显示信息
  * @param[out]      interactive_data_updata: 空
  * @retval         none
  */
static void interactive_display(interactive_data_t *display);






#endif

