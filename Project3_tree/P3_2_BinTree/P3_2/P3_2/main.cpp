#include<stdio.h>
#include<Stack.h>

//树的顺序存储：完美二叉树或者将一般二叉树补充成完美二叉树
//树的链表存储：二叉树（一个结点最多两个指针）

typedef struct TreeNode* BinTree;
typedef BinTree Position;
struct TreeNode {
	int Data;
	BinTree Left;
	BinTree Right;
};

//二叉树先序遍历：1.访问根节点，2.先序遍历左子树，3.先序遍历右子树
//采用递归的思想：通过递归能回到上层的结点
//传入根
void PreOrderTrabersal(BinTree BT) {
	if (BT) {
		printf("%d",BT->Data);
		PreOrderTrabersal(BT->Left);
		PreOrderTrabersal(BT->Right);
	}
}

//中序遍历：1.中序遍历其左子树，2.访问根节点，3.中序遍历其右子树
//也是递归的思想

void InOrderTrabersal(BinTree BT) {
	if (BT) {
		InOrderTrabersal(BT->Left);
		printf("%d", BT->Data);
		InOrderTrabersal(BT->Right);
	}
}

//后序遍历：1.后序遍历左子树，2.后序遍历右子树，3.访问根节点
void PostOrderTrabersal(BinTree BT) {
	if (BT) {
		PostOrderTrabersal(BT->Left);
		PostOrderTrabersal(BT->Right);
		printf("%d", BT->Data);
	}
}

//遍历结点的路线一样，只是访问各节点的时机不同
//其实先中后序只是先打印还是先跳出循环

//中序非递归遍历：
//1.遇到节点就压栈，遍历其左子树，左子树遍历完后，从栈顶弹出并访问这个节点，再从其右指针中序遍历
//关键是堆栈的结构本身就包含了递归的属性
void InOrderTraversal(BinTree BT) {
	Stack S = CreatStack();//函数调用加括号！！！
	BinTree T = BT;
	while (T || !isEmpty(S) ){
		while (T) {
			Push(S,T);
			T = T->Left;
		}
		if (!isEmpty(S)) {
			T = Pop(S);
			printf("%d", T->Data);
			T = T->Right;
		}
	}
}

//二叉树遍历本质是二维结构的线性化
//层序遍历：使用堆栈储存父节点(不就是上面那个非递归遍历吗)或者使用队列保存未访问的子结点
//从队列取一个元素，访问该元素所指的结点，将其左右儿子的指针入队
void LevelOrderTraversal(BinTree BT) {
	Queue Q; BinTree T;
	if (!BT) return;
	AddQ(Q, BT);
	while (!isEmptyQ(Q)){
		T = DeleteQ(Q);
		if (T->Left) AddQ(Q, T->Left);
		if (T->Right)AddQ(Q, T->Right);
	}
}

