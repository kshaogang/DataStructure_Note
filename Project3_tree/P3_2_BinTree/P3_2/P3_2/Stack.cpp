#include<Stack.h>

int isEmpty(Stack s) {
	return (s->Next == NULL);
}//ջΪ�շ���1����ʽ�����������򷵻�0

int Pop(Stack s) {
	if (isEmpty(s) ){
		printf("ջΪ��");
		return 0;
	}

	//�ͷ��׽ڵ㲢��ͷ������ӵ��µ��׽ڵ�
	Stack Temp = s->Next;
	int a = s->Data;
	s = Temp->Next;
	free(Temp);
	return a;
}

//����ͷ���
Stack CreatStack() {
	Stack S;//��ջ�Ϸ����ڴ����洢ָ������������ָ��ָ����ϵ�ĳ���ط�
	S = (Stack)malloc(sizeof(SNode));//�ڶ��϶�̬�����ڴ棬�����ϵ��ڴ��ָ�븳��S
	S->Next = NULL;
	return S;
}
//���ڶѺ�ջ��ջ�ڴ�ķ����ٶȿ죬���ǿռ����ޣ��������������뺯��������ء�
// ���ڴ�ķ����ٶ���Խ��������ǿ����ṩ������ڴ�ռ䡣
//����������ʱ���Զ��ͷ�ջ���ڴ棬���ѵ��ڴ���Ҫ�ֶ��ͷ�

void Push(int item, Stack S) /* ��Ԫ��itemѹ���ջS */
{
}