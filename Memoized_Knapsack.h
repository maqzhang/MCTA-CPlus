#pragma once
/*
* 2019年下半年 软件设计师 下午试卷
试题四（共 15 分）
阅读下列说明和 C 代码，回答问题 1 至问题 3，将解答填入答题纸的对应栏内。
【说明】
0-1 背包问题定义为：给定 i 个物品的价值 v[1…i]、小重量 w[1…i]和背包容量 T，每
个物品装到背包里或者不装到背包里。求最优的装包方案，使得所得到的价值最大。
0-1 背包问题具有最优子结构性质。定义 c[i][T]为最优装包方案所获得的最大价值，则
可得到如下所示的递归式。
*/
#include <stdio.h>
#include <math.h>

#define N 6       // 物品数量（含索引0占位）
#define maxT 1000 // 背包最大容量上限

// 记忆化表：c[i][j] 表示前i件物品、容量为j时的最大价值；-1表示未计算
int c[N][maxT] = { 0 };

// 前向声明
int Calculate_Max_Value(int v[N], int w[N], int i, int j);

/**
 * @brief 记忆化搜索入口函数，初始化缓存表后启动递归求解
 * @param v 物品价值数组
 * @param w 物品重量数组
 * @param T 背包总容量
 * @return 最优装包方案的最大价值
 */
int Memoized_Knapsack(int v[N], int w[N], int T) {
    int i;
    int j;
    // 将记忆化表全部初始化为-1，表示所有子问题尚未求解
    for (i = 0; i < N; i++) {
        for (j = 0; j <= T; j++) {
            c[i][j] = -1;
        }
    }
    // 从第N-1件物品、容量T开始递归求解
    return Calculate_Max_Value(v, w, N - 1, T);
}

/**
 * @brief 递归计算前i件物品在容量j下的最大价值（记忆化搜索）
 * @param v 物品价值数组
 * @param w 物品重量数组
 * @param i 当前考虑的物品索引
 * @param j 当前背包剩余容量
 * @return c[i][j] 前i件物品容量j下的最大价值
 */
int Calculate_Max_Value(int v[N], int w[N], int i, int j) {
    int temp = 0;
    if (c[i][j] != -1) {
        return c[i][j]; // (1) 缓存命中，直接返回已记录的最优值，避免重复计算
    }
    if (i == 0 || j == 0) {
        c[i][j] = 0; // 边界条件：无物品或背包容量为0时，价值为0
    }
    else {
        // 不放入第i件物品时的最优价值
        c[i][j] = Calculate_Max_Value(v, w, i - 1, j);
        if (w[i] <= j) { // (2) 判断第i件物品的重量是否不超过当前背包剩余容量j
            temp = v[i] + Calculate_Max_Value(v, w, i - 1, j - w[i]); // (3) 计算选入第i件物品后的总价值（当前物品价值 + 剩余容量的最优子结构值）
            if (c[i][j] < temp) {
                c[i][j] = temp; // (4) 若放入第i件物品的价值更大，则更新当前状态的最优值
            }
        }
    }
    return c[i][j];
}