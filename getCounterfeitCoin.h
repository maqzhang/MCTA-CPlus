#pragma once
/*
* 2017年上半年 软件设计师 下午试卷
试题四（共 15 分）
阅读下列说明和 C 代码，回答问题 1 至问题 3，将解答填入答题纸的对应栏内。
【说明】
假币问题：有 n 枚硬币，其中有一枚是假币，已知假币的重量较轻。现只有一个天平，
要求用尽量少的比较次数找出这枚假币。
【分析问题】
将 n 枚硬币分成相等的两部分：
（1）当 n 为偶数时，将前后两部分，即 1…n/2 和 n/2+1…n，放在天平的两端，较轻
的一端里有假币，继续在较轻的这部分硬币中用同样的方法找出假币；
（2）当 n 为奇数时，将前后两部分，即 1…(n-1)/2 和(n+1)/2+1…n，放在天平的两端，
较轻的一端里有假币，继续在较轻的这部分硬币中用同样的方法找出假币；若两端重量相等，
则中间的硬币，即第(n+1)/2 枚硬币是假币。
*/
#include <stdio.h>

/* 递归查找假币：coins为硬币数组，first为起始下标，last为终止下标 */
/* 假币比真币轻，返回假币的下标 */
int getCounterfeitCoin(int coins[], int first, int last) {
	int firstSum = 0, lastSum = 0;
	int i;
	if (first == last - 1) { /* 只剩两枚硬币 */
		if (coins[first] < coins[last])
			return first;
		return last;
	}
	if ((last - first + 1) % 2 == 0) { /* 偶数枚硬币 */
		/* 累加前半段硬币重量，前半段范围：[first, first+(last-first)/2] */
		for (i = first; i < first + (last - first) / 2 + 1; i++) { /* (1) 前半段上界为 first+(last-first)/2+1 */
			firstSum += coins[i];
		}
		/* 累加后半段硬币重量，后半段范围：[first+(last-first)/2+1, last] */
		for (i = first + (last - first) / 2 + 1; i < last + 1; i++) {
			lastSum += coins[i];
		}
		/* (2) 若前半段总重量小于后半段，说明假币在前半段 */
		if (firstSum < lastSum) { /* (2) 判断条件：前半段较轻则假币在前半段 */
			return getCounterfeitCoin(coins, first,
				first + (last - first) / 2);
		}
		else {
			/* 否则假币在后半段 */
			return getCounterfeitCoin(coins,
				first + (last - first) / 2 + 1, last);
		}
	}
	else { /*奇数枚硬币*/
		/* 累加前半段硬币重量，跳过中间那枚 */
		for (i = first; i < first + (last - first) / 2; i++) {
			firstSum += coins[i];
		}
		/* 累加后半段硬币重量，跳过中间那枚 */
		for (i = first + (last - first) / 2 + 1; i < last + 1; i++) {
			lastSum += coins[i];
		}
		if (firstSum < lastSum) {
			/* 前半段较轻，假币在前半段 */
			return getCounterfeitCoin(coins, first,
				first + (last - first) / 2 - 1);
		}
		else if (firstSum > lastSum) {
			/* 后半段较轻，假币在后半段 */
			return getCounterfeitCoin(coins,
				first + (last - first) / 2 + 1, last);
		}
		else {
			/* 两段重量相等，假币就是中间那枚 */
			return first + (last - first) / 2; /* (3) 返回中间元素下标：first+(last-first)/2 */
		}
	}
}