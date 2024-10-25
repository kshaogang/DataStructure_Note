#include<stdlib.h>
#include<stdio.h>

//判别搜索树是否一致：
//方法一方法二采用递归，从根节点再到左子树再到右子树判断，一是建树，二是直接判别序列

typedef struct TreeNode* Tree;
struct TreeNode
{
	int v;
	Tree Left, Right;
	int flag;//作为标志,置1时说明已被查看
};

Tree MakeTree(int N);
Tree NewNode(int V);
Tree Insert(Tree T, int V);
int check(Tree T,int a);
int judge(Tree T,int N);
void Reset(Tree T);
void FreeTree(Tree T);

void main() {

}

Tree NewNode(int V) {
	Tree T = (Tree)malloc(sizeof(TreeNode));
	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
}

Tree Insert(Tree T, int V) {
	if (!T) T = NewNode(V);
	if (V < T->v) {
		T->Left = Insert(T->Left,V);
	}
	else if (V > T->v) {
		T->Right = Insert(T->Right, V);
	}
	return T;
}

//N代表N个结点
Tree MakeTree(int N) {
	Tree T;
	int i, V;

	scanf("%d", &V);
	T = NewNode(V);

	for (i = 1; i < N ; i++) {
		scanf("%d", &V);
		T = Insert(T, V);
	}
	return T;
}

int check(Tree T,int a) {
	if (T->flag) {
		if (a < T->v) check(T->Left, a);
		else if (a > T->v) check(T->Right, a);
		else return 0;
	}
	else {
		if (a = T->v) {
			T->flag = 1;
		}
		else return 0;
	}
}

//N代表结点数
int judge(Tree T,int N) {
	int a, i;
	int flag = 0;//当flag被置为1时说明已经不符合
	
	//判断根结点
	scanf("%d", &a);
	if(!check(T,a)) flag = 1;

	for (i = 1; i < N; i++) {
		scanf("%d", &a);
		if (!check(T, a)) flag = 1;
	}

	if (flag) return 0;//利用flag可以在验证不符合后依旧把程序跑完
	return 1;
}
//清除各结点的flag
void Reset(Tree T) {
	if (T->Left) Reset(T->Left);
	if (T->Right) Reset(T->Right);
	
	T->flag = 0;
}

void FreeTree(Tree T) {
	if (T->Left) FreeTree(T->Left);
	if (T->Right) FreeTree(T->Right);

	free(T);
}

//平衡因子BF(T) = hL - hR;
//平衡二叉树 ，任意结点的左右子树的高度差的绝对值不超过一，|BF(T)| <= 1
//nh为高度为h的平衡二叉树的最小结点树，则nh = n(h-1) + n(n-2) + 1
//该公式近似于斐波那契数列nh = F(h+2) - 1
//得nh约等于1/根号5*（1+根号5/2）^(h+2) - 1
//所以h = O(log2n)
//平衡二叉树是一个二叉搜索树（满足左小右大）
//平衡二叉树的调整：rr旋转,ll旋转,rl旋转，lr旋转