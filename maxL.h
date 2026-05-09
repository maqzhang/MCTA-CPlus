#pragma once
#define _CRT_SECURE_NO_WARNINGS  // 禁用 scanf 等函数的安全弃用警告
/*
2014年下半年 软件设计师 下午试卷
试题四（共 15 分）
阅读下列说明和 C 代码，回答问题 1 至问题 3，将解答填入答题纸的对应栏内。
【说明】
计算一个整数数组 a 的最长递增子序列长度的方法描述如下：
假设数组 a 的长度为 n，用数组 b 的元素 b[i]记录以 a[i](0≤i<n)为结尾元素的最长递
增子序列的长度，则数组 a 的最长递增子序列的长度为
0≤i<n
max{𝑏[𝑖]}；其中 b[i]满足最优子结
构，可递归定义为：
*/

#include <stdio.h>

// 找出数组b中前n个元素的最大值（即最长递增子序列长度）
int maxL(int* b, int n) {
	int i, temp = 0;
	for (i = 0; i < n; i++) {
		if (b[i] > temp)
			temp = b[i];
	}
	return temp;
}

int bak13_main() {
	int n, a[100], b[100], i, j, len;

	// 读取序列长度
	scanf("%d", &n);

	// 读取序列元素
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	// (1) 初始化：以第一个元素结尾的最长递增子序列长度为1
	b[0] = 1;

	// 动态规划：依次计算以a[i]结尾的最长递增子序列长度
	for (i = 1; i < n; i++) {
		// (2) 遍历i之前的所有元素，寻找可以接在a[i]前面的最长子序列
		for (j = 0, len = 0; j < i; j++) {
			// (3) 若a[j]<a[i]，则a[i]可以接在a[j]后面构成递增序列，更新当前最大长度
			if (a[j] < a[i] && len < b[j])
				len = b[j];
		}
		// (4) 以a[i]结尾的最长递增子序列长度 = 前面最长可接子序列长度 + 1
		b[i] = len + 1;
	}

	// 输出最长递增子序列的长度
	printf("len:%d\n", maxL(b, n));
	printf("\n");
	return 0;
}

