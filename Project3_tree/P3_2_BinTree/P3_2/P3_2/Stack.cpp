#include<Stack.h>

int isEmpty(Stack s) {
	return (s->Next == NULL);
}//栈为空返回1（等式成立），否则返回0

int Pop(Stack s) {
	if (isEmpty(s) ){
		printf("栈为空");
		return 0;
	}

	//释放首节点并将头结点链接到新的首节点
	Stack Temp = s->Next;
	int a = s->Data;
	s = Temp->Next;
	free(Temp);
	return a;
}

//创建头结点
Stack CreatStack() {
	Stack S;//在栈上分配内存来存储指针变量本身，这个指针指向堆上的某个地方
	S = (Stack)malloc(sizeof(SNode));//在堆上动态分配内存，将堆上的内存的指针赋给S
	S->Next = NULL;
	return S;
}
//关于堆和栈：栈内存的分配速度快，但是空间有限，而且生命周期与函数调用相关。
// 堆内存的分配速度相对较慢，但是可以提供更大的内存空间。
//当函数结束时，自动释放栈的内存，而堆的内存需要手动释放

void Push(int item, Stack S) /* 将元素item压入堆栈S */
{
}