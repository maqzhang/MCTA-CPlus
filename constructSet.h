#pragma once
/*
* 2016年上半年 软件设计师 下午试卷
试题四（共 15 分）
阅读下列说明和 C 代码，回答问题 1 至问题 3，将解答填入答题纸的对应栏内。
【说明】
在一块电路板的上下两端分别有𝑛个接线柱。根据电路设计，用(i,π(i))表示将上端接
线柱 i 与下端接线柱π(i)相连，称其为该电路板上的第 i 条连线。如图 4-1 所示的π(i)排列为
{8, 7, 4, 2, 5, 1, 9, 3, 10, 6}。对于任何 1≤i<j≤𝑛，第 i 条连线和第 j 条连线相
交的充要条件是π(i)>π(j)
*/
#include <stdlib.h>
#include <stdio.h>
#define N 10 /* 问题规模 */

extern int m; /* 记录最大连接集合中的接线柱（定义在 constructSet.cpp） */

/* 求最大不相交连接数 */
/* pi[]    : 连线映射数组，pi[i] 表示第 i 条连线下端接线柱编号 */
/* size[][] : 动态规划表，size[i][j] 表示前 i 条连线中，下端编号 <= j 时的最大不相交连接数 */
/* n       : 接线柱数量 */
void maxNum(int pi[], int size[N + 1][N + 1], int n);

/* 构造最大不相交连接集合，net[i]表示最大不相交子集中第 i 条连线的上端接线柱的序号 */
void constructSet(int pi[], int size[N + 1][N + 1], int n, int net[]);

/* 演示入口，供 main 调用 */
int constructSetMain();

