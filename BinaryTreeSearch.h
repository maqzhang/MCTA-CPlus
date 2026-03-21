#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <Stack>
#include <Queue>
using namespace std;
#define Element char
#define format "%c"

typedef struct Node {
    Element data;
    struct Node* lchild;
    struct Node* rchild;
} *Tree;


//二叉树构造器,按先序遍历顺序构造二叉树
//无左子树或右子树用'#'表示
void treeNodeConstructor(Tree& root, Element data[]);
//深度优先遍历
void depthFirstSearch(Tree root);

//广度优先遍历
void breadthFirstSearch(Tree root);