// CPlusCourse.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "HeapSort.h"
#include "BinaryTreeSearch.h"
#include "MatrixMultiplication.h"
int main()
{/*
	//矩阵链乘法问题测试
	int n = 6;
	int seq[7] = { 30, 35, 15, 5, 10, 20, 25 };
	int minCost = cmm(n, seq);  // 返回最小乘法次数
	printf("矩阵乘法次数最少: ");
	printf("%d ", minCost);
	*/
	//上图所示的二叉树先序遍历序列,其中用'#'表示结点无左子树或无右子树
	Element data[15] = { 'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F','#', '#', 'G', '#', '#' };
	Tree tree;
	treeNodeConstructor(tree, data);
	printf("深度优先遍历二叉树结果: ");
	depthFirstSearch(tree);
	printf("\n\n广度优先遍历二叉树结果: ");
	breadthFirstSearch(tree);
	
	/*
	// 注意：数组按 1..n 使用，R[0] 用作暂存
	int R[MAXITEM] = { 0, 20, 5, 16, 8, 14, 2, 10 }; // R[0]=0 占位，n=7
	int n = 7;

	printf("排序前: ");
	for (int i = 1; i <= n; i++) printf("%d ", R[i]);
	printf("\n");

	HeapSort(R, n);

	printf("排序后: ");
	for (int i = 1; i <= n; i++) printf("%d ", R[i]);
	printf("\n");
	*/

	return 0;
}
