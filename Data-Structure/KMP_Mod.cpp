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
	���ݽ̲��ϸ����Ĳο��㷨,�޶�KMP��ʵ�֡�
	2011-11-05 B511 18:00
	����ʦҪ�������ضԴ��Լ��Ĳ�Ʒ!�������Լ��ԡ�
	2011-11-05 B511 18:08
	����һ�κܲ����ֵ��ѧϰ��codes,
	���극�������о�����δ�����!
 */


/*
	����������ʵ��
 */

Status StrAssign(SString T, char *chars)
{
	// ����һ����ֵ����chars�Ĵ�T
	int i;
	if (strlen(chars) > MAXSTRLEN)
	{
		return ERROR;
	}
	else
	{
		T[0] = strlen(chars);
		for (i=1; i<=T[0]; i++)  // C��������±��0��ʼ,��0�ѱ������泤��
		{
			T[i] = *(chars+i-1);
		}
		return OK;
	}
}

/*
Status StrCopy(SString T, SString S)  // ��������,д�����������صĺ���
{
	// �ɴ�S���Ƶô�T
	// ��ʵ������ôʵ�ֵĺ��������Ͻ�,BUGs�ܶ�
	int i;
	for (i=0; i<=S[0]; i++)
	{
		T[i] = S[i];
	}
	return OK;
}

Status StrEmpty(SString S)
{
	// ��SΪ�մ�,�򷵻�TRUE
	// ���򷵻�FALSE
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
	// ��ʼ����: ��S�ʹ�T���ڡ�
	// �������: ��S��T,�򷵻�ֵ��0;��S=T,�򷵻�ֵ=0
	// ��S��T,�򷵻�ֵ��0
	// ��һ���ǶԴ�Сд���е�,������һ���Դ�Сд�����е�
	int i;
	for (i=1; i<=S[0]&&i<=T[0]; ++i)  // �˴���++i
	{
		if (S[i] != T[i])
		{
			return (S[i] - T[i]);  // Lib�еĺ���Ҳ����ô�ж���
		}
	}// end of for
	return (S[0] - T[0]);
}
 */

int StrLength(SString S)
{
	// ���ش���Ԫ�ظ���
	return S[0];
}

/*
Status ClearString(SString S)
{
	// ��ʼ����: ��S���ڡ�
	// �������: ��S��Ϊ�մ�
	S[0] = 0;  // ���Ϊ0,Ҳ���˶���
	return OK;  // ��ΪΪ������,�����޷�����?Ϊʲô~
}

Status Contact(SString T, SString S1, SString S2)
{
	// ��T����S1��S2���Ӷ��ɵ��´���
	// ��δ�ض�,�򷵻�TRUE,���򷵻�FALSE
	int i;
	if (S1[0]+S2[0] <= MAXSTRLEN)
	{
		// ����δ�ض�
		for (i=1; i<=S1[0]; i++)
		{
			T[i] = S1[i];
		}
		for (i=1; i<=S2[0]; i++)
		{
			T[S1[0]+i] = S2[i];  // ��һ��д�ıȽϾ���,����������д��
		}
		T[0] = S1[0] + S2[0];
		return TRUE;
	}// end of if
	else
	{
		// �ض�S2
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
	// ��Sub���ش�S�ĵ�pos���ַ���
	// ����Ϊlen���Ӵ��� Algo 4.3
	int i;
	if (pos<1 || pos>S[0] || len<0 || len>S[0]-pos+1)
	{
		return ERROR;
		// Ҫ���������֮ǰ�ټ�һ��printf
	}
	for (i=1; i<=len; i++)
	{
		Sub[i] = S[pos+i-1];
	}
	Sub[0] = len;  // ���㷨Ҫ���㹻�����,����������ʵ��ʱд���ö�����.
	return OK;
}

int Index(SString S, SString T, int pos)
{
	// �����Ӵ�T������S�е�pos���ַ����λ�á�
	// ��������,����ֵΪ0������,T�ǿ�,1��pos��StrLength(S)��
	// Algo 4.5----KMP���㷨,����ֵ���о����԰����ꡣ
	// Algo 4.5���䲻����ĵط�,���Գ�ѧ����˵�Ѿ��㹻�ο��ˡ�
	int i;
	int j;
	if (1<=pos && pos<=S[0])
	{
		i = pos;
		j = 1;
		while (i<=S[0] && j<=T[0])
		{
			if (S[i] == T[j])  // �����ȽϺ���ַ�
			{
				++i;
				++j;
			}
			else
			{
				i = i-j+2;  // ����һ���ƶ���λ��ʮ�־���!
				j = 1;
			}// end of if
		}// end of while
		if (j > T[0])
		{
			return (i - T[0]);
		}
		else
		{
			return 0;  // ����
		}// end of if
	}
	else
	{
		return 0;
	}// end of if...else...
}

Status StrInsert(SString S, int pos, SString T)
{
	// ��ʼ����: ��S��T����, 1��pos��StrLength(S)+1
	// �������: �ڴ�S�ĵ�pos���ַ�֮ǰ���봮T��
	// ��ȫ���뷵��TRUE,���ֲ��뷵��FALSE��
	int i;
	if (pos<1 || pos>S[0]+1)
	{
		return ERROR;
	}
	if (S[0]+T[0] <= MAXSTRLEN)
	{
		// ��ȫ����
		// ����һ�ֲ��뷽ʽ������,�����ö���ģ��ʱ��
		for (i=S[0]; i>=pos; i--)
		{
			S[i+T[0]] = S[i];  // ���ƶ�
		}
		for (i=pos; i<pos+T[0]; i++)
		{
			S[i] = T[i-pos+1];  // ������ֵ
		}
		S[0] = S[0] + T[0];
		return TRUE;
	}// end of if
	else
	{
		// ���ֲ���
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
	// ��ʼ����: ��S����, 1��pos��StrLength(S)-len+1
	// �������: �Ӵ���ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
	int i;
	if (pos<1 || pos>S[0]-len+1)  // ɾ��λ�ò�����
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
	// ��ʼ����: ��S��T��V���ڡ�T�Ƿǿմ�(�˺����봮�Ĵ洢�ṹ�޹�)
	// �������: ��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�
	int i = 1;  // �Ӵ�S�ĵ�һ���ַ�����Ҵ�T
	if (StrEmpty(T) == TRUE)  // T�ǿմ�
	{
		return ERROR;
	}
	do
	{
		i = Index(S, T, i);  // ���iΪ����һ��i֮���ҵ����Ӵ�T��λ��
		if (i != 0)  // ��S�д��ڴ�T
		{
			StrDelete(S, i, StrLength(T));  // ɾ���ô�T
			StrInsert(S, i, V);  // ��ԭ��T��λ�ò��봮V
			i = (i + StrLength(V));  // �ڲ���Ĵ�����������Ҵ�T
		}
	}while(i != 0);  // end of do...while
	return OK;
}

void DestroyString()
{
	// ����SString�Ƕ�������,���޷����١�
	// ���������԰�������׵�ַ��Ϊ��,����ʲô���ӡ�
}
 */

void StrPrint(SString T)
{
	// ����ַ���T
	// ��֪��ģ�������ǲ�������д��
	int i;
	for (i=1; i<=T[0]; i++)
	{
		printf("%c", T[i]);
	}  // ò���Ǵ�Cʵ�ֵ�Ψһһ�ֽ������?
	printf("\n");
}

void get_nextval(SString T, int nextval[])
{
	// ��ģʽ��T��next��������ֵ����������nextval��
	// Algo 4.8
	int i = 1;  // �ڶ����ʱ���Ҫ��ʼ��!
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
	// ���,��next[]������len
{
	// ����ģʽ��T��next������T������S�е�pos���ַ�֮���
	// λ�õ�KMP�㷨������T�ǿ�,1��pos��StrLength(S)�� 
	// Algo 4.6
	int i = pos;
	int j = 1;
	while (i<=S[0] && j<=T[0])
	{
		if (j==0 || S[i]==T[j])  // �����ȽϺ���ַ�
		{
			++i;
			++j;
		}
		else  // ģʽ�������ƶ�
		{
			j = next[j];
		}// end of if...else
	}// end of while
	if (j > T[0])  // ƥ��ɹ�
	{
		return (i - T[0]);  // ���سɹ�ƥ���λ��
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
	int *p;  // �Ծ�������������
	SString s1;
	SString s2;
	timeb t1;  // ���ڷ�������ʱ��
	timeb t2;  // �ļ򵥱���
	long t;
	
	// �̿����ϵĲ���codes:
	/*
	StrAssign(s1, "aaabaaaab");
	printf("����Ϊ: ");
	StrPrint(s1);
	StrAssign(s2, "aaaab");
	printf("�Ӵ�Ϊ: ");
	StrPrint(s2);
	 */
	 
	/*
	StrAssign(s1, "abcdefghijklmnopqrstuvwxyz");
	printf("����Ϊ: ");
	StrPrint(s1);
	StrAssign(s2, "z");
	printf("�Ӵ�Ϊ: ");
	StrPrint(s2);
	 */

	
	StrAssign(s1, "Hello, World! My name is TES.");
	printf("����Ϊ: ");
	StrPrint(s1);
	StrAssign(s2, "TES");
	printf("�Ӵ�Ϊ: ");
	StrPrint(s2);
	

	i = StrLength(s2);
	p = (int*)malloc((i+1) * sizeof(int));  // ��Ϊ��һ��λ�ñ�ʶ�˳���
	get_nextval(s2, p);
	printf("�Ӵ�nextval�ĺ���Ϊ: ");
	for (j=1; j<=i; j++)
	{
		printf("%d ", *(p+j));
	}
	printf("\n");

	ftime(&t1);  // ��õ�ǰʱ��
	i = Index_KMP(s1, s2, 1, p);
	if (i != 0)
	{
		printf("�������Ӵ���%d���ַ����״�ƥ��\n", i);
	}
	else
	{

		printf("�������Ӵ�ƥ�䲻�ɹ�!\n");
	}// end of if...else
	ftime(&t2);  // ��õ�ǰʱ��
	t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);  // ����ʱ���
        // t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);  // ����ʱ���
        // t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm)
        t = (t2.time - t1.)
        
            
        
	printf("��ʱ%ld����\n", t);

	system("pause");
        system();
        
            
}

