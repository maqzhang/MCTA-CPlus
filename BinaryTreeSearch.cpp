#include "BinaryTreeSearch.h"
//2023年下午题目
// 文章参考：图文详解两种算法：深度优先遍历（DFS）和广度优先遍历（BFS）
//https://www.51cto.com/article/614590.html

// 全局索引变量,用于跟踪当前在数据数组中的位置
int index = 0;

/**
 * 二叉树构造器 - 按先序遍历顺序递归构造二叉树
 * 约定: 无左子树或右子树用'#'表示为空节点
 * 
 * @param root 二叉树根节点的引用
 * @param data 包含节点数据和空标记('#')的数组
 * 
 * 工作流程:
 * 1. 从数据数组中获取当前索引位置的元素,索引自动递增
 * 2. 如果元素为'#',表示该位置为空,设置节点为NULL
 * 3. 否则,为该节点分配内存并设置数据
 * 4. 递归构建左子树(先序遍历中左子树在右子树之前)
 * 5. 递归构建右子树
 */
void treeNodeConstructor(Tree& root, Element data[]) {
	// 获取数据数组中当前位置的元素,然后索引自增
	Element e = data[index++];
	
	// 判断当前节点是否为空(用'#'表示)
	if (e == '#') {
		root = NULL;  // 空节点
	}
	else {
		// 为新节点分配内存空间
		root = (Node*)malloc(sizeof(Node));
		
		// 设置节点数据
		root->data = e;
		
		// 递归构建左子树(先序遍历顺序:根->左->右)
		treeNodeConstructor(root->lchild, data);
		
		// 递归构建右子树
		treeNodeConstructor(root->rchild, data);
	}
}

/**
 * 深度优先搜索(DFS) - 使用栈的迭代方式遍历二叉树
 * 遍历顺序: 前序遍历(根->左->右)
 * 
 * @param root 二叉树根节点
 * 
 * 算法步骤:
 * 1. 使用栈存储待访问的节点
 * 2. 根节点入栈
 * 3. 当栈非空时,循环执行:
 *    - 从栈顶取出一个节点并访问(打印)
 *    - 先将右子树入栈(因为栈后进先出,这样左子树会先被访问)
 *    - 再将左子树入栈
 * 4. 直到栈为空,遍历完成
 */
void depthFirstSearch(Tree root) {
	// 创建栈,用于存储待访问的节点指针
	stack<Node*> nodeStack;
	
	// 根节点首先入栈
	nodeStack.push(root);
	
	// 临时变量,用于存储当前处理的节点
	Node* node;
	
	// 当栈非空时,继续循环
	while (!nodeStack.empty()) {
		// 获取栈顶节点
		node = nodeStack.top();
		
		// 访问(打印)当前节点的数据
		printf(format, node->data);
		
		// 从栈中移除该节点
		nodeStack.pop();
		
		// 将右子树入栈(先入后出)
		if (node->rchild) {
			nodeStack.push(node->rchild);
		}
		
		// 将左子树入栈(后入先出,所以左子树会先被处理)
		if (node->lchild) {
			nodeStack.push(node->lchild);
		}
	}
}

/**
 * 广度优先搜索(BFS) - 使用队列的方式遍历二叉树
 * 遍历顺序: 按层级遍历(逐层从左到右)
 * 
 * @param root 二叉树根节点
 * 
 * 算法步骤:
 * 1. 使用队列存储待访问的节点
 * 2. 根节点入队
 * 3. 当队列非空时,循环执行:
 *    - 从队列头部取出一个节点并访问(打印)
 *    - 将左子树(如果存在)入队
 *    - 将右子树(如果存在)入队
 * 4. 直到队列为空,遍历完成
 * 
 * 注: 先进先出的队列性质保证了按层级顺序访问节点
 */
void breadthFirstSearch(Tree root) {
	// 创建队列,用于存储待访问的节点指针
	queue<Node*> nodeQueue;
	
	// 根节点首先入队
	nodeQueue.push(root);
	
	// 临时变量,用于存储当前处理的节点
	Node* node;
	
	// 当队列非空时,继续循环
	while (!nodeQueue.empty()) {
		// 获取队列头部的节点
		node = nodeQueue.front();
		
		// 从队列中移除该节点
		nodeQueue.pop();
		
		// 访问(打印)当前节点的数据
		printf(format, node->data);
		
		// 将左子树入队(按顺序,保证层级遍历的正确性)
		if (node->lchild) {
			nodeQueue.push(node->lchild);
		}
		
		// 将右子树入队
		if (node->rchild) {
			nodeQueue.push(node->rchild);
		}
	}
}