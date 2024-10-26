#include<stdlib.h>
#include<stdio.h>

#define MaxData 1000
//�������ݣ�һ��Ҫ�б߽���ԣ�����

//�ѣ�����洢����ȫ�������������Ѻ���С��
//���ѣ�ÿ������Ԫ��ֵ��С�����ӽ���Ԫ��ֵ

typedef struct HeapStruct* MaxHeap;
struct HeapStruct {
	int* Elements;//һ�������ָ�루�������鱾��
	int Size;//��ǰ�ѵ�Ԫ�ظ��� 
	int Capacity;//�ѵ��������
};

MaxHeap Create(int MaxSize) {
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
	//ʹ��malloc��Ҫ��ʽ�ؽ�������ת��
	H->Elements = (int*)malloc((MaxSize + 1) * sizeof(int));//���±�1��ʼ������ݣ��±�0�����ڱ�
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData;//��ΪElements�Ѿ����������ڴ棬���Կ��Է��ʵ�0��λ��
	//���ʽ Elements[0] ʵ�����ǵȼ��� *(Elements + 0)���﷨�Ϸ�
	return H;
}

void Insert(int x, MaxHeap H) {
	int i;
	if (IsFull(H)) {
		printf("������");
		return;
	}
	i = ++H->Size;//��x����ѵ���ĩβ

	//�߽磺x����������ֵʱ��i=1���i=0�Ƚϣ���0��Ϊ�ڱ���㣬������ȥi>1������
	//Ϊʲô�����±�0Ҳ���ڴ��Ԫ�أ�
	//����λ��2i���Һ���λ��2i+1���丸�ڵ�λ��i/2������Ҫ���ж���������ж���������ڵ�������
	//���������ױ���һ��

	for (; H->Elements[i / 2] < x; i /= 2) {
		H->Elements[i] = H->Elements[i / 2];
	}//Elements[i/2]���丸���
	H->Elements[i] = x;
}

int DeleteMax( MaxHeap H) {
	int Parent, Child;
	int MaxItem, temp;
	if (IsEmpty(H)) {
		printf("���ѿ�");
		return;
	}
	MaxItem = H->Elements[1];
	temp = H->Elements[H->Size--];//�ȸ�ֵ���Լ�
	//ɾ��һ��Ԫ�غ�size��һ
	
	//�ж������Ǵ������ӽ�㣨<=��
	for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {
		Child = 2 * Parent;
		//�ҳ�����ӽ��
		if (Child != H->Size && H->Elements[Child] < H->Elements[++Child]) {
			Child++;
		}
		if (temp > H->Elements[Child]) break;
		else {
			H->Elements[Parent] = H->Elements[Child];
		}
	}
	//forѭ������ʵtempû�ж���ֻ��parentһֱ�����¹��ˣ�ֱ��temp���룬����һ��Ԫ���ѱ�����
	H->Elements[Parent] = temp;
	return MaxItem;
}