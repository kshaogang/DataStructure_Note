#include<stdlib.h>
#include<stdio.h>

#define NULL 0
//二叉搜索树：
//非空左子树的所有键值小于其根节点的键值
//非空右子树的所有键值大于其根节点的键值
//即最大和最小的键值分别在最左端和最右端
//相同元素不同的插入顺序会得到不同的二叉搜索树

struct TreeNode {
	int Data;
	BinTree Left;
	BinTree Right;
};
typedef TreeNode* BinTree;

//递归查找
BinTree Find_Recursion(int x,BinTree BST) {
	if (!BST) return NULL;
	if (x < BST->Data) {
		return Find_Recursion(x,BST->Left);//直接return的话可以不用运行后面的语句
	}
	else if (x > BST->Data) {
		return Find_Recursion(x, BST->Right);
	}
	else
		return BST;
}

//尾部递归时可以用迭代替代，非递归的效率高
//但是递归不会破坏BST的原先的根节点的指向
//迭代查找
BinTree Find_Iterate(int x, BinTree BST) {
	while (BST) {
		if (x < BST->Data)
			BST = BST->Left;
		else if (x > BST->Data)
			BST = BST->Right;
		else
			return BST;
	}//判断条件是BST非空，节省一个if语句，当BST是所求的结点时直接return结束循环
	return NULL;
}

//寻找最大最小元素
BinTree FindMin_Recursion(BinTree BST) {
	if (!BST) return NULL;
	else if (BST->Left)
		return FindMin_Recursion(BST->Left);
	else
		return BST;
}

BinTree FindMax_Iterate(BinTree BST) {
	while (BST) {
		if (!BST->Right) {
			return BST;
		}
		BST = BST->Right;
	}
	return NULL;
}

//递归就是重复执行这个函数，每次传下一层的参数
BinTree Insert(int x, BinTree BT) {
	if (!BT) {
		BT = (BinTree)malloc(sizeof(struct TreeNode));
		BT->Data = x;
		BT->Left = BT->Right = NULL;
	}
	else if (x < BT->Data) {
		BT->Left = Insert(x,BT->Left);//可以将结点链接
	}
	else if (x > BT->Data) {
		BT->Right = Insert(x, BT->Right);
	}
	return BT;
}

BinTree Delete(int x, BinTree BT) {
	BinTree Tmp;
	if (!BT) printf("找不到要删除的元素");
	else if (x < BT->Data) {
		BT->Left = Delete(x, BT->Left);//每层递归的BT都指代自己的结点
	}
	else if (x > BT->Data) {
		BT->Right = Delete(x, BT->Right);
	}
	else {
		if (BT->Left && BT->Right) {
			Tmp = FindMin_Recursion(BT->Right);//寻找右边最小元素以代替被删元素
			BT->Data = Tmp->Data;
			BT->Right = Delete(BT->Data,BT->Right);//删除在右子树中的最小元素
		}
		else {
			if (!BT->Right) {
				Tmp = BT;
				BT = BT->Left;
				free(Tmp);
			}
			if (!BT->Left) {
				Tmp = BT;
				BT = BT->Right;
				free(Tmp);
			}
		}
	}
	return BT;//每层递归返回自己的BT
}