#include<stdio.h>
#include<time.h>

#define MAXN 10//������治�ӣ�

clock_t start, stop;//clock���صı���������clt
//CLK_TCK Ϊ����������ʼ��ÿ�����ߵĴ����

//���õݹ�ʵ�ִ�ӡ��0��N��
void PrintN(int N)
{
	if (N)
	{
		PrintN(N - 1);
		printf("%d\n", N);
	}
	return;
}

//�㷨���Ӷȣ�

//�㷨Ч�ʣ�ʵ�ֶ���ʽ f(x) = a0 + a1*x^1 +... +an * x^n
double f1(int n, double a[],double x) 
{
	int i;
	double p = a[n];
	for(i = n; i > 0; i--) {
		p = a[i - 1] + x * p;
	}
	return p;
}

//��ӡ����
void PrintA(double a[],int n) {
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%f\n", a[i]);
	}
}

//�����������������к�����
//1.ѭ�����,T(N) = O(N^2)
double MaxSubseqSum1(int A,double B[]) {
	double ThisSum, MaxSum;
	ThisSum = 0;
	MaxSum = 0;
	int i,j;
	for (i = 0; i<A; i++) {
		for (j = i; j < A; j++) {
			ThisSum += B[j];
			if (MaxSum < ThisSum) 
				MaxSum = ThisSum;
		}
        ThisSum = 0;
	}
	return MaxSum;
}
//����������ThisSum��Ҫ����

//2.�ֶ���֮��T(N) = O(NlogN)
double Max3(int A, int B, int C)
{ /* ����3�������е����ֵ */
    return A > B ? A > C ? A : C : B > C ? B : C;
}
double DivideAndConquer(double List[], int left, int right)
{ 
    int MaxLeftSum, MaxRightSum; 
    int MaxLeftBorderSum, MaxRightBorderSum; 

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if (left == right)
    { /* �ݹ����ֹ����������ֻ��1������ */
        if (List[left] > 0)
        {
            return List[left];
        }
        else return 0;
    }

    /* ������"��"�Ĺ��� */
    center = (left + right) / 2; /* �ҵ��зֵ� */
    /* �ݹ�����������е����� */
    MaxLeftSum = DivideAndConquer(List, left, center);
    MaxRightSum = DivideAndConquer(List, center + 1, right);
    //���õݹ飡����NB!!!

    /* �������ֽ��ߵ�������к� */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for (i = center; i >= left; i--)
    { /* ����������ɨ�� */
        LeftBorderSum += List[i];
        if (LeftBorderSum > MaxLeftBorderSum)
        {
            MaxLeftBorderSum = LeftBorderSum;
        }
    } 
    MaxRightBorderSum = 0; RightBorderSum = 0;
    for (i = center + 1; i <= right; i++)
    { /* ����������ɨ�� */
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum)
        {
            MaxRightBorderSum = RightBorderSum;

        }
    } 
    //��Ϊ����Ŀ�Խ��������ֻ��Ҫ�����ߵ���Եɨ��һ�鼴�ɣ��������߿�ʼɨ��������������ɨ��Ĺ���
    /* ���淵��"��"�Ľ�� */
    double Max = Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
    // printf("Max=%d\n", Max);
    return Max;
}
double MaxSubseqSum2(int N,double List[])
{ /* ������ǰ2���㷨��ͬ�ĺ����ӿ� */
    return DivideAndConquer(List, 0, N - 1);
}

//���ߴ���ÿһ�����ݽ��м�ʱ�������κ�һ���ط�������ֲ����������ǰ�Ľ�
//T(N) = O(N)
double MaxSubseqSum3(int A,double B[])
{
    double ThisSum = 0;
    double MaxSum = 0;
    int i = 0;
    for (; i < A; i++) {
        ThisSum += B[i];
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if (ThisSum < 0)
            ThisSum = 0;//��ǰ����ӵĺ�С��0����˵���䲻����Ϊ������������е�������
    }
    return MaxSum;
}


void main()
{
	int a = 10;
	PrintN(a);
	
	double b[MAXN];
	int i;
	for (i = 0; i < MAXN; i++)b[i] = (double)i;//�ٶ�ÿһ��ϵ������i

	double result = f1(MAXN-1, b, 1);//�����������ʱֻ�����ּ���
	PrintA(b,MAXN);
	printf("%f\n", result);
    double r1 = MaxSubseqSum1(MAXN - 1,b);
    double r2 = MaxSubseqSum2(MAXN - 1, b);
    double r3 = MaxSubseqSum3(MAXN - 1, b);
    printf("%f\n", r1);
    printf("%f\n", r2);
    printf("%f\n", r3);

}
//����������Ϊ������ԭ�򣺵���f1ʱ��p=b[MAXN]�е�MAXNΪ10�������������Ϊ9����������Խ�硣