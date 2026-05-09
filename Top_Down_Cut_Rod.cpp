#include <stdio.h>
#include "Top_Down_Cut_Rod.h"

int bak_5main() {
	/* 钢条价格表，p[i] 表示长度为 i 的钢条的价格，p[0] 不使用 */
	int p[] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };

	/* 待切割的钢条长度 */
	int n = 10;

	/* 调用自顶向下递归方法求最优收益 */
	int result1 = Top_Down_Cut_Rod(p, n);
	printf("自顶向下最优收益: %d\n", result1);

	/* 调用自底向上动态规划方法求最优收益 */
	int result2 = Bottom_Up_Cut_Rod(p, n);
	printf("自底向上最优收益: %d\n", result2);

	return 0;
}
