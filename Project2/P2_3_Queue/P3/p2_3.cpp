#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10//���崢��Ԫ�ص�������

//����Queue��ʹ��˳��洢ʵ��
struct QNode {
	int Data[MaxSize];
	int rear;//ָ�����һ��Ԫ�ص�λ��
	int front;//ָ���һ��Ԫ�ص�ǰһ��λ��
	//rear��front�����±�
};
//�ж϶��пպ�����rear��front�����λ����N��״̬����������N+1�֡�
//�����������ʹ��n-1������ռ��ʹ�ö�����size/tag

typedef struct QNode* Queue;//typedef���ڸ��Ѵ��ڵ��������ʹ���һ������

void AddQ(int x, Queue Q) {
	if (Q->rear+1%MaxSize == Q->front) {
		printf("������");//��ʹ����n-1���ռ�ʱ��������
		return ;//void����return NULL
	}
	Q->rear = (Q->rear + 1) % MaxSize;//ʹ��������������ѭ��
	Q->Data[Q->rear] = x;
}

int DeleteQ(Queue Q) {
	if (Q->front == Q->rear) {
		printf("���п�");
		return;
	}
	Q->front = (Q->front + 1) % MaxSize;
	return Q->Data[Q->front];//���ֵ���ɴ��ڵ�����ҪAddʱ�ᱻ���ǣ���������Ŀռ��ѱ�������
}

//���е���ʽ�洢ʵ��
//�����ͷ��front,�����ǵ������������

struct Node {
	int Data;
	struct Node* Next;
};//����ṹ���������������Ľڵ�

struct QQNode {
	struct Node* Front;
	struct Node* Rear;
};//����ṹ������������У���Front��Rear

typedef struct QQNode* QQueue;
QQueue PQ;

//����
int DeletQQ(QQueue PQ) {
	if (PQ->Front == NULL)
	{
		printf("���п�");
		return 0;
	}
	struct Node* Frontcell = PQ->Front;
	/*����QQueue Frontcell = PQ;��Ϊ�����ͷ� PQ ��ָ����ڴ�飬
	֮�� PQ �� Frontcell ������Ϊ��Чָ��*/
	int Tmpcell;
	if (PQ->Front == PQ->Rear)
	{
		PQ->Front = PQ->Rear = NULL;
	}
	else
	{
		PQ->Front = Frontcell->Next;
	}
	Tmpcell = Frontcell->Data;
	free(Frontcell);
	return Tmpcell;
}