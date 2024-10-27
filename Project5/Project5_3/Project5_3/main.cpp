//����
#define MaxSize 10

typedef struct {
	int Data;
	int Parent;
}SetType;

//������S�в���ֵΪx��Ԫ�������ļ���
int Find(SetType S[], int x) {
	int i;
	for (i = 0; S[i].Data != x && i < MaxSize; i++);
	if (i >= MaxSize) return - 1;
	for (; S[i].Parent >= 0; i = S[i].Parent);
	return i;
}
//ע��S[]������һ���ṹ�������ָ�룬�����ÿ��Ԫ�ض���һ���ṹ��
//���﷨ΪS[i].xxx 

void Union(SetType S[], int x1, int x2) {
	int Root1, Root2;
	Root1 = Find(S, x1);
	Root2 = Find(S, x2);
	if (Root1 != Root2)  S[Root1].Parent = Root2;
}