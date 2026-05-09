#include "schedule.h"

#include <cstdio> // 包含标准输入输出函数，如 printf、scanf
#include <windows.h> // 添加此头文件

// 使用匿名命名空间，将全局变量限定在本文件内，避免与其他文件的同名变量产生链接冲突
namespace {
	const int MAXM = 10; // 最大机器数
	const int MAXN = 100; // 最大任务数

	int m;              // 机器数量
	int n;              // 任务数量
	int t[MAXN];        // 每个任务所需时间
	int d[MAXM];        // 每台机器当前累计完成时间
	int s[MAXM][MAXN];  // s[i][j]：第 i 台机器分配的第 j 个任务编号
	int count[MAXM];    // 每台机器已分配的任务数量
}

// 多机任务调度函数实现（贪心算法）
void schedule() {
	int i, j, k, max = 0;
	for (i = 0; i < m; i++) {
		d[i] = 0;
		for (j = 0; j < n; j++) {
			s[i][j] = 0;
		}
	}
	for (i = 0; i < m; i++) { // 分配前 m 个任务
		s[i][0] = i;
		d[i] = t[i]; // (1) 初始化机器 i 的完成时间为第 i 个任务的用时
		count[i] = 1;
	}
	for (i = m; i < n; i++) { // (2) 从第 m 个任务开始，分配后 n - m 个任务
		int min = d[0];
		k = 0;
		for (j = 1; j < m; j++) { // 确定空闲机器
			if (min > d[j]) {
				min = d[j];
				k = j; // 机器 k 空闲
			}
		}
		s[k][count[k]] = i; // (3) 将任务 i 分配给当前最空闲的机器 k
		count[k] = count[k] + 1;
		d[k] = d[k] + t[i];
	}
	for (i = 0; i < m; i++) { // 确定完成所有任务所需要的时间
		if (max < d[i]) { // (4) 找出所有机器中最大的完成时间
			max = d[i];
		}
	}

	// 输出调度结果
	printf("最优完成时间: %d\n", max);
	for (i = 0; i < m; i++) {
		printf("机器 %d（完成时间 %d）分配的任务: ", i, d[i]);
		for (j = 0; j < count[i]; j++) {
			printf("%d ", s[i][j]);
		}
		printf("\n");
	}
}
int main() {
	SetConsoleOutputCP(65001); // 将控制台输出编码设置为 UTF-8
	m = 3;                           // 机器数量
	n = 7;                           // 任务数量
	int taskTime[] = { 2, 14, 4, 16, 6, 5, 3 }; // 各任务所需时间
	for (int i = 0; i < n; i++) {
		t[i] = taskTime[i];          // 初始化任务时间数组
	}
	schedule(); // 执行调度算法
}