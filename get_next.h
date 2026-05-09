#pragma once
/*
* 2016年下半年 软件设计师 下午试卷
试题四（共 15 分）
阅读下列说明和 C 代码，回答问题 1 至问题 3，将解答填入答题纸的对应栏内。
【说明】
模式匹配是指给定主串 t 和子串 s，在主串 t 中寻找子串 s 的过程，其中 s 称为模式。
如果匹配成功，返回 s 在 t 中的位置，否则返回-1。
KMP 算法用 next 数组对匹配过程进行了优化。KMP 算法的伪代码描述如下：
1．在串 t 和串 s 中，分别设比较的起始下标 i=j=0。
2．如果串 t 和串 s 都还有字符，则循环执行下列操作：
（1）如果 j=-1 或者 t[i]=s[j]，则将 i 和 j 分别加 1，继续比较 t 和 s 的下一个字符；
（2）否则，将 j 向右滑动到 next[j]的位置，即 j=next[j]。
3．如果 s 中所有字符均已比较完毕，则返回匹配的起始位置（从 1 开始）；否则返回
-1。其中，next 数组根据子串 s 求解。求解 next 数组的代码已由 get_next 函数给出。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 求 next[]的值 */
void get_next(int* next, char* s, int ls) {
	int i = 0, j = -1;
	next[0] = -1; /* 初始化 next[0] */
	while (i < ls) { /* 还有字符 */
		if (j == -1 || s[i] == s[j]) { /* 匹配 */
			j++;
			i++;
			if (s[i] == s[j])
				next[i] = next[j];
			else
				next[i] = j;
		}
		else
			j = next[j];
	}
}

/* KMP 字符串匹配算法
   t: 主串, s: 模式串, lt: 主串长度, ls: 模式串长度
   返回模式串在主串中第一次出现的起始位置，未找到返回 -1 */
int kmp(int* next, char* t, char* s, int lt, int ls) {
	int i = 0, j = 0;
	while (i < lt && (j < ls) /* (1) j 未超出模式串长度，继续匹配 */) {
		if (j == -1 || (t[i] == s[j]) /* (2) 主串与模式串当前字符匹配 */) {
			i++; /* 主串指针后移 */
			j++; /* 模式串指针后移 */
		}
		else
			(j = next[j]); /* (3) 匹配失败，模式串指针回退到 next[j] */
	}
	if (j >= ls)
		return (i - ls); /* (4) 返回模式串在主串中的起始位置 */
	else
		return -1; /* 未找到，返回 -1 */
}

/* 主函数：测试 get_next 和 kmp */
int bak6_main() {
	char t[] = "ababcabcacbab"; /* 主串 */
	char s[] = "abcac";         /* 模式串 */
	int lt = (int)strlen(t);    /* 主串长度 */
	int ls = (int)strlen(s);    /* 模式串长度 */

	/* 分配 next 数组空间 */
	int* next = (int*)malloc((ls + 1) * sizeof(int));

	/* 计算模式串的 next 数组 */
	get_next(next, s, ls);

	/* 打印 next 数组 */
	printf("next 数组: ");
	for (int i = 0; i <= ls; i++) {
		printf("%d ", next[i]);
	}
	printf("\n");

	/* 执行 KMP 匹配 */
	int pos = kmp(next, t, s, lt, ls);

	/* 输出匹配结果 */
	if (pos != -1)
		printf("模式串在主串中的起始位置（从0开始）: %d\n", pos);
	else
		printf("模式串在主串中未找到\n");

	/* 释放 next 数组内存 */
	free(next);
	return 0;
}
