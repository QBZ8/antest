#ifndef __CLC_H__
#define __CLC_H__

#include "main.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"
#include <stdio.h>
#include <stdint.h>
/* ================= 参数说明 ================= */
/*
 * 网格规模说明：
 * 当前实现为 7 × 9 网格，共 63 个格子
 * 禁区数量可变
 *
 * 输出路径长度最大：
 *   63（遍历） + 若干回程节点
 * 建议 out_path 至少分配 100 个 int
 */

/**
 * 计算覆盖全图并最终回到起点的路径
 *
 * 说明：
 *  - 从 start_id 出发
 *  - 遍历所有非禁区格子（4 邻接）
 *  - 最终通过 8 邻接回到起点
 *  - 输出路径最后一个元素一定是 start_id
 *
 * @param start_id    起点格子编号（如 19）
 * @param forbidden   禁区格子编号数组
 * @param forbid_num  禁区数量
 * @param out_path    输出路径数组（格子编号序列）
 * @param out_len     输出路径长度
 *
 * @return
 *   1  成功，out_path / out_len 有效
 *   0  失败（不存在可行路径）
 */
int solve_path_return_start(
    int start_id,
    const uint8_t *forbidden,
    int forbid_num,
    int *out_path,
    int *out_len
);


#endif
