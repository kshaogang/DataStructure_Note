#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
/*��ջ Stack
����һ������Լ�������Ա�ֻ��һ��(ջ����Top)�� ���롢ɾ��*/
//ջ��˳��洢ʵ��
typedef struct SNode* Strack;
struct SNode {
	int Data[MaxSize];
	int Top;//ջ���������±�
	struct SNode* Next;
	int data;
};

//1.��ջ
void Push(int x, Strack S)
{
	if (S->Top == MaxSize - 1)
	{
		printf("ջ����");
		return;
	}
	else
	{
		S->Data[++(S->Top)] = x;//�Ƚ�Top+1��x��ջ
		return;
	}
}

//2.��ջ
int Pop(Strack S)
{
	if (S->Top == -1)//�����±�Ϊ-1��ʾ������
	{
		printf("ջ�ѿ�");
		return NULL;
	}
	else
	{
		return S->Data[(S->Top)--];//��pop��ջ������Top��һ
	}
}

//ջ����ʽ�洢
//ע����ʽ�洢ֻ���ñ�ͷ��ջ��,���ñ�β�Ļ��޷��ҵ�ǰһ���ڵ�

//1.��ʼ��������ջ
Strack Creat()
{
	Strack s;//����һ��ָ��
	s = (Strack)malloc(sizeof(struct SNode));//��ָ�����ռ�
	s->Next = NULL;
	return s;
}

//2.�ж϶�ջ�Ƿ�Ϊ��
int IsEmpty(Strack S) {
	return (S->Next == NULL);
}

//3.��ջ
void Push(int x, Strack S)
{
	Strack Tmpcell;
	//��Ҫ��ջ�ȴ���һ���ڵ㲢����x
	Tmpcell = (Strack)malloc(sizeof(struct SNode));
	Tmpcell->data = x;
	//����ڵ�ı�׼����
	Tmpcell->Next = S->Next;
	S->Next = Tmpcell;
}

//4.��ջ
int Pop(Strack S) {
	Strack Tmpcell;
	int a;
	if (IsEmpty(S))
	{
		printf("��ջ��");
		return NULL;
	}
	else {
		Tmpcell = S->Next;
		S->Next = Tmpcell->Next;//��S�Ľڵ�ָ����һ���ڵ㣬��ɾ��ԭ�ȵı�ͷ
		a = Tmpcell->data;
		free(Tmpcell);
		return a;
	}
}
//Ҫ���Sֻ��ָ���ͷ�������Ǳ�ͷ
//Ȼ������ʽ�ṹ�Ķ�ջ���棬Sָ����Ƕ�ջ��ͷ��㣬����ջ��