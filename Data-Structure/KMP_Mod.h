/*
* Copyright TES@NPU
* All rights reserved.
*
* FileName: KMP_Mod.h
* 
* Version: 1.0
* Updated @ Nov. 5 2011
* Finished @ Nov. 5 2011
 */

#include <string.h>
#include <ctype.h>
#include <malloc.h>  //mallc() and so on
#include <limits.h>  //INT_MAX and so on
#include <stdio.h>  //EOF(=^Z or F6), NULL
#include <stdlib.h>  //atoi()
#include <io.h>  //eof()
#include <math.h>  //floor(), ceil(), abs()
#include <process.h>  //exit()
#include <iostream>  //cout, cin
#include <sys/timeb.h>  // timeb
// ��ª�Ĳ���ʱ��,�����㷨��Ч��



using namespace std;

/*
	�������״̬����
 */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
// #define OVERFLOW -2 for there was the definition in file "math.h" so it could be omitted

/*
	�������ĺ�
 */
#define MAXSTRLEN 40  // �û�������255���ڶ�����󴮳�

typedef int Status;  // Status�Ǻ������ͣ� ��ֵ�Ǻ������״̬���룬��OK��
typedef int Boolean;  // Boolean�ǲ������ͣ���ֵ��TRUE��FALSE

typedef char SString[MAXSTRLEN+1];  // 0�ŵ�Ԫ��Ŵ��ĳ���

/*
	����������
	C++��֧��Ĭ������,�������Ǳ���������
	����һ��ϰ�߱ȽϺ�
 */
Status StrAssign(SString T, char *chars);
// Status StrCopy(SString T, SString S);  // �����������!
// Status StrEmpty(SString S);
// int StrCompare(SString S, SString T);
int StrLength(SString S);
// Status ClearString(SString S);
// Status Contact(SString T, SString S1, SString S2);
// Status SubString(SString Sub, SString S, int pos, int len);
// int Index(SString S, SString T, int pos);
// Status StrInsert(SString S, int pos, SString T);
// Status StrDelete(SString S, int pos, int len);
// Status Replace(SString S, SString T, SString V);
// void DestroyString();
void StrPrint(SString T);
void get_nextval(SString T, int nextval[]);
int Index_KMP(SString S, SString T, int pos, int next[]);
