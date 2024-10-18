#include<stdio.h>//定义NULL为0
#include<stdlib.h>

//栈的顺序存储通常由一个一维数组和一个记录栈顶的元素变量构成
//栈的链式存储是一个单链表，插入和删除的操作都只在栈顶即表头进行
//注意区分栈的头结点和首结点
//首节点是第一个储存元素的结点，头结点指向首节点，可以为空或者存储附加信息
struct SNode {
	int Data;
	Stack Next;//由整数记录
};
typedef SNode* Stack;

int isEmpty(Stack s);
int Pop(Stack s);
Stack CreatStack();
void Push(Stack S,BinTree T);
