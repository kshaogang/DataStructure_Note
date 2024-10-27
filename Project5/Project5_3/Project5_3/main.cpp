//集合
#define MaxSize 10

typedef struct {
	int Data;
	int Parent;
}SetType;

//在数组S中查找值为x的元素所属的集合
int Find(SetType S[], int x) {
	int i;
	for (i = 0; S[i].Data != x && i < MaxSize; i++);
	if (i >= MaxSize) return - 1;
	for (; S[i].Parent >= 0; i = S[i].Parent);
	return i;
}
//注意S[]定义了一个结构体数组的指针，数组的每个元素都是一个结构体
//其语法为S[i].xxx 

void Union(SetType S[], int x1, int x2) {
	int Root1, Root2;
	Root1 = Find(S, x1);
	Root2 = Find(S, x2);
	if (Root1 != Root2)  S[Root1].Parent = Root2;
}