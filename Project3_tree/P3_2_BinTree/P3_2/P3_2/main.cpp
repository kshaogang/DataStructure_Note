#include<stdio.h>
#include<Stack.h>

//����˳��洢���������������߽�һ����������������������
//��������洢����������һ������������ָ�룩

typedef struct TreeNode* BinTree;
typedef BinTree Position;
struct TreeNode {
	int Data;
	BinTree Left;
	BinTree Right;
};

//���������������1.���ʸ��ڵ㣬2.���������������3.�������������
//���õݹ��˼�룺ͨ���ݹ��ܻص��ϲ�Ľ��
//�����
void PreOrderTrabersal(BinTree BT) {
	if (BT) {
		printf("%d",BT->Data);
		PreOrderTrabersal(BT->Left);
		PreOrderTrabersal(BT->Right);
	}
}

//���������1.�����������������2.���ʸ��ڵ㣬3.���������������
//Ҳ�ǵݹ��˼��

void InOrderTrabersal(BinTree BT) {
	if (BT) {
		InOrderTrabersal(BT->Left);
		printf("%d", BT->Data);
		InOrderTrabersal(BT->Right);
	}
}

//���������1.���������������2.���������������3.���ʸ��ڵ�
void PostOrderTrabersal(BinTree BT) {
	if (BT) {
		PostOrderTrabersal(BT->Left);
		PostOrderTrabersal(BT->Right);
		printf("%d", BT->Data);
	}
}

//��������·��һ����ֻ�Ƿ��ʸ��ڵ��ʱ����ͬ
//��ʵ���к���ֻ���ȴ�ӡ����������ѭ��

//����ǵݹ������
//1.�����ڵ��ѹջ����������������������������󣬴�ջ����������������ڵ㣬�ٴ�����ָ���������
//�ؼ��Ƕ�ջ�Ľṹ����Ͱ����˵ݹ������
void InOrderTraversal(BinTree BT) {
	Stack S = CreatStack();//�������ü����ţ�����
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

//���������������Ƕ�ά�ṹ�����Ի�
//���������ʹ�ö�ջ���游�ڵ�(�����������Ǹ��ǵݹ������)����ʹ�ö��б���δ���ʵ��ӽ��
//�Ӷ���ȡһ��Ԫ�أ����ʸ�Ԫ����ָ�Ľ�㣬�������Ҷ��ӵ�ָ�����
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

