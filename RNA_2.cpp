/* 禁用 MSVC 对不安全 CRT 函数（如 scanf）的弃用警告 */
#define _CRT_SECURE_NO_WARNINGS
#include "RNA_2.h"
#include <windows.h>

int bak_4main() {
	/* 设置控制台输入输出编码为 UTF-8，解决中文乱码问题 */
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	/* 存储 RNA 序列，下标从 1 开始，B[0] 不使用 */
	char B[LEN];
	/* RNA 序列的长度 */
	int n;

	/* 提示用户输入 RNA 序列长度 */
	printf("请输入 RNA 序列长度 n（n < %d）：", LEN);
	scanf("%d", &n);

	/* 校验输入长度，防止数组越界 */
	if (n <= 0 || n >= LEN) {
		printf("错误：n 必须在 1 到 %d 之间。\n", LEN - 1);
		return 1;
	}

	/* 提示用户输入 RNA 序列，仅包含 A、U、C、G 四种碱基 */
	printf("请输入 RNA 序列（仅含 A、U、C、G）：");
	/* 从下标 1 开始存储，与算法中数组下标保持一致 */
	for (int i = 1; i <= n; i++) {
		scanf(" %c", &B[i]);
	}

	printf("\n各子区间最大配对数：\n");

	/* 调用动态规划函数，计算整条 RNA 链的最大碱基配对数 */
	int result = RNA_2(B, n);

	/* 输出最终结果 */
	printf("\nRNA 序列最大碱基配对数为：%d\n", result);

	return 0;
}
