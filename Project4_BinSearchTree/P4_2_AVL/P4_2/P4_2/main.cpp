#include<stdlib.h>
#include<stdio.h>

//�б��������Ƿ�һ�£�
//����һ���������õݹ飬�Ӹ��ڵ��ٵ��������ٵ��������жϣ�һ�ǽ���������ֱ���б�����

typedef struct TreeNode* Tree;
struct TreeNode
{
	int v;
	Tree Left, Right;
	int flag;//��Ϊ��־,��1ʱ˵���ѱ��鿴
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

//N����N�����
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

//N��������
int judge(Tree T,int N) {
	int a, i;
	int flag = 0;//��flag����Ϊ1ʱ˵���Ѿ�������
	
	//�жϸ����
	scanf("%d", &a);
	if(!check(T,a)) flag = 1;

	for (i = 1; i < N; i++) {
		scanf("%d", &a);
		if (!check(T, a)) flag = 1;
	}

	if (flag) return 0;//����flag��������֤�����Ϻ����ɰѳ�������
	return 1;
}
//���������flag
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

//ƽ������BF(T) = hL - hR;
//ƽ������� ������������������ĸ߶Ȳ�ľ���ֵ������һ��|BF(T)| <= 1
//nhΪ�߶�Ϊh��ƽ�����������С���������nh = n(h-1) + n(n-2) + 1
//�ù�ʽ������쳲���������nh = F(h+2) - 1
//��nhԼ����1/����5*��1+����5/2��^(h+2) - 1
//����h = O(log2n)
//ƽ���������һ��������������������С�Ҵ�
//ƽ��������ĵ�����rr��ת,ll��ת,rl��ת��lr��ת