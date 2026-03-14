// CPlusCourse.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "HeapSort.h"
int main()
{
	// 注意：数组按 1..n 使用，R[0] 用作暂存
	int R[MAXITEM] = { 0, 20, 5, 16, 8, 14, 2, 10 }; // R[0]=0 占位，n=7
	int n = 7;

	printf("排序前: ");
	for (int i = 1; i <= n; i++) printf("%d ", R[i]);
	printf("\n");

	HeapSort(R, n);

	printf("排序后: ");
	for (int i = 1; i <= n; i++) printf("%d ", R[i]);
	printf("\n");

	return 0;
}
