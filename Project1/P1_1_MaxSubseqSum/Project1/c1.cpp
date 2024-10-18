#include<stdio.h>
#include<time.h>

#define MAXN 10//定义后面不加；

clock_t start, stop;//clock返回的变量类型是clt
//CLK_TCK 为常数，机器始终每秒所走的打点数

//利用递归实现打印从0到N；
void PrintN(int N)
{
	if (N)
	{
		PrintN(N - 1);
		printf("%d\n", N);
	}
	return;
}

//算法复杂度？

//算法效率：实现多项式 f(x) = a0 + a1*x^1 +... +an * x^n
double f1(int n, double a[],double x) 
{
	int i;
	double p = a[n];
	for(i = n; i > 0; i--) {
		p = a[i - 1] + x * p;
	}
	return p;
}

//打印数组
void PrintA(double a[],int n) {
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%f\n", a[i]);
	}
}

//求解数组最大连续子列和问题
//1.循环求解,T(N) = O(N^2)
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
//错误修正：ThisSum需要归零

//2.分而治之，T(N) = O(NlogN)
double Max3(int A, int B, int C)
{ /* 返回3个整数中的最大值 */
    return A > B ? A > C ? A : C : B > C ? B : C;
}
double DivideAndConquer(double List[], int left, int right)
{ 
    int MaxLeftSum, MaxRightSum; 
    int MaxLeftBorderSum, MaxRightBorderSum; 

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if (left == right)
    { /* 递归的终止条件，子列只有1个数字 */
        if (List[left] > 0)
        {
            return List[left];
        }
        else return 0;
    }

    /* 下面是"分"的过程 */
    center = (left + right) / 2; /* 找到中分点 */
    /* 递归求得两边子列的最大和 */
    MaxLeftSum = DivideAndConquer(List, left, center);
    MaxRightSum = DivideAndConquer(List, center + 1, right);
    //利用递归！！！NB!!!

    /* 下面求跨分界线的最大子列和 */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for (i = center; i >= left; i--)
    { /* 从中线向左扫描 */
        LeftBorderSum += List[i];
        if (LeftBorderSum > MaxLeftBorderSum)
        {
            MaxLeftBorderSum = LeftBorderSum;
        }
    } 
    MaxRightBorderSum = 0; RightBorderSum = 0;
    for (i = center + 1; i <= right; i++)
    { /* 从中线向右扫描 */
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum)
        {
            MaxRightBorderSum = RightBorderSum;

        }
    } 
    //因为是求的跨越中线所以只需要从中线到边缘扫描一遍即可，不从中线开始扫描的是上面的左右扫描的工作
    /* 下面返回"治"的结果 */
    double Max = Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
    // printf("Max=%d\n", Max);
    return Max;
}
double MaxSubseqSum2(int N,double List[])
{ /* 保持与前2种算法相同的函数接口 */
    return DivideAndConquer(List, 0, N - 1);
}

//在线处理：每一个数据进行即时处理，在任何一个地方输入种植，都给出当前的解
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
            ThisSum = 0;//若前面相加的和小于0，则说明其不可能为最大连续子数列的子数列
    }
    return MaxSum;
}


void main()
{
	int a = 10;
	PrintN(a);
	
	double b[MAXN];
	int i;
	for (i = 0; i < MAXN; i++)b[i] = (double)i;//假定每一项系数就是i

	double result = f1(MAXN-1, b, 1);//输入参数数组时只打名字即可
	PrintA(b,MAXN);
	printf("%f\n", result);
    double r1 = MaxSubseqSum1(MAXN - 1,b);
    double r2 = MaxSubseqSum2(MAXN - 1, b);
    double r3 = MaxSubseqSum3(MAXN - 1, b);
    printf("%f\n", r1);
    printf("%f\n", r2);
    printf("%f\n", r3);

}
//错误：输出结果为负数。原因：调用f1时的p=b[MAXN]中的MAXN为10而数组最大索引为9，导致数组越界。