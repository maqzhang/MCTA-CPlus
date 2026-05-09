#pragma once
/*2020年下半年 软件设计师 下午试卷
试题四（共 15 分）
阅读下列说明和 C 代码，回答问题 1 至问题 3，将解答填入答题纸的对应栏内。
【说明】
希尔排序算法又称最小增量排序算法，其基本思想是：
步骤 1：构造一个步长序列 delta1, delta2, ...., deltak, 其中 delta1 = n / 2，
后面的每个 delta 是前一个的 1 / 2，deltak = 1；
步骤 2：根据步长序列进行 k 趟排序；
步骤 3：对第 i 趟排序，根据对应的步长 delta，将等步长位置元素分，对同一组内元素
在原位置上进行直接插入排序
*/ 
#include <stdlib.h>
void ShellSort(int data[], int n) {
	int* delta, k, i, t, dk, j;
	k = n;
	delta = (int*)malloc(sizeof(int) * (n / 2));
	i = 0;
	do {
		k = k / 2;            // (1) 步长每次折半
		delta[i++] = k;       // 将步长存入delta数组
	} while (k > 0);          // (2) 直到k=0为止，0作为终止哨兵

	i = 0;
	while ((dk = delta[i]) > 0) {  // (3) 取出步长dk，步长为0时终止
		for (k = delta[i]; k < n; ++k)
			if (data[k] < data[k - dk]) {
				t = data[k];
				for (j = k - dk; j >= 0 && t < data[j]; j -= dk)
					data[j + dk] = data[j];
				data[j + dk] = t;  // (4) 将暂存值t插入到正确位置
			}
		++i;
	}
}