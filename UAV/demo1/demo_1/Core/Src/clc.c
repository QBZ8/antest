#include "main.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "clc.h"


#define ROWS 7
#define COLS 9
#define MAXN 100

// 网格编号
static int grid[ROWS][COLS] = {
    {71,72,73,74,75,76,77,78,79},
    {61,62,63,64,65,66,67,68,69},
    {51,52,53,54,55,56,57,58,59},
    {41,42,43,44,45,46,47,48,49},
    {31,32,33,34,35,36,37,38,39},
    {21,22,23,24,25,26,27,28,29},
    {11,12,13,14,15,16,17,18,19}
};

static int visited[ROWS][COLS];
static int path_r[MAXN], path_c[MAXN];
static int path_len;
static int total_cells;
static const uint8_t *g_forbidden;
static int g_forbidden_num;

// 四方向
static int dr4[4] = {1,-1,0,0};
static int dc4[4] = {0,0,1,-1};

// 判断是否为禁入格
static int is_forbidden(int id) {
    for (int i=0;i<g_forbidden_num;i++)
        if (g_forbidden[i]==id)
            return 1;
    return 0;
}

// 根据编号找行列
static void find_pos(int id, int *r, int *c) {
    for (int i=0;i<ROWS;i++)
        for (int j=0;j<COLS;j++)
            if (grid[i][j]==id){
                *r=i; *c=j; return;
            }
}

// 判断当前位置能否直接回到起点（八方向）
static int can_return_to_start(int r,int c,int sr,int sc) {
    if (abs(r-sr)<=1 && abs(c-sc)<=1)
        return !is_forbidden(grid[sr][sc]);
    return 0;
}

// 核心函数：遍历所有格子并回到起点
int solve_path_return_start(int start_id,
                            const uint8_t *forbidden,
                            int forbid_num,
                            int *out_path,
                            int *out_len)
{
    g_forbidden = forbidden;
    g_forbidden_num = forbid_num;
    total_cells = ROWS*COLS - forbid_num;

    memset(visited,0,sizeof(visited));
    path_len = 0;

    int sr, sc;
    find_pos(start_id,&sr,&sc);

    // 非递归 DFS 栈
    typedef struct { int r,c,dir; } StackNode;
    StackNode stack[MAXN];
    stack[0] = (StackNode){sr,sc,0};
    visited[sr][sc] = 1;
    path_r[path_len] = sr; path_c[path_len] = sc; path_len++;

    int sp = 0;
    while (sp >= 0) {
        StackNode *cur = &stack[sp];

        // 判断是否完成 Hamiltonian 回路
        if (path_len == total_cells) {
            if (can_return_to_start(cur->r,cur->c,sr,sc)) {
                // 输出路径 + 回到起点
                int idx=0;
                for(int i=0;i<path_len;i++)
                    out_path[idx++] = grid[path_r[i]][path_c[i]];
                out_path[idx++] = start_id; // 回到起点
                *out_len = idx;
                return 1;
            } else {
                // 无法回到起点，回溯
                visited[cur->r][cur->c]=0;
                path_len--;
                sp--;
                if(sp>=0) stack[sp].dir++;
                continue;
            }
        }

        if (cur->dir >=4) {
            // 回退
            visited[cur->r][cur->c]=0;
            path_len--;
            sp--;
            if (sp>=0) stack[sp].dir++;
            continue;
        }

        int nr = cur->r + dr4[cur->dir];
        int nc = cur->c + dc4[cur->dir];
        cur->dir++;

        if (nr<0||nr>=ROWS||nc<0||nc>=COLS) continue;
        if (visited[nr][nc]) continue;
        if (is_forbidden(grid[nr][nc])) continue;

        sp++;
        stack[sp] = (StackNode){nr,nc,0};
        visited[nr][nc]=1;
        path_r[path_len] = nr;
        path_c[path_len] = nc;
        path_len++;
    }

    return 0; // 无解
}
