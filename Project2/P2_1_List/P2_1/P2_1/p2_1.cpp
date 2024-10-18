#include<stdio.h>
#include<stdlib.h>/*使用macllo需要*/

#define MAXSIZE 10 /*后面别加分号！*/

/*线性存储序列的实现*/
struct LNode {
	int Date[MAXSIZE];//MAXSIZE代表数组的元素个数
	int Last;//Last代表数组最后一个索引
	List Next;//指向下一个结点
	int Date2;
};
typedef struct LNode* List;

/*空列表初始化*/
List MakeEmpty() {
	List PtrL;
	PtrL = (List)malloc(sizeof(struct LNode));
	/*malloc(size_t size)：分配 size 字节的内存，并返回指向这块内存的指针。*/
	PtrL->Last = -1;//初始化列表为空
	return PtrL;
}

//查找元素x在列表中的位置
int Find(int x, List L) {
	int i = 0;
	while (i <= L->Last && x != L->Date[i])
	{
		i++;
	}
	if (i > L->Last)return -1;
	else return i;
}
//平均查找次数(n +1)/2，平均时间性能为 O(n)
/*注意在C语言中没有List关键字，所以List指代的是我创造的结构体的指针*/
/*但在C++里面，有两个非常接近且常用的容器类型：std::vector 和 std::list*/
/*std::vector 是一种动态数组的实现，它支持随机访问，也就是说你可以通过索引快速地访问到任何位置的元素。std::vector 在内部使用连续的
内存来存储元素。因此它在需要的时候会自动调整大小（通常是成倍增长），以容纳更多的元素。
std::list 实现了一个双向链表，它不支持随机访问，但是支持高效的插入和删除操作。由于链表中的元素不是连续
存储的，所以访问特定元素的时间复杂度较高（线性时间复杂度），但是插入和删除操作非常快（常数时间复杂度）。
*/

//插入,第 i (1≤i≤n+1)个位置上插入一个值为X的新元素
void Insert(int x, int i, List L)
{
	int j;
	if (L->Last == MAXSIZE - 1) {
		printf("表满");
		return;//会跳出整个函数
	}
	if (i<1 || i>L->Last + 2)
	{
		printf("位置不合法");
		return;
	}
	for (j = L->Last; j >= i - 1; j--)
	{
		L->Date[j + 1] = L->Date[j];
	}
	L->Date[i - 1] = x;
	L->Last++;
	return;
}
//平均移动次数为 n /2，检查插入位置的合法性,平均时间性能为 O(n)

//删除
void Delete(int i, List L) {
	int k;
	if (i<1 || i>L->Last + 1) {
		printf("位置不合法");
			return;
	}
	for (k = i - 1; k < L->Last; k++)//有时候要减一有时候又不用，本质是要看你拿这个变量做什么事情，如果要做索引的话就不需要减一了！
	{
		L->Date[k] = L->Date[k + 1];
	}
	L->Last--;
	return;
}

/*线性表的链式存储*/
//用数组存储的时候，相邻的元素不仅逻辑上不仅逻辑上相邻，物理上也是相邻的。而链表通过链连接，建立数据元素的逻辑关系。
//1.求表长
int Lenght(List L)
{
	int j = 0;
	List P = L;//创建一个新的指针与L指向同一个链表的表头，即结构体
	while (P) {
		P = P->Next;//将P的下一个节点的指针赋给P，但不会影响链表的内容
		j++;
	}
	return j;
}

//2.1.按序号查找
List FindKth(int k, List L)
{
	List P = L;
	int i = 1;//链表一开始指向第一个元素
	while (P != NULL && i < k)
	{
		P = P->Next;
		i++;
	}
	if (P == NULL)return NULL;
	if (i == k)return P;
}

//2.2按值查找
List Find1(int x, List L)
{
	List P = L;
	while (P != NULL && P->Date2 != x)
	{
		P = P->Next;
	}
	if (P->Date2 == x)return P;
	else return NULL;
}

//3.插入
List Insert2(int x, int i, List L)
{
	List s, p;
	if (i == 1) {
		s = (List)malloc(sizeof(struct LNode));//创建一个节点
		s->Date2 = x;
		s->Next = L;
		return s;//将s作为第一个节点返回
	}
	p = FindKth(i-1,L);//将p指向第i-1个结点
	if (p == NULL) {
		printf("参数i错");
		return NULL;
	}
	else {
		s = (List)malloc(sizeof(struct LNode));
		s->Date2 = x;
		s->Next = p->Next;//赋值语句从右往左看的，即将p的下个节点赋值给s指向的节点的Next
		p->Next = s;//将s赋值给p指向的节点的Next
		return L;
	}

}

//4.删除第i个位置上的节点
List Delete2(int i, List L)
{
	List s,p;
	if (i == 1)
	{
		s = L;
		p = L;
		if (p == NULL)return NULL;
		else {
			p = p->Next;//这个操作其实只是将指针指向的表头往后移了一位，p就代表表头！！
		}
		free(s);//释放指针s指向的旧表头的空间
		//指针s依旧存在不过变成悬空指针
	}
	p = FindKth(i-1, L);
	if (p == NULL)
	{
		printf("第%d个节点不存在", i - 1);
		return NULL;
	}
	else if (p->Next == NULL) {
		printf("第%d个节点不存在", i);
	}
	else {
		s = p->Next;
		p->Next = s->Next;//删除节点
		free(s);
		return L;
	}
}
/*矩阵可以用二维数组表示，但二维数组表示有两个缺陷：

一是数组的大小需要事先确定
对于“稀疏矩阵 ”，将造成大量的存储空间浪费。
采用一种典型的多重链表——十字链表来存储稀疏矩阵
只存储矩阵非0元素项 结点的数据域:行坐标Row、列坐标Col、数值Value
每个结点通过两个指针域，把同行、同列串起来
行指针(或称为向右指针)Right
列指针(或称为向下指针)Down
Term 代表非0项
特殊Term A 代表4行5列，7个非零项*/