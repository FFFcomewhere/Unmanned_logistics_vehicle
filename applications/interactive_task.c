#include "interactive_task.h"

#include "main.h"



#include "detect_task.h"
#include "arm_task.h"
#include "conveyor_task.h"



#include "remote_control.h"
#include "struct_typedef.h"
#include "gpio.h"
#include "OLED.h"






/**
  * @brief          交互任务初始化
  * @param[out]      interactive_data_init: 空
  * @retval         none
  */
static void interactive_init(interactive_data_t *interactive_data_init);




/**
  * @brief          交互任务数据更新
  * @param[out]      interactive_data_updata: 空
  * @retval         none
  */
static void interactive_feedback_update(interactive_data_t *interactive_data_updata);



/**
  * @brief          在OLED屏上显示信息
  * @param[out]      interactive_data_updata: 空
  * @retval         none
  */
static void interactive_display(interactive_data_t *interactive_data_display);




//交互任务数据
interactive_data_t interactive_data;




void interactive_task()
{
    //空闲一段时间
    vTaskDelay(INTERACTIVE_TASK_INIT_TIME);
    //交互任务初始化
    interactive_init(&interactive_data);
    
    while (1)
    {
        //更新数据
        interactive_feedback_update(&interactive_data);
        //在OLED屏上显示信息
        interactive_display(&interactive_data);
        //系统延时
        vTaskDelay(INTERACTIVE_CONTROL_TIME_MS);
    }
    
}

/**
  * @brief          交互任务初始化
  * @param[out]      interactive_data_init: 空
  * @retval         none
  */
static void interactive_init(interactive_data_t *interactive_data_init)
{
    OLED_init();     

    interactive_feedback_update(interactive_data_init);
}



/**
  * @brief          交互任务数据更新
  * @param[out]      interactive_data_updata: 空
  * @retval         none
  */
static void interactive_feedback_update(interactive_data_t *interactive_data_updata)
{
    interactive_data_updata->stop_switch = HAL_GPIO_ReadPin(switch_stop_GPIO_Port, switch_stop_Pin);

    interactive_data_updata->oled_display.light_sensor = !HAL_GPIO_ReadPin(light_sensor_GPIO_Port, light_sensor_Pin);
    //电池电压还没测,模式没写，暂时写死
    interactive_data_updata->oled_display.battery_vltage = 24.0f;
    interactive_data_updata->oled_display.arm_behaviour = 1;

}



/**
  * @brief          在OLED屏上显示信息
  * @param[out]      interactive_data_updata: 空
  * @retval         none
  */
static void interactive_display(interactive_data_t *interactive_data_display)
{
    // OLED_show_string(1, 1, "stop_switch");
    // OLED_printf(2, 1, "%d", interactive_data_display->stop_switch);

    // OLED_show_string(3, 1, "light_sensor");
    // OLED_printf(4, 1, "%d", interactive_data_display->oled_display.light_sensor);

    //OLED_LOGO();
    OLED_draw_line(1, 1, 10, 10, PEN_WRITE);
}