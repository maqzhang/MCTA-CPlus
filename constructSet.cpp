#include "constructSet.h"

int m = 0; /* 最大连接集合中的连线数量 */

/* 求最大不相交连接数（动态规划） */
void maxNum(int pi[], int size[N + 1][N + 1], int n) {
	/* size[0][j] = 0，已由数组初始化为0 */
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (j < pi[i]) {
				/* 第 i 条连线的下端编号 pi[i] > j，不能选第 i 条 */
				size[i][j] = size[i - 1][j];
			} else {
				/* 可以选第 i 条连线（下端编号 pi[i] <= j） */
				int withI = size[i - 1][pi[i] - 1] + 1;
				int withoutI = size[i - 1][j];
				size[i][j] = withI > withoutI ? withI : withoutI;
			}
		}
	}
}

/* 构造最大不相交连接集合 */
void constructSet(int pi[], int size[N + 1][N + 1], int n, int net[]) {
	m = 0;
	int j = n;
	for (int i = n; i >= 1; i--) {
		/* 若选了第 i 条连线，则 size[i][j] != size[i-1][j] */
		if (size[i][j] != size[i - 1][j]) {
			net[m++] = i;
			j = pi[i] - 1; /* 下端接线柱编号限制缩小 */
		}
	}
}

int constructSetMain() {
	int n = N;
	int pi[N + 1] = { 0, 3, 2, 5, 1, 9, 6, 4, 8, 7, 10 };
	int size[N + 1][N + 1] = { 0 };
	int net[N + 1] = { 0 };

	maxNum(pi, size, n);
	constructSet(pi, size, n, net);
	return size[n][n];
}

int bak10_main() {
	/* 接线柱数量（使用问题规模 N） */
	int n = N;

	/* pi[i] 表示第 i 条连线下端接线柱的编号（下标从1开始，下标0不使用） */
	int pi[N + 1] = { 0, 3, 2, 5, 1, 9, 6, 4, 8, 7, 10 };

	/* 动态规划表 */
	int size[N + 1][N + 1] = { 0 };

	/* net[k] 存储最大不相交子集中第 k 条连线的上端接线柱序号 */
	int net[N + 1] = { 0 };

	/* 求最大不相交连接数 */
	maxNum(pi, size, n);

	/* 输出动态规划表 */
	printf("动态规划表 size[i][j]:\n");
	printf("     ");
	for (int j = 0; j <= n; j++) printf("j=%-3d", j);
	printf("\n");
	for (int i = 1; i <= n; i++) {
		printf("i=%2d:", i);
		for (int j = 0; j <= n; j++) printf("%-5d", size[i][j]);
		printf("\n");
	}

	/* 输出最大不相交连接数 */
	printf("\n最大不相交连接数: %d\n", size[n][n]);

	/* 构造最大不相交连接集合 */
	constructSet(pi, size, n, net);

	/* 输出最大不相交连接集合的连线 */
	printf("\n最大不相交连接集合（共 %d 条）:\n", m);
	for (int k = 0; k < m; k++) {
		printf("  上端接线柱: %d  ->  下端接线柱: %d\n", net[k], pi[net[k]]);
	}

	return 0;
}
