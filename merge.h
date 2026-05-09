#pragma once
/*
* 2014年上半年 软件设计师 下午试卷
试题四（共 15 分）
阅读下列说明和 C 代码，回答问题 1 至问题 3，将解答填入答题纸的对应栏内。
【说明】
采用归并排序对 n 个元素进行递增排序时，首先将 n 个元素的数组分成各含 n/2 个元
素的两个子数组，然后用归并排序对两个子数组进行递归排序，最后合并两个已经排好序的
子数组得到排序结果。
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 65536

void merge(int arr[], int p, int q, int r) {
	int* left, * right;
	int n1, n2, i, j, k;
	n1 = q - p + 1; // 左子数组长度
	n2 = r - q;     // 右子数组长度

	// 为左子数组分配内存（+1 用于存放哨兵值 MAX）
	if ((left = (int*)malloc((n1 + 1) * sizeof(int))) == NULL) {
		perror("malloc error");
		exit(1);
	}
	// 为右子数组分配内存（+1 用于存放哨兵值 MAX）
	if ((right = (int*)malloc((n2 + 1) * sizeof(int))) == NULL) {
		perror("malloc error");
		exit(1);
	}

	// 将原数组左半部分复制到 left
	for (i = 0; i < n1; i++) {
		left[i] = arr[p + i];
	}
	left[i] = MAX; // 在末尾设置哨兵值，避免越界比较

	// 将原数组右半部分复制到 right
	for (i = 0; i < n2; i++) {
		right[i] = arr[q + i + 1];
	}
	right[i] = MAX; // 在末尾设置哨兵值，避免越界比较

	i = 0; j = 0;
	// (1) 循环条件：k 从 p 遍历到 r，合并左右子数组
	for (k = p; (k <= r); k++) {
		if (left[i] > right[j]) {
			// (2) 右子数组当前元素更小，取 right[j] 写入 arr[k]
			arr[k] = right[j];
			j++;
		}
		else {
			arr[k] = left[i]; // 左子数组当前元素更小或相等，取 left[i] 写入 arr[k]
			i++;
		}
	}

	// 释放动态分配的内存
	free(left);
	free(right);
}

void mergeSort(int arr[], int begin, int end) {
	int mid;
	// (3) 递归条件：只有当子数组长度大于 1 时才继续分割
	if ((begin < end)) {
		mid = (begin + end) / 2;
		mergeSort(arr, begin, mid);         // 递归排序左半部分
		// (4) 递归排序右半部分
		mergeSort(arr, mid + 1, end);
		merge(arr, begin, mid, end);        // 合并左右两个有序子数组
	}
}

int bak15_main() {
	int arr[] = { 38, 27, 43, 3, 9, 82, 10 }; // 待排序数组
	int n = sizeof(arr) / sizeof(arr[0]);       // 计算数组长度

	printf("排序前: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	mergeSort(arr, 0, n - 1); // 调用归并排序

	printf("排序后: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}