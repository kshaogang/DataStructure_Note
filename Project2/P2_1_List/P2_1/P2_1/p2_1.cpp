#include<stdio.h>
#include<stdlib.h>/*ʹ��macllo��Ҫ*/

#define MAXSIZE 10 /*�����ӷֺţ�*/

/*���Դ洢���е�ʵ��*/
struct LNode {
	int Date[MAXSIZE];//MAXSIZE���������Ԫ�ظ���
	int Last;//Last�����������һ������
	List Next;//ָ����һ�����
	int Date2;
};
typedef struct LNode* List;

/*���б��ʼ��*/
List MakeEmpty() {
	List PtrL;
	PtrL = (List)malloc(sizeof(struct LNode));
	/*malloc(size_t size)������ size �ֽڵ��ڴ棬������ָ������ڴ��ָ�롣*/
	PtrL->Last = -1;//��ʼ���б�Ϊ��
	return PtrL;
}

//����Ԫ��x���б��е�λ��
int Find(int x, List L) {
	int i = 0;
	while (i <= L->Last && x != L->Date[i])
	{
		i++;
	}
	if (i > L->Last)return -1;
	else return i;
}
//ƽ�����Ҵ���(n +1)/2��ƽ��ʱ������Ϊ O(n)
/*ע����C������û��List�ؼ��֣�����Listָ�������Ҵ���Ľṹ���ָ��*/
/*����C++���棬�������ǳ��ӽ��ҳ��õ��������ͣ�std::vector �� std::list*/
/*std::vector ��һ�ֶ�̬�����ʵ�֣���֧��������ʣ�Ҳ����˵�����ͨ���������ٵط��ʵ��κ�λ�õ�Ԫ�ء�std::vector ���ڲ�ʹ��������
�ڴ����洢Ԫ�ء����������Ҫ��ʱ����Զ�������С��ͨ���ǳɱ��������������ɸ����Ԫ�ء�
std::list ʵ����һ��˫����������֧��������ʣ�����֧�ָ�Ч�Ĳ����ɾ�����������������е�Ԫ�ز�������
�洢�ģ����Է����ض�Ԫ�ص�ʱ�临�ӶȽϸߣ�����ʱ�临�Ӷȣ������ǲ����ɾ�������ǳ��죨����ʱ�临�Ӷȣ���
*/

//����,�� i (1��i��n+1)��λ���ϲ���һ��ֵΪX����Ԫ��
void Insert(int x, int i, List L)
{
	int j;
	if (L->Last == MAXSIZE - 1) {
		printf("����");
		return;//��������������
	}
	if (i<1 || i>L->Last + 2)
	{
		printf("λ�ò��Ϸ�");
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
//ƽ���ƶ�����Ϊ n /2��������λ�õĺϷ���,ƽ��ʱ������Ϊ O(n)

//ɾ��
void Delete(int i, List L) {
	int k;
	if (i<1 || i>L->Last + 1) {
		printf("λ�ò��Ϸ�");
			return;
	}
	for (k = i - 1; k < L->Last; k++)//��ʱ��Ҫ��һ��ʱ���ֲ��ã�������Ҫ���������������ʲô���飬���Ҫ�������Ļ��Ͳ���Ҫ��һ�ˣ�
	{
		L->Date[k] = L->Date[k + 1];
	}
	L->Last--;
	return;
}

/*���Ա����ʽ�洢*/
//������洢��ʱ�����ڵ�Ԫ�ز����߼��ϲ����߼������ڣ�������Ҳ�����ڵġ�������ͨ�������ӣ���������Ԫ�ص��߼���ϵ��
//1.���
int Lenght(List L)
{
	int j = 0;
	List P = L;//����һ���µ�ָ����Lָ��ͬһ������ı�ͷ�����ṹ��
	while (P) {
		P = P->Next;//��P����һ���ڵ��ָ�븳��P��������Ӱ�����������
		j++;
	}
	return j;
}

//2.1.����Ų���
List FindKth(int k, List L)
{
	List P = L;
	int i = 1;//����һ��ʼָ���һ��Ԫ��
	while (P != NULL && i < k)
	{
		P = P->Next;
		i++;
	}
	if (P == NULL)return NULL;
	if (i == k)return P;
}

//2.2��ֵ����
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

//3.����
List Insert2(int x, int i, List L)
{
	List s, p;
	if (i == 1) {
		s = (List)malloc(sizeof(struct LNode));//����һ���ڵ�
		s->Date2 = x;
		s->Next = L;
		return s;//��s��Ϊ��һ���ڵ㷵��
	}
	p = FindKth(i-1,L);//��pָ���i-1�����
	if (p == NULL) {
		printf("����i��");
		return NULL;
	}
	else {
		s = (List)malloc(sizeof(struct LNode));
		s->Date2 = x;
		s->Next = p->Next;//��ֵ���������󿴵ģ�����p���¸��ڵ㸳ֵ��sָ��Ľڵ��Next
		p->Next = s;//��s��ֵ��pָ��Ľڵ��Next
		return L;
	}

}

//4.ɾ����i��λ���ϵĽڵ�
List Delete2(int i, List L)
{
	List s,p;
	if (i == 1)
	{
		s = L;
		p = L;
		if (p == NULL)return NULL;
		else {
			p = p->Next;//���������ʵֻ�ǽ�ָ��ָ��ı�ͷ��������һλ��p�ʹ����ͷ����
		}
		free(s);//�ͷ�ָ��sָ��ľɱ�ͷ�Ŀռ�
		//ָ��s���ɴ��ڲ����������ָ��
	}
	p = FindKth(i-1, L);
	if (p == NULL)
	{
		printf("��%d���ڵ㲻����", i - 1);
		return NULL;
	}
	else if (p->Next == NULL) {
		printf("��%d���ڵ㲻����", i);
	}
	else {
		s = p->Next;
		p->Next = s->Next;//ɾ���ڵ�
		free(s);
		return L;
	}
}
/*��������ö�ά�����ʾ������ά�����ʾ������ȱ�ݣ�

һ������Ĵ�С��Ҫ����ȷ��
���ڡ�ϡ����� ��������ɴ����Ĵ洢�ռ��˷ѡ�
����һ�ֵ��͵Ķ���������ʮ���������洢ϡ�����
ֻ�洢�����0Ԫ���� ����������:������Row��������Col����ֵValue
ÿ�����ͨ������ָ���򣬰�ͬ�С�ͬ�д�����
��ָ��(���Ϊ����ָ��)Right
��ָ��(���Ϊ����ָ��)Down
Term �����0��
����Term A ����4��5�У�7��������*/