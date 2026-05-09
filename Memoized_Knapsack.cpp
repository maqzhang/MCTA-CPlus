#include "Memoized_Knapsack.h"

int bak3_main() {
    // 定义6个物品的价值数组（索引0不使用，物品编号从1开始）
    int v[N] = { 0, 6, 3, 5, 4, 6 };
    // 定义6个物品的重量数组（索引0不使用，物品编号从1开始）
    int w[N] = { 0, 2, 2, 6, 5, 4 };
    // 定义背包最大承重容量
    int T = 10;

    // 调用记忆化搜索求解0-1背包问题，返回最大价值
    int result = Memoized_Knapsack(v, w, T);

    // 输出最优装包方案所能获得的最大价值
    printf("背包最大价值为: %d\n", result);

    return 0;
}
