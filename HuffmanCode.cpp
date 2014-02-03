/*
* Copyright TES@NPU
* All rights reserved.
*
* FileName: HuffmanCode.cpp
* 
* Version: 1.0
* Updated @ Dec. 30 2011
* Finished @ Dec. 30 2011
 */

/*
	Without a lady, you can do nothing
	but learning. Professor. X @  west 
	Teaching Building C, Room 503. Right
	here fighting...
	So, my lord, why not bestow me a lady... 
 */


#include "HuffmanCode.h"

/*
	2011-12-30 C503 17:32
	Last few days of the year.
	Right here working. Without a lady...
 */

int min(HuffmanTree t, int i)
{
	// ����void select()����
	int j;
	int flag;
	unsigned int k = UINT_MAX;  // ȡkΪ��С�ڿ��ܵ�ֵ
	for (j=1; j<=i; j++)
	{
		if (t[j].weight<k && t[j].parent==0)
		{
			k = t[j].weight;
			flag = j;
		}// end of if
	}// end of for
	t[flag].parent = 1;
	return flag;
        
}

void select(HuffmanTree t, int i, int &s1, int &s2)
{
	// s1Ϊ��С������ֵ�����С���Ǹ�
	int j;
	s1 = min(t, i);
	s2 = min(t, i);
	if (s1 > s2)
	{
		j = s1;
		s1 = s2;
		s2 = j;
	}
}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC,
	int *w, int n)
{
	/*
		w���n���ַ���Ȩֵ(��>0)�������������HT��
		�����n���ַ��Ĺ���������HC
	*/
	int m;
	int i;
	int s1;
	int s2;
	unsigned c;
	unsigned cdlen;
	HuffmanTree p;
	char *cd;

	if (n <= 1)
	{
		// ���ݲ�����Ҫ��
		return;
	}
	
	m = 2*n-1;
	// 0�ŵ�Ԫδ��
	HT = (HuffmanTree)malloc((m+1) * sizeof(HTNode));
	
	for (p = HT+1,i=1; i<=n; ++i,++p,++w)
	{
		(*p).weight = *w;
		(*p).parent = 0;
		(*p).lchild = 0;
		(*p).rchild = 0;
	}
	
	for (; i<=m; ++i,++p)
	{
		(*p).parent = 0;
	}

	for (i=n+1; i<=m; ++i)  // ����������
	{
		/*
			��HT[1~i-1]��ѡ��parentΪ0��wieght��С
			��������㣬����ŷֱ�Ϊs1��s2
		 */
		select(HT, i-1, s1, s2);
		HT[s2].parent = i;
		HT[s1].parent = HT[s2].parent;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}

	// ����n���ַ������ͷָ������([0]����)
	HC = (HuffmanCode)malloc((n+1) * sizeof(char*));
	// ���������Ĺ����ռ�
	cd = (char*)malloc(n * sizeof(char));
	c = m;
	cdlen = 0;
	for (i=1; i<=m; ++i)
	{
		HT[i].weight = 0;  // ������������ʱ�������״̬��־
	}
	while (c)
	{
		if (HT[c].weight == 0)
		{
			// ����
			HT[c].weight = 1;
			if (HT[c].lchild != 0)
			{
				c = HT[c].lchild;
				cd[cdlen++] = '0';
			}
			else if (HT[c].rchild == 0)
			{
				// �Ǽ�Ҷ�ӽ����ַ��ı���
				HC[c] = (char*)malloc((cdlen+1) * sizeof(char));
				cd[cdlen] = '\0';
				strcpy(HC[c], cd);  // ���Ʊ��루����
			}
		}
		else if (HT[c].weight == 1)
		{
			// ����
			if (HT[c].rchild != 0)
			{
				c = HT[c].rchild;
				cd[cdlen+1] = '1';
			}
		}
		else
		{
			// HT[c].wight == 2, �˻�
			HT[c].weight = 0;
			c = HT[c].parent;
			--cdlen;  // �˵����ڵ㣬���볤�ȼ�1
		}
	}
	free(cd);  // ������ڴ�ռ����Ҫ�ͷ�
}

void main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int *w;
	int n;
	int i;

	printf("������Ȩֵ�ĸ�����>1����");
	scanf_s("%d", &n);

	w = (int*)malloc(n * sizeof(int));
	printf("����������%d��Ȩֵ�����ͣ���\n", n);
	for (i=0; i<=n-1; i++)
	{
		scanf_s("%d", w+i);
	}
	HuffmanCoding(HT, HC, w, n);

	for (i=1; i<=n; i++)
	{
		puts(HC[i]);
	}

	system("pause");
}
