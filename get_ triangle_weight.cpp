#include "get_ triangle_weight.h"

// 全局变量定义
int m[N + 1][N + 1]; // m[i][j]表示多边形 Vi-1 到 Vj 最优三角剖分的权值
int S[N + 1][N + 1]; // S[i][j]记录多边形 Vi-1 到 Vj 最优三角剖分的 k 值
int W[N + 1][N + 1]; // 凸多边形的权重矩阵，在 main 函数中输入

/**
 * 计算三角形的权重
 * @param a 三角形顶点下标 a
 * @param b 三角形顶点下标 b
 * @param c 三角形顶点下标 c
 * @return 三角形 a-b-c 的权重和
 */
int get_triangle_weight(int a, int b, int c) {
	return W[a][b] + W[b][c] + W[c][a];
}

/**
 * 求解凸多边形的最优三角剖分
 * 使用动态规划算法自底向上计算最优值
 * 时间复杂度：O(n^3)
 */
void triangle_partition() {
	int i, r, k, j;
	int temp;

	/* 初始化单个顶点的权值为0 */
	for (i = 1; i <= N; i++) {
		m[i][i] = 0;
	}

	/* 自底向上计算 m, S */
	// r 为子问题规模，从2到N-1
	for (r = 2; r <= N - 1; r++) {
		// 遍历所有起始位置 i
		for (i = 1; i <= N - r + 1; i++) {
			// 根据起始位置和链长度计算终止位置
			j = i + r - 1;

			// 初始化 m[i][j]，假设分割点 k = i
			m[i][j] = m[i][i] + m[i + 1][j] +
				get_triangle_weight(i - 1, i, j);
			S[i][j] = i;

			// 遍历所有可能的分割点 k，计算 m[i][j] 的最小代价
			for (k = i + 1; k < j; k++) {
				// 计算当前分割点下的代价
				temp = m[i][k] + m[k + 1][j] +
					get_triangle_weight(i - 1, k, j);

				// 判断是否为最小值，若是则更新
				if (temp < m[i][j]) {
					m[i][j] = temp;
					S[i][j] = k;
				}
			}
		}
	}
}

/**
 * 递归输出最优三角剖分的所有三角形
 * @param i 凸多边形的起始顶点下标
 * @param j 凸多边形的终止顶点下标
 */
void print_triangle(int i, int j) {
	// 递归终止条件：只有一条边时无法形成三角形
	if (i == j) return;

	// 递归处理左侧子问题 (i 到 S[i][j])
	print_triangle(i, S[i][j]);

	// 递归处理右侧子问题 (S[i][j]+1 到 j)
	print_triangle(S[i][j] + 1, j);

	// 输出当前三角形：以 S[i][j] 为分割点
	printf("V%d--V%d--V%d\n", i - 1, S[i][j], j);
}

/**
 * 主函数：初始化权重矩阵并求解最优三角剖分
 */
int bak_main() {
	int i, j;

	// 初始化权重矩阵 W
	// W[i][j] 表示从顶点 Vi 到顶点 Vj 的边的权重
	printf("初始化凸多边形的权重矩阵...\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (i != j) {
				W[i][j] = 1;  // 设置每条边的权重为1
			}
			else {
				W[i][j] = 0;  // 对角线上的权重为0
			}
		}
	}

	printf("凸多边形规模：%d 个顶点\n", N);
	printf("\n开始计算最优三角剖分...\n");

	// 调用动态规划函数计算最优三角剖分
	triangle_partition();

	// 输出最优三角剖分的结果
	printf("\n最优三角剖分结果：\n");
	printf("最小权值：%d\n\n", m[1][N]);

	printf("三角形列表：\n");
	// 递归输出所有三角形
	print_triangle(1, N);

	printf("\n计算完成！\n");
	return 0;
}