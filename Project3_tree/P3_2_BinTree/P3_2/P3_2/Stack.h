#include<stdio.h>//����NULLΪ0
#include<stdlib.h>

//ջ��˳��洢ͨ����һ��һά�����һ����¼ջ����Ԫ�ر�������
//ջ����ʽ�洢��һ�������������ɾ���Ĳ�����ֻ��ջ������ͷ����
//ע������ջ��ͷ�����׽��
//�׽ڵ��ǵ�һ������Ԫ�صĽ�㣬ͷ���ָ���׽ڵ㣬����Ϊ�ջ��ߴ洢������Ϣ
struct SNode {
	int Data;
	Stack Next;//��������¼
};
typedef SNode* Stack;

int isEmpty(Stack s);
int Pop(Stack s);
Stack CreatStack();
void Push(Stack S,BinTree T);
