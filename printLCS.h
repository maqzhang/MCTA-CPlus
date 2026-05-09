#pragma once
/*
* 2015年下半年 软件设计师 下午试卷
试题四（共 15 分）
阅读下列说明和 C 代码，回答问题 1 至问题 3，将解答填入答题纸的对应栏内。
【说明】
计算两个字符串𝑥和𝑦的最长公共子串（Longest-Common-Substring）。
假设字符串𝑥和字符串𝑦的长度分别为𝑚和𝑛，用数组𝑐的元素𝑐[𝑖][𝑗]记录𝑥中前𝑖个字符
和𝑦中前𝑗个字符的最长公共子串的长度。
 * 最长公共子串（Longest Common Substring）算法
 * 使用动态规划求解两个字符串的最长公共连续子串
 */
#include <stdio.h>
#include <string.h>

// 动态规划表，c[i][j] 表示以 x[i-1] 和 y[j-1] 结尾的公共子串长度
int c[50][50];
// 最长公共子串结束位置在 x 中的行列下标
int maxi;
int maxj;

/*
 * lcs: 求字符串 x（长度 m）与 y（长度 n）的最长公共子串长度
 * 同时记录最长子串在 x 中的结束下标 maxi
 */
int lcs(const char* x, int m, const char* y, int n) {
	int i, j;
	int max = 0; // 当前找到的最大公共子串长度
	maxi = 0;
	maxj = 0;

	// 初始化边界：第 0 行和第 0 列均为 0
	for (i = 0; i <= m; i++) c[i][0] = 0;
	for (i = 1; i <= n; i++) c[0][i] = 0;

	// 逐字符填充动态规划表
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			// (1) 判断 x 和 y 当前字符是否相等
			if (x[i - 1] == y[j - 1]) {
				// 字符匹配，公共子串长度在左上角基础上加 1
				c[i][j] = c[i - 1][j - 1] + 1;
				if (max < c[i][j]) {
					// (2) 更新最大公共子串长度及其结束位置
					max = c[i][j];
					maxi = i;
					maxj = j;
				}
			}
			else
				// (3) 字符不匹配，公共子串长度归零
				c[i][j] = 0;
		}
	}
	return max;
}

/*
 * printLCS: 根据最长公共子串长度 max 及字符串 x，打印最长公共子串
 */
void printLCS(int max, const char* x) {
	int i = 0;
	if (max == 0) return; // 无公共子串则直接返回

	// (4) 从最长公共子串的起始位置开始遍历，起始下标 = maxi - max
	for (i = maxi - max; i < maxi; i++)
		printf("%c", x[i]);
}

/*
 * main: 程序入口，定义测试字符串并调用 lcs 与 printLCS 输出结果
 */
void bak11_main() {
	const char* x = "ABCADAB"; // 第一个字符串
	const char* y = "BDCABA";  // 第二个字符串
	int max = 0;
	int m = strlen(x); // x 的长度
	int n = strlen(y); // y 的长度

	// 计算最长公共子串的长度
	max = lcs(x, m, y, n);

	// 打印最长公共子串
	printLCS(max, x);
}