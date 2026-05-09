#include "ShellSort.h"
#include <stdio.h>

/**
 * 主函数：测试希尔排序
 */
int bak2_main() {
	// 测试数组，包含无序整数
	int data[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	int n = sizeof(data) / sizeof(data[0]); // 计算数组长度

	// 输出排序前的数组
	printf("排序前: ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n");

	// 调用希尔排序
	ShellSort(data, n);

	// 输出排序后的数组
	printf("排序后: ");
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n");

	// 期望输出: 13 27 38 49 49 65 76 97
	return 0;
}
