#ifndef GET_TRIANGLE_WEIGHT_H
#define GET_TRIANGLE_WEIGHT_H
/*
* 2021年上半年 软件设计师 下午试卷
* 试题四（共 15 分）
阅读下列说明和 C 代码，回答问题 1 至问题 2，将解答填入答题纸的对应栏内。
【说明】
凸多边形是指多边形的任意两点的连线均落在多边形的边界或内部。相邻的点连线落在
多边形边界上，称为边；不相邻的点连线落在多边形内部，称为弦。假设任意两点连线上均
有权重，凸多边形最优三角剖分问题定义为：求将凸多边形划分为不相交的三角形集合，且
各三角形权重之和最小的剖分方案。每个三角形的权重为三条边权重之和。
假设 N 个点的凸多边形点编号为 V1, V2, ......-, VN,若在 Vk 处将原凸多边形划分为一
个三角形 V1VkVN，两个子多边形 V1, V2, ...-, Vk 和 Vk, Vk+1, ...-, VN 得到一个最优的
剖分方案，则该最优剖分方案应该包含这两个子凸边形的最优剖分方案。用 m[i][j]表示 Vi-1,
Vi, ...-,Vj 构成的凸多边形的最优剖分方案的权重，S[i][j]记录剖分该凸多边形的 k 值。
* */
#include<stdio.h>
// 凸多边形规模
#define N 6

// m[i][j]表示多边形 Vi-1 到 Vj 最优三角剖分的权值
extern int m[N + 1][N + 1];

// S[i][j]记录多边形 Vi-1 到 Vj 最优三角剖分的 k 值
extern int S[N + 1][N + 1];

// 凸多边形的权重矩阵，在 main 函数中输入
extern int W[N + 1][N + 1];

/**
 * 计算三角形的权重
 * @param a 三角形顶点下标 a
 * @param b 三角形顶点下标 b
 * @param c 三角形顶点下标 c
 * @return 三角形 a-b-c 的权重和
 */
int get_triangle_weight(int a, int b, int c);

/**
 * 求解凸多边形的最优三角剖分
 * 使用动态规划算法自底向上计算最优值
 * 时间复杂度：O(n^3)
 */
void triangle_partition();

/**
 * 递归输出最优三角剖分的所有三角形
 * @param i 凸多边形的起始顶点下标
 * @param j 凸多边形的终止顶点下标
 */
void print_triangle(int i, int j);

#endif // GET_TRIANGLE_WEIGHT_H
