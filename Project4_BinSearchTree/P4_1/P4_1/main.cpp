#include<stdlib.h>
#include<stdio.h>

#define NULL 0
//������������
//�ǿ������������м�ֵС������ڵ�ļ�ֵ
//�ǿ������������м�ֵ��������ڵ�ļ�ֵ
//��������С�ļ�ֵ�ֱ�������˺����Ҷ�
//��ͬԪ�ز�ͬ�Ĳ���˳���õ���ͬ�Ķ���������

struct TreeNode {
	int Data;
	BinTree Left;
	BinTree Right;
};
typedef TreeNode* BinTree;

//�ݹ����
BinTree Find_Recursion(int x,BinTree BST) {
	if (!BST) return NULL;
	if (x < BST->Data) {
		return Find_Recursion(x,BST->Left);//ֱ��return�Ļ����Բ������к�������
	}
	else if (x > BST->Data) {
		return Find_Recursion(x, BST->Right);
	}
	else
		return BST;
}

//β���ݹ�ʱ�����õ���������ǵݹ��Ч�ʸ�
//���ǵݹ鲻���ƻ�BST��ԭ�ȵĸ��ڵ��ָ��
//��������
BinTree Find_Iterate(int x, BinTree BST) {
	while (BST) {
		if (x < BST->Data)
			BST = BST->Left;
		else if (x > BST->Data)
			BST = BST->Right;
		else
			return BST;
	}//�ж�������BST�ǿգ���ʡһ��if��䣬��BST������Ľ��ʱֱ��return����ѭ��
	return NULL;
}

//Ѱ�������СԪ��
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

//�ݹ�����ظ�ִ�����������ÿ�δ���һ��Ĳ���
BinTree Insert(int x, BinTree BT) {
	if (!BT) {
		BT = (BinTree)malloc(sizeof(struct TreeNode));
		BT->Data = x;
		BT->Left = BT->Right = NULL;
	}
	else if (x < BT->Data) {
		BT->Left = Insert(x,BT->Left);//���Խ��������
	}
	else if (x > BT->Data) {
		BT->Right = Insert(x, BT->Right);
	}
	return BT;
}

BinTree Delete(int x, BinTree BT) {
	BinTree Tmp;
	if (!BT) printf("�Ҳ���Ҫɾ����Ԫ��");
	else if (x < BT->Data) {
		BT->Left = Delete(x, BT->Left);//ÿ��ݹ��BT��ָ���Լ��Ľ��
	}
	else if (x > BT->Data) {
		BT->Right = Delete(x, BT->Right);
	}
	else {
		if (BT->Left && BT->Right) {
			Tmp = FindMin_Recursion(BT->Right);//Ѱ���ұ���СԪ���Դ��汻ɾԪ��
			BT->Data = Tmp->Data;
			BT->Right = Delete(BT->Data,BT->Right);//ɾ�����������е���СԪ��
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
	return BT;//ÿ��ݹ鷵���Լ���BT
}