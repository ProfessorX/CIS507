/*
* Copyright TES@NPU
* All rights reserved.
*
* FileName: KMP_Mod.cpp
* 
* Version: 1.0
* Updated @ Nov. 5 2011
* Finished @ Nov. 5 2011
 */

#include "KMP_Mod.h"

/*
	2011-11-05 B511 17:45
	根据教材上给出的参考算法,修订KMP的实现。
	2011-11-05 B511 18:00
	工程师要务必严肃地对待自己的产品!否则苦果自己吃。
	2011-11-05 B511 18:08
	这是一段很不错很值得学习的codes,
	吃完饭来继续研究它。未完待续!
 */


/*
	基本操作的实现
 */

Status StrAssign(SString T, char *chars)
{
	// 生成一个其值等于chars的串T
	int i;
	if (strlen(chars) > MAXSTRLEN)
	{
		return ERROR;
	}
	else
	{
		T[0] = strlen(chars);
		for (i=1; i<=T[0]; i++)  // C中数组的下标从0开始,但0已被用来存长度
		{
			T[i] = *(chars+i-1);
		}
		return OK;
	}
}

/*
Status StrCopy(SString T, SString S)  // 看起来简单,写起来机关重重的函数
{
	// 由串S复制得串T
	// 其实现在这么实现的函数并不严谨,BUGs很多
	int i;
	for (i=0; i<=S[0]; i++)
	{
		T[i] = S[i];
	}
	return OK;
}

Status StrEmpty(SString S)
{
	// 若S为空串,则返回TRUE
	// 否则返回FALSE
	if (S[0] == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int StrCompare(SString S, SString T)
{
	// 初始条件: 串S和串T存在。
	// 操作结果: 若S＞T,则返回值＞0;若S=T,则返回值=0
	// 若S＜T,则返回值＜0
	// 这一个是对大小写敏感的,库中有一个对大小写不敏感的
	int i;
	for (i=1; i<=S[0]&&i<=T[0]; ++i)  // 此处用++i
	{
		if (S[i] != T[i])
		{
			return (S[i] - T[i]);  // Lib中的函数也是这么判定的
		}
	}// end of for
	return (S[0] - T[0]);
}
 */

int StrLength(SString S)
{
	// 返回串的元素个数
	return S[0];
}

/*
Status ClearString(SString S)
{
	// 初始条件: 串S存在。
	// 操作结果: 将S清为空串
	S[0] = 0;  // 令串长为0,也仅此而已
	return OK;  // 因为为定长串,所以无法销毁?为什么~
}

Status Contact(SString T, SString S1, SString S2)
{
	// 用T返回S1和S2联接而成的新串。
	// 若未截断,则返回TRUE,否则返回FALSE
	int i;
	if (S1[0]+S2[0] <= MAXSTRLEN)
	{
		// 联接未截断
		for (i=1; i<=S1[0]; i++)
		{
			T[i] = S1[i];
		}
		for (i=1; i<=S2[0]; i++)
		{
			T[S1[0]+i] = S2[i];  // 这一句写的比较精妙,还有其他的写法
		}
		T[0] = S1[0] + S2[0];
		return TRUE;
	}// end of if
	else
	{
		// 截断S2
		for (i=1; i<=S1[0]; i++)
		{
			T[i] = S1[i];
		}
		for (i=1; i<=MAXSTRLEN-S1[0]; i++)
		{
			T[S1[0]+i] = S2[i];
		}
		T[0] = MAXSTRLEN;
		return FALSE;
	}// end of else
}

Status SubString(SString Sub, SString S, int pos, int len)
{
	// 用Sub返回串S的第pos个字符起
	// 长度为len的子串。 Algo 4.3
	int i;
	if (pos<1 || pos>S[0] || len<0 || len>S[0]-pos+1)
	{
		return ERROR;
		// 要方便可以在之前再加一句printf
	}
	for (i=1; i<=len; i++)
	{
		Sub[i] = S[pos+i-1];
	}
	Sub[0] = len;  // 对算法要有足够的理解,这样才能在实践时写出好东东来.
	return OK;
}

int Index(SString S, SString T, int pos)
{
	// 返回子串T在主串S中第pos个字符后的位置。
	// 若不存在,则函数值为0。其中,T非空,1≤pos≤StrLength(S)。
	// Algo 4.5----KMP的算法,更加值得研究。稍安勿躁。
	// Algo 4.5有其不成熟的地方,但对初学者来说已经足够参考了。
	int i;
	int j;
	if (1<=pos && pos<=S[0])
	{
		i = pos;
		j = 1;
		while (i<=S[0] && j<=T[0])
		{
			if (S[i] == T[j])  // 继续比较后继字符
			{
				++i;
				++j;
			}
			else
			{
				i = i-j+2;  // 这样一个移动的位置十分精髓!
				j = 1;
			}// end of if
		}// end of while
		if (j > T[0])
		{
			return (i - T[0]);
		}
		else
		{
			return 0;  // 跳出
		}// end of if
	}
	else
	{
		return 0;
	}// end of if...else...
}

Status StrInsert(SString S, int pos, SString T)
{
	// 初始条件: 串S和T存在, 1≤pos≤StrLength(S)+1
	// 操作结果: 在串S的第pos个字符之前插入串T。
	// 完全插入返回TRUE,部分插入返回FALSE。
	int i;
	if (pos<1 || pos>S[0]+1)
	{
		return ERROR;
	}
	if (S[0]+T[0] <= MAXSTRLEN)
	{
		// 完全插入
		// 这样一种插入方式很神奇,尤其用动画模拟时。
		for (i=S[0]; i>=pos; i--)
		{
			S[i+T[0]] = S[i];  // 先移动
		}
		for (i=pos; i<pos+T[0]; i++)
		{
			S[i] = T[i-pos+1];  // 再做赋值
		}
		S[0] = S[0] + T[0];
		return TRUE;
	}// end of if
	else
	{
		// 部分插入
		for (i=MAXSTRLEN; i<=pos; i--)
		{
			S[i] = S[i-T[0]];
		}
		for (i=pos; i<pos+T[0]; i++)
		{
			S[0] = T[i-pos+1];
		}
		S[0] = MAXSTRLEN;
		return FALSE;
	}
}

Status StrDelete(SString S, int pos, int len)
{
	// 初始条件: 串S存在, 1≤pos≤StrLength(S)-len+1
	// 操作结果: 从串中删除第pos个字符起长度为len的子串
	int i;
	if (pos<1 || pos>S[0]-len+1)  // 删除位置不合理
	{
		return ERROR;
	}
	for (i=pos+len; i<=S[0]; i++)
	{
		S[i-len] = S[i];
	}
	S[0] = (S[0] - len);
	return OK;
}

Status Replace(SString S, SString T, SString V)
{
	// 初始条件: 串S、T和V存在。T是非空串(此函数与串的存储结构无关)
	// 操作结果: 用V替换主串S中出现的所有与T相等的不重叠的子串
	int i = 1;  // 从串S的第一个字符起查找串T
	if (StrEmpty(T) == TRUE)  // T是空串
	{
		return ERROR;
	}
	do
	{
		i = Index(S, T, i);  // 结果i为从上一个i之后找到的子串T的位置
		if (i != 0)  // 串S中存在串T
		{
			StrDelete(S, i, StrLength(T));  // 删除该串T
			StrInsert(S, i, V);  // 在原串T的位置插入串V
			i = (i + StrLength(V));  // 在插入的串后面继续查找串T
		}
	}while(i != 0);  // end of do...while
	return OK;
}

void DestroyString()
{
	// 由于SString是定长类型,故无法销毁。
	// 不过想试试把数组的首地址置为空,看是什么样子。
}
 */

void StrPrint(SString T)
{
	// 输出字符串T
	// 不知道模板类中是不是这样写的
	int i;
	for (i=1; i<=T[0]; i++)
	{
		printf("%c", T[i]);
	}  // 貌似是纯C实现的唯一一种解决方案?
	printf("\n");
}

void get_nextval(SString T, int nextval[])
{
	// 求模式串T的next函数修正值并存入数组nextval。
	// Algo 4.8
	int i = 1;  // 在定义的时候就要初始化!
	int j = 0;
	nextval[1] = 0;
	while (i < T[0])
	{
		if (j==0 || T[i]==T[j])
		{
			++i;
			++j;
			if (T[i] != T[j])
			{
				nextval[i] = j;  // move back
			}
			else
			{
				nextval[i] = nextval[j];
			}// end of if...else
		}
		else
		{
			j = nextval[j];
		}// end of if...else
	}// end of while
}

int Index_KMP(SString S, SString T, int pos, int next[])  
	// 相比,用next[]换掉了len
{
	// 利用模式串T的next函数求T在主串S中第pos个字符之后的
	// 位置的KMP算法。其中T非空,1≤pos≤StrLength(S)。 
	// Algo 4.6
	int i = pos;
	int j = 1;
	while (i<=S[0] && j<=T[0])
	{
		if (j==0 || S[i]==T[j])  // 继续比较后继字符
		{
			++i;
			++j;
		}
		else  // 模式串向右移动
		{
			j = next[j];
		}// end of if...else
	}// end of while
	if (j > T[0])  // 匹配成功
	{
		return (i - T[0]);  // 返回成功匹配的位置
	}
	else
	{
		return 0;
	}
}

void main()
{
	int i;
	int j;
	int *p;  // 仍旧用来操作数组
	SString s1;
	SString s2;
	timeb t1;  // 用于分析运行时间
	timeb t2;  // 的简单变量
	long t;
	
	// 教科书上的测试codes:
	/*
	StrAssign(s1, "aaabaaaab");
	printf("主串为: ");
	StrPrint(s1);
	StrAssign(s2, "aaaab");
	printf("子串为: ");
	StrPrint(s2);
	 */
	 
	/*
	StrAssign(s1, "abcdefghijklmnopqrstuvwxyz");
	printf("主串为: ");
	StrPrint(s1);
	StrAssign(s2, "z");
	printf("子串为: ");
	StrPrint(s2);
	 */

	
	StrAssign(s1, "Hello, World! My name is TES.");
	printf("主串为: ");
	StrPrint(s1);
	StrAssign(s2, "TES");
	printf("子串为: ");
	StrPrint(s2);
	

	i = StrLength(s2);
	p = (int*)malloc((i+1) * sizeof(int));  // 因为第一个位置标识了长度
	get_nextval(s2, p);
	printf("子串nextval的函数为: ");
	for (j=1; j<=i; j++)
	{
		printf("%d ", *(p+j));
	}
	printf("\n");

	ftime(&t1);  // 求得当前时间
	i = Index_KMP(s1, s2, 1, p);
	if (i != 0)
	{
		printf("主串和子串在%d个字符处首次匹配\n", i);
	}
	else
	{

		printf("主串和子串匹配不成功!\n");
	}// end of if...else
	ftime(&t2);  // 求得当前时间
	t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);  // 计算时间差
        // t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);  // 计算时间差
        // t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm)
        t = (t2.time - t1.)
        
            
        
	printf("用时%ld毫秒\n", t);

	system("pause");
        system();
        
            
}

