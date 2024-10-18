#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
/*堆栈 Stack
具有一定操作约束的线性表，只在一端(栈顶，Top)做 插入、删除*/
//栈的顺序存储实现
typedef struct SNode* Strack;
struct SNode {
	int Data[MaxSize];
	int Top;//栈顶的数组下标
	struct SNode* Next;
	int data;
};

//1.入栈
void Push(int x, Strack S)
{
	if (S->Top == MaxSize - 1)
	{
		printf("栈已满");
		return;
	}
	else
	{
		S->Data[++(S->Top)] = x;//先将Top+1后x入栈
		return;
	}
}

//2.出栈
int Pop(Strack S)
{
	if (S->Top == -1)//数组下标为-1表示空数组
	{
		printf("栈已空");
		return NULL;
	}
	else
	{
		return S->Data[(S->Top)--];//先pop出栈顶，再Top减一
	}
}

//栈的链式存储
//注意链式存储只能用表头当栈顶,若用表尾的话无法找到前一个节点

//1.初始化建立空栈
Strack Creat()
{
	Strack s;//建立一个指针
	s = (Strack)malloc(sizeof(struct SNode));//给指针分配空间
	s->Next = NULL;
	return s;
}

//2.判断堆栈是否为空
int IsEmpty(Strack S) {
	return (S->Next == NULL);
}

//3.入栈
void Push(int x, Strack S)
{
	Strack Tmpcell;
	//想要入栈先创造一个节点并放入x
	Tmpcell = (Strack)malloc(sizeof(struct SNode));
	Tmpcell->data = x;
	//插入节点的标准操作
	Tmpcell->Next = S->Next;
	S->Next = Tmpcell;
}

//4.出栈
int Pop(Strack S) {
	Strack Tmpcell;
	int a;
	if (IsEmpty(S))
	{
		printf("堆栈空");
		return NULL;
	}
	else {
		Tmpcell = S->Next;
		S->Next = Tmpcell->Next;//将S的节点指向下一个节点，即删除原先的表头
		a = Tmpcell->data;
		free(Tmpcell);
		return a;
	}
}
//要理解S只是指向表头，而不是表头
//然而在链式结构的堆栈里面，S指向的是堆栈的头结点，不是栈顶