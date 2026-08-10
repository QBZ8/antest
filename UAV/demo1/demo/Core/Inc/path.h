#ifndef PATH_H
#define PATH_H
#include <stdio.h>
#include "main.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"

/* 初始化坐标表（可选，如果需要动态初始化，可扩展） */
void init_point_table(void);

/* 路径 → GUI line 输出 */
void path_to_gui_lines(const int *path, int len);

/* 根据点 ID 获取坐标，返回 1 成功，0 失败 */
int get_point(int id, int *x, int *y);
extern UART_HandleTypeDef huart3;


#endif /* PATH_GUI_H */
