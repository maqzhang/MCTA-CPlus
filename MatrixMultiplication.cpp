#include "MatrixMultiplication.h"
//2022年上午题目
//矩阵链乘法问题：给定矩阵序列，找出最优的加括号方案，使得矩阵乘法次数最少
#define N 100
int cost[N][N];//cost[i][j] 表示计算矩阵 Ai..Aj 的最小乘法次数
int trace[N][N];//trace[i][j] 表示最优分割点，用于回溯构造最优解

/**
 * 矩阵链乘法动态规划求解函数
 * @param n: 矩阵个数
 * @param seq: 矩阵维数序列，长度为n+1
 *            seq[i] 为第i个矩阵的行数，seq[i+1] 为第i个矩阵的列数
 *            相邻两个矩阵的维数关系：矩阵i的列数 = 矩阵i+1的行数
 * @return: 计算所有矩阵乘积的最小乘法次数
 */
int cmm(int n, int seq[]) {
	int tempCost;    // 临时存储当前链的最小乘法次数
	int tempTrace;   // 临时存储最优分割点
	int i, j, k, p;  // 循环变量：i-起始位置，j-结束位置，k-分割点，p-链长
	int temp;        // 临时存储某个分割方案的乘法次数
	
	// 初始化：单个矩阵的乘法次数为0
	for (i = 0; i < n; i++) { cost[i][i] = 0; }
	
	// 动态规划主循环
	// p表示矩阵链的长度（包含矩阵个数-1）
	// p=1 表示相邻两个矩阵（Ai*Ai+1）
	// p=n-1 表示所有n个矩阵
	for (p = 1; p < n; p++) {
		// 遍历所有可能的链起始位置
		for (i = 0; i < n - p; i++) {
			//(1) 计算链的结束位置
			j = i + p;
			
			// 初始化该链的最小成本为-1（表示未初始化）
			tempCost = -1;
			
			//(2) 尝试所有可能的分割点 k
			// 分割点 k 表示在第k个和第k+1个矩阵之间分割
			// 即分割为 (Ai...Ak) * (Ak+1...Aj)
			//for (k = i; (2); k++) {
			for (k = i; k < j; k++) {
				//(3) 计算该分割方案的总乘法次数
				// = 左边链的乘法次数 + 右边链的乘法次数 + 最后两个结果矩阵相乘的次数
				// 左链：Ai...Ak，结果矩阵维数为 seq[i] × seq[k+1]
				// 右链：Ak+1...Aj，结果矩阵维数为 seq[k+1] × seq[j+1]
				// 两个结果矩阵相乘需要 seq[i] * seq[k+1] * seq[j+1] 次乘法
				//temp = (3);
				temp = cost[i][k] + cost[k + 1][j] + seq[i] * seq[k + 1] * seq[j + 1];
				
				// 更新最小成本和对应的分割点
				if (tempCost == -1 || tempCost > temp) {
					tempCost = temp;
					tempTrace = k;
				}
			}
			
			// 记录该链的最小乘法次数
			cost[i][j] = tempCost;
			//(4) 记录该链的最优分割点（用于后续构造最优解）
			trace[i][j] = tempTrace;
		}
	}
	
	// 返回计算所有n个矩阵乘积的最小乘法次数
	// cost[0][n-1] 表示从第0个矩阵到第n-1个矩阵的最小成本
	return cost[0][n - 1];
}
