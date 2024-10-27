//带权路径长度（WPL）：每个叶子结点的权值为w,从根结点到叶子结点的长度为l,则WPL=wl(1到n求和)
//最优二叉树/哈夫曼树：WPL最小的二叉树
//特点：没有度为1的结点；N个叶子结点的哈夫曼树共有2N-1个结点
//哈夫曼树的任意非叶结点的左右子树交换后仍旧是哈夫曼树
//同一组权值，存在不同构的两颗哈夫曼树，但WPL值一样

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
};//最小堆的结构体里没有指针！！是数组！！

HuffmanTree Huffman(MinHeap H) {
	int i; HuffmanTree T;
	BuildMinHeap(H);

	//需要合并Size-1次
	for (i = 1; i < H->Size; i++) {
		T = malloc(sizeof(struct TreeNode));
		T->Left = DeleteMin(H);
		T->Right = DeleteMin(H);
		T->Weight = T->Left->Weight + T->Right->Weight;
		Insert(H, T);
	}
	//这里T是一个哈夫曼树，H是一个最小堆，两个互不干涉
	//DeleteMin返回一个指针变量即返回最小堆的数组的0并删除这个元素
	//但T这棵树的结构没有被破坏，其左右子结点还是连着
	T = DeleteMin(H);

	return T;
}
//用最小堆比直接使用数组排序更快（应该主要体现在排序上面）

//哈夫曼树可用于哈夫曼编码