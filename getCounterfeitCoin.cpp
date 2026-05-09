#include "getCounterfeitCoin.h"
#include <stdio.h>

int bak7_main() {
	/* 测试用例1：偶数枚硬币，假币（重量为1）在下标2 */
	int coins1[] = { 2, 2, 1, 2, 2, 2 };
	int n1 = sizeof(coins1) / sizeof(coins1[0]);
	int result1 = getCounterfeitCoin(coins1, 0, n1 - 1);
	printf("测试1（偶数枚）：假币下标 = %d（期望：2）\n", result1);

	/* 测试用例2：奇数枚硬币，假币（重量为1）在下标3（中间位置） */
	int coins2[] = { 2, 2, 2, 1, 2, 2, 2 };
	int n2 = sizeof(coins2) / sizeof(coins2[0]);
	int result2 = getCounterfeitCoin(coins2, 0, n2 - 1);
	printf("测试2（奇数枚，假币在中间）：假币下标 = %d（期望：3）\n", result2);

	/* 测试用例3：奇数枚硬币，假币（重量为1）在下标5 */
	int coins3[] = { 2, 2, 2, 2, 2, 1, 2 };
	int n3 = sizeof(coins3) / sizeof(coins3[0]);
	int result3 = getCounterfeitCoin(coins3, 0, n3 - 1);
	printf("测试3（奇数枚，假币在后半段）：假币下标 = %d（期望：5）\n", result3);

	return 0;
}
