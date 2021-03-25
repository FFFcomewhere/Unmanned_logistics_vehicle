#ifndef  ARM_TASK_H
#define ARM_TASK_H


//机械臂行为机    conveyor 传送带 paw 爪子 ground 地面
typedef enum
{
    converyor_to_paw_mode = 0,   //爪子从传送带取
    paw_to_convertor_mode,       //爪子放至传送带
    paw_to_ground_mode,          //爪子从地面取
    ground_to_paw_mode           //爪子放至地面

} arm_behaviour_e;










extern void arm_task();

#endif
