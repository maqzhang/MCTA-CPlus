/*
* 2021年下半年 软件设计师 下午试卷
* 试题四（共 15 分）
阅读下列说明和 C 代码，回答问题 1 至问题 2，将解答填入答题纸的对应栏内。
【说明】
生物学上通常采用编辑距离来定义两个物种 DNA 序列的相似性，从而刻画物种之间的
进化关系。具体来说，编辑距离是指将一个字符串变换为另一个字符所需要的最小操作次数。
操作有三种，分别为：插入一个字符、删除一个字符以及将一个字符修改为另一个字符。用
字符数组 str1 和 str2 分别表示长度为 len1 和 len2 的字符串，定义二维数组 d 记录求解编
辑距离的子问题最优解，则该二维数组可以递归定义为：
*/
#include <stdio.h>
#define N 100
char A[N] = "CTGA";
char B[N] = "ACGCTA";
int d[N][N];

// 返回两个整数中的较小值
int min(int a, int b) {
	return a < b ? a : b;
}

// 编辑距离算法（动态规划）
// 计算将 str1 转换为 str2 所需的最少操作次数
// 允许的操作：插入、删除、替换
int editdistance(char* str1, int len1, char* str2, int len2) {
	int i, j;
	int diff;
	int temp;
	
	// 初始化第一列：从空字符串插入 str1 的前 i 个字符需要 i 次操作
	for (i = 0; i <= len1; i++) {
		d[i][0] = i;
	}
	
	// 初始化第一行：从空字符串插入 str2 的前 j 个字符需要 j 次操作
	for (j = 0; j <= len2; j++) {
		d[0][j] = j;//(1)
	}
	
	// 动态规划填充 DP 表
	for (i = 1; i <= len1; i++) {
		for (j = 1; j <= len2; j++) {
			// 当前字符相等，不需要操作，取对角线值
			if (str1[i - 1] == str2[j - 1]) {//(2)
				d[i][j] = d[i - 1][j - 1];
			}
			else {
				// 当前字符不相等，选择三种操作中成本最小的
				// d[i-1][j] + 1：删除 str1 的第 i 个字符
				// d[i][j-1] + 1：在 str1 中插入 str2 的第 j 个字符
				temp = min(d[i - 1][j] + 1, d[i][j - 1] + 1);
				// d[i-1][j-1] + 1：替换 str1 的第 i 个字符为 str2 的第 j 个字符
				d[i][j] = min(temp, d[i - 1][j - 1] + 1); //(3)
			}
		}
	}
	
	// 返回右下角的值，即两个完整字符串的编辑距离
	return d[len1][len2];//(4)
}

int _main() {
	int len1 = 4;
	int len2 = 6;
	
	// 计算字符串 A 和 B 的编辑距离
	int result = editdistance(A, len1, B, len2);
	
	// 输出结果
	printf("字符串A: %s\n", A);
	printf("字符串B: %s\n", B);
	printf("编辑距离: %d\n", result);
	
	return 0;
}