#pragma once
#include <stdio.h>
#include <iostream>
/*
* 2013年下半年 软件设计师 下午试卷
试题四（共 15 分）
阅读下列说明和 C 代码，回答问题 1 至问题 3，将解答填入答题纸的对应栏内。
【说明】
某工程计算中要完成多个矩阵相乘（链乘）的计算任务。
两个矩阵相乘要求第一个矩阵的列数等于第二个矩阵的行数，计算量主要由进行乘法运
算的次数决定。采用标准的矩阵相乘算法，计算 Am×n*Bn×p，需要 m*n*p 次乘法运算
*/
#define N 100
// static 限制变量仅在当前编译单元可见，避免与其他文件中同名全局变量产生链接冲突
static int cost[N][N];
static int trace[N][N];

// 矩阵链乘法动态规划函数
// n: 矩阵数量, seq: 维度序列（长度为n+1）
// 返回最优乘法代价
int cmm2(int n, int seq[]) {
	int tempCost;
	int tempTrace;
	int i, j, k, p;
	int temp;
	for (i = 0; i < n; i++) { cost[i][i] = 0; }
	for (p = 1; p < n; p++) {
		// (1) 链长为p时，起始下标i的范围为 [0, n-p)
		for (i = 0; i < n - p; i++) {
			// (2) 根据链长p和起始下标i计算终止下标j
			j = i + p;
			tempCost = -1;
			for (k = i; k < j; k++) {
				// (3) 计算在k处分割时的总代价：左段代价 + 右段代价 + 当前合并代价
				temp = cost[i][k] + cost[k + 1][j] + seq[i] * seq[k + 1] * seq[j + 1];
				if (tempCost == -1 || tempCost > temp) {
					tempCost = temp;
					// (4) 记录当前最优分割点k到追踪数组
					tempTrace = k;
				}
			}
			cost[i][j] = tempCost;
			trace[i][j] = tempTrace;
		}
	}
	return cost[0][n - 1];
}

// 打印最优加括号方案（递归）
void printOptimal(int i, int j) {
	if (i == j) {
		printf("A%d", i + 1);
		return;
	}
	printf("(");
	printOptimal(i, trace[i][j]);
	printOptimal(trace[i][j] + 1, j);
	printf(")");
}

int bak17_main() {
	// 设置运行时 locale 为中文，解决 UTF-8 源文件在 Windows 控制台的乱码问题
	setlocale(LC_ALL, ".UTF-8");
	// 矩阵数量
	int n = 4;
	// 维度序列：矩阵i的维度为seq[i] x seq[i+1]
	// 例：A1(30x35), A2(35x15), A3(15x5), A4(5x10)
	int seq[] = { 30, 35, 15, 5, 10 };

	// 调用矩阵链乘法动态规划函数，获取最优代价
	int minCost = cmm2(n, seq);

	// 输出最优乘法代价
	std::cout << "最优乘法代价: " << minCost << std::endl;

	// 输出最优加括号方案
	std::cout << "最优加括号方案: ";
	printOptimal(0, n - 1);
	std::cout << std::endl;

	return 0;
}