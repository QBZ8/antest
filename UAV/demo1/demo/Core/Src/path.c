#include "path.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "tjc.h"
/* ================= 坐标映射表 ================= */
/* 7 行 9 列 */
typedef struct {
    int id;
    int x;
    int y;
} Point;

/* 静态表，直接初始化 */
static Point points[] = {
    {71,92,104}, {72,156,104}, {73,220,104}, {74,284,104}, {75,348,104}, {76,412,104}, {77,476,104}, {78,540,104}, {79,604,104},
    {61,92,168}, {62,156,168}, {63,220,168}, {64,284,168}, {65,348,168}, {66,412,168}, {67,476,168}, {68,540,168}, {69,604,168},
    {51,92,232}, {52,156,232}, {53,220,232}, {54,284,232}, {55,348,232}, {56,412,232}, {57,476,232}, {58,540,232}, {59,604,232},
    {41,92,296}, {42,156,296}, {43,220,296}, {44,284,296}, {45,348,296}, {46,412,296}, {47,476,296}, {48,540,296}, {49,604,296},
    {31,92,360}, {32,156,360}, {33,220,360}, {34,284,360}, {35,348,360}, {36,412,360}, {37,476,360}, {38,540,360}, {39,604,360},
    {21,92,424}, {22,156,424}, {23,220,424}, {24,284,424}, {25,348,424}, {26,412,424}, {27,476,424}, {28,540,424}, {29,604,424},
    {11,92,488}, {12,156,488}, {13,220,488}, {14,284,488}, {15,348,488}, {16,412,488}, {17,476,488}, {18,540,488}, {19,604,488}
};

#define POINT_COUNT (sizeof(points)/sizeof(points[0]))

/* ================= 接口函数实现 ================= */

void init_point_table(void)
{
    /* 静态表已经初始化，可留空或用于动态初始化 */
}

int get_point(int id, int *x, int *y)
{
    for (int i = 0; i < POINT_COUNT; i++) {
        if (points[i].id == id) {
            *x = points[i].x;
            *y = points[i].y;
            return 1;
        }
    }
    return 0;
}

void path_to_gui_lines(const int *path, int len)
{
    int x0, y0, x1, y1;
	char message[30];
	char msg[2]="OK";
	tjc_send_string(msg);
    for (int i = 0; i < len; i++) {
        if (!get_point(path[i], &x0, &y0) ||
            !get_point(path[i+1], &x1, &y1)) {
           // printf("// ERROR: invalid point %d or %d\n", path[i], path[i+1]);
            continue;
        }
		int n = snprintf(message, sizeof(message),
                         "line %d,%d,%d,%d,RED",
                         x0, y0, x1, y1);

        tjc_send_string(message);
        //printf("line %d,%d,%d,%d,RED;\n", x0, y0, x1, y1);
    }
}
