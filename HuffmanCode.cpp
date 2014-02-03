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
	// 函数void select()调用
	int j;
	int flag;
	unsigned int k = UINT_MAX;  // 取k为不小于可能的值
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
	// s1为最小的两个值中序号小的那个
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
		w存放n个字符的权值(均>0)，构造哈夫曼树HT，
		并求出n个字符的哈弗曼编码HC
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
		// 数据不符合要求
		return;
	}
	
	m = 2*n-1;
	// 0号单元未用
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

	for (i=n+1; i<=m; ++i)  // 建哈夫曼树
	{
		/*
			在HT[1~i-1]中选择parent为0且wieght最小
			的两个结点，其序号分别为s1和s2
		 */
		select(HT, i-1, s1, s2);
		HT[s2].parent = i;
		HT[s1].parent = HT[s2].parent;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}

	// 分配n个字符编码的头指针向量([0]不用)
	HC = (HuffmanCode)malloc((n+1) * sizeof(char*));
	// 分配求编码的工作空间
	cd = (char*)malloc(n * sizeof(char));
	c = m;
	cdlen = 0;
	for (i=1; i<=m; ++i)
	{
		HT[i].weight = 0;  // 遍历哈夫曼树时用作结点状态标志
	}
	while (c)
	{
		if (HT[c].weight == 0)
		{
			// 向左
			HT[c].weight = 1;
			if (HT[c].lchild != 0)
			{
				c = HT[c].lchild;
				cd[cdlen++] = '0';
			}
			else if (HT[c].rchild == 0)
			{
				// 登记叶子结点的字符的编码
				HC[c] = (char*)malloc((cdlen+1) * sizeof(char));
				cd[cdlen] = '\0';
				strcpy(HC[c], cd);  // 复制编码（串）
			}
		}
		else if (HT[c].weight == 1)
		{
			// 向右
			if (HT[c].rchild != 0)
			{
				c = HT[c].rchild;
				cd[cdlen+1] = '1';
			}
		}
		else
		{
			// HT[c].wight == 2, 退回
			HT[c].weight = 0;
			c = HT[c].parent;
			--cdlen;  // 退到父节点，编码长度减1
		}
	}
	free(cd);  // 申请的内存空间必须要释放
}

void main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int *w;
	int n;
	int i;

	printf("请输入权值的个数（>1）：");
	scanf_s("%d", &n);

	w = (int*)malloc(n * sizeof(int));
	printf("请依次输入%d个权值（整型）：\n", n);
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
