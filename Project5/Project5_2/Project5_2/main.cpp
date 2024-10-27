//��Ȩ·�����ȣ�WPL����ÿ��Ҷ�ӽ���ȨֵΪw,�Ӹ���㵽Ҷ�ӽ��ĳ���Ϊl,��WPL=wl(1��n���)
//���Ŷ�����/����������WPL��С�Ķ�����
//�ص㣺û�ж�Ϊ1�Ľ�㣻N��Ҷ�ӽ��Ĺ�����������2N-1�����
//���������������Ҷ�������������������Ծ��ǹ�������
//ͬһ��Ȩֵ�����ڲ�ͬ�������Ź�����������WPLֵһ��

typedef struct TreeNode* HuffmanTree;
typedef struct HeapNode* MinHeap;
struct TreeNode {
	int Weight;
	HuffmanTree Left, Right;
};

struct HeapNode {
	int* Elements;
	int Size;
	int Capacity;
};//��С�ѵĽṹ����û��ָ�룡�������飡��

HuffmanTree Huffman(MinHeap H) {
	int i; HuffmanTree T;
	BuildMinHeap(H);

	//��Ҫ�ϲ�Size-1��
	for (i = 1; i < H->Size; i++) {
		T = malloc(sizeof(struct TreeNode));
		T->Left = DeleteMin(H);
		T->Right = DeleteMin(H);
		T->Weight = T->Left->Weight + T->Right->Weight;
		Insert(H, T);
	}
	//����T��һ������������H��һ����С�ѣ�������������
	//DeleteMin����һ��ָ�������������С�ѵ������0��ɾ�����Ԫ��
	//��T������Ľṹû�б��ƻ����������ӽ�㻹������
	T = DeleteMin(H);

	return T;
}
//����С�ѱ�ֱ��ʹ������������죨Ӧ����Ҫ�������������棩

//�������������ڹ���������