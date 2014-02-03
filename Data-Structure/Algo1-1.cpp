/* 
* Copyright TES@NPU 
* School of Automation InfoSec
* All rights reserved.
*
* FileName: Algo1-1.cpp
* 
* Version: 1.0
* Finished @ Sep. 26st 2011
* Update @ Sep. 27st 2011
 */

// Algo1-1.cpp ����1-1/x+1/x*x...
#include <stdio.h>
#include <sys/timeb.h>

void main()
{
	timeb t1;
	timeb t2;
	long t;
	double x;
	double sum;
	double sum1;
	sum1 = 1;
	int i;
	int j;
	int n;

	printf("������x n: ");
	scanf("%lf %d", &x, &n);

	ftime(&t1);  // ��õ�ǰʱ��

	for (i=1; i<=n; i++)
	{
		sum = 1;
		for (j=1; j<=i; j++)
			sum1 = sum * (-1.0 / x);
		sum += sum1;
	}

	ftime(&t2);  // ��õ�ǰʱ��
	t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);  // ����ʱ���
	
	printf(" sum = %lf ��ʱ%ld����\n", sum, t);
}

/*
Output in VC++2008:
----------
������x n: 123 10000
 sum = 0.991870 ��ʱ2554����
 ----------
 */

