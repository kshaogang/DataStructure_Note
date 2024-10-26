#include<stdlib.h>
#include<stdio.h>

#define MaxData 1000
//测试数据：一定要有边界测试！！！

//堆：数组存储的完全二叉树，有最大堆和最小堆
//最大堆：每个结点的元素值不小于其子结点的元素值

typedef struct HeapStruct* MaxHeap;
struct HeapStruct {
	int* Elements;//一个数组的指针（不是数组本身）
	int Size;//当前堆的元素个数 
	int Capacity;//堆的最大容量
};

MaxHeap Create(int MaxSize) {
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
	//使用malloc需要显式地进行类型转换
	H->Elements = (int*)malloc((MaxSize + 1) * sizeof(int));//从下标1开始存放数据，下标0用于哨兵
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData;//因为Elements已经被分配了内存，所以可以访问到0的位置
	//表达式 Elements[0] 实际上是等价于 *(Elements + 0)，语法合法
	return H;
}

void Insert(int x, MaxHeap H) {
	int i;
	if (IsFull(H)) {
		printf("堆已满");
		return;
	}
	i = ++H->Size;//将x插入堆的最末尾

	//边界：x是数组的最大值时，i=1会和i=0比较，而0作为哨兵结点，可以免去i>1的条件
	//为什么不把下标0也用于存放元素？
	//左孩子位于2i，右孩子位于2i+1，其父节点位于i/2，不需要进行额外的条件判断来处理根节点的情况。
	//与其他文献保持一致

	for (; H->Elements[i / 2] < x; i /= 2) {
		H->Elements[i] = H->Elements[i / 2];
	}//Elements[i/2]是其父结点
	H->Elements[i] = x;
}

int DeleteMax( MaxHeap H) {
	int Parent, Child;
	int MaxItem, temp;
	if (IsEmpty(H)) {
		printf("堆已空");
		return;
	}
	MaxItem = H->Elements[1];
	temp = H->Elements[H->Size--];//先赋值再自减
	//删除一个元素后size减一
	
	//判断条件是存在左子结点（<=）
	for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {
		Child = 2 * Parent;
		//找出大的子结点
		if (Child != H->Size && H->Elements[Child] < H->Elements[++Child]) {
			Child++;
		}
		if (temp > H->Elements[Child]) break;
		else {
			H->Elements[Parent] = H->Elements[Child];
		}
	}
	//for循环里其实temp没有动，只是parent一直在向下过滤，直到temp插入，而第一个元素已被过滤
	H->Elements[Parent] = temp;
	return MaxItem;
}