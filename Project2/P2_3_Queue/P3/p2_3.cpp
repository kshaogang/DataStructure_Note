#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10//定义储存元素的最大个数

//队列Queue：使用顺序存储实现
struct QNode {
	int Data[MaxSize];
	int rear;//指向最后一个元素的位置
	int front;//指向第一个元素的前一个位置
	//rear和front都是下标
};
//判断队列空和满：rear和front的相对位置有N种状态，而队列有N+1种。
//解决方案：仅使用n-1个数组空间或使用额外标记size/tag

typedef struct QNode* Queue;//typedef用于给已存在的数据类型创建一个别名

void AddQ(int x, Queue Q) {
	if (Q->rear+1%MaxSize == Q->front) {
		printf("队列满");//当使用了n-1个空间时数组已满
		return ;//void不能return NULL
	}
	Q->rear = (Q->rear + 1) % MaxSize;//使用余数来让数组循环
	Q->Data[Q->rear] = x;
}

int DeleteQ(Queue Q) {
	if (Q->front == Q->rear) {
		printf("队列空");
		return;
	}
	Q->front = (Q->front + 1) % MaxSize;
	return Q->Data[Q->front];//这个值依旧存在但当需要Add时会被覆盖，而且数组的空间已被分配了
}

//队列的链式存储实现
//链表的头作front,依旧是单向链表的问题

struct Node {
	int Data;
	struct Node* Next;
};//这个结构体用来代表队列里的节点

struct QQNode {
	struct Node* Front;
	struct Node* Rear;
};//这个结构体用来代表队列，即Front和Rear

typedef struct QQNode* QQueue;
QQueue PQ;

//出队
int DeletQQ(QQueue PQ) {
	if (PQ->Front == NULL)
	{
		printf("队列空");
		return 0;
	}
	struct Node* Frontcell = PQ->Front;
	/*不是QQueue Frontcell = PQ;因为将会释放 PQ 所指向的内存块，
	之后 PQ 和 Frontcell 都将变为无效指针*/
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