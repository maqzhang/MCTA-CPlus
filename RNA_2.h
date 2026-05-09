#pragma once
/*
* 2018年下半年 软件设计师 下午试卷
试题四（共 15 分）
阅读下列说明和 C 代码，回答问题 1 至问题 3，将解答填入答题纸的对应栏内。
【说明】
给定一个字符序列 B = b1b2….bn，其中 bi∈{A, C, G, U}。B 上的二级结构是一
组字符对集合 S={(bi, bj)},其中 i, j∈{1, 2, …., n}，并满足以下四个条件：
（1）S 中的每对字符是(A, U), (U, A), (C, G)和(G, C)四种组合之一；
（2）S 中的每对字符之间至少有四个字符将其隔开，即 i < j – 4；
（3）S 中每一个字符（记为 bk）的配对存在两种情况：bk 不参与任何配对；bk 和字符
bt，其中 t < k – 4；
（4）（不交叉原则）若(bi, bj)和(bk, bt)是 S 中的两个字符对，且 i < k，则 i < k
< j < 1 不成立。
*/
#include <stdio.h>
#include <stdlib.h>
#define LEN 100
/* 判断两个字符是否配对 */
int isMatch(char a, char b) {
	if ((a == 'A' && b == 'U') || (a == 'U' && b == 'A'))
		return 1;
	if ((a == 'C' && b == 'G') || (a == 'G' && b == 'C'))
		return 1;
	return 0;
}
/* 求最大配对数 */
int RNA_2(char B[LEN], int n) {
	int i, j, k, t;
	int max;
	int C[LEN][LEN] = { 0 };
	for (k = 5; k <= n - 1; k++) {
		for (i = 1; i <= n - k; i++) {
			j = i + k;
			/* (1) 初始化 max 为 B[j] 不参与配对时的最大配对数，即子串 [i, j-1] 的最优解 */
			max = C[i][j - 1];
			for (/* (2) 枚举配对位置 t，从 i 开始逐个检查是否能与 B[j] 配对 */ t = i; t <= j - 4; t++) {
				if (/* (3) 判断 B[t] 与 B[j] 是否互补配对 */ isMatch(B[t], B[j]) && max < C[i][t - 1] + 1 + C[t + 1][j - 1])
					max = C[i][t - 1] + 1 + C[t + 1][j - 1];
			}
			C[i][j] = max;
			printf("c[%d][%d] = %d--", i, j, C[i][j]);
		}
	}
	/* (4) 返回整条链 B[1..n] 的最大碱基配对数 */
	return C[1][n];
}