/*
* Copyright (C) TES@NPU 
* School of Automation InfoSec
* All rights reserved.
*
* FileName: Time.cpp
* 
* Version: 1.0
* 
* Updated @ Nov. 5 2011
* Finished @ Nov. 5 2011
 */
 // һ����ª��ʱ����Ժ���,ԭ��@��һ��
 
#include <stdio.h>
#include <sys/timeb.h>


void main()
{
	timeb t1;
	timeb t2;
	long t;

	ftime(&t1);  // ��õ�ǰʱ��
	/*
		�����м��������Ҫ���ԵĴ���
		Ȼ��ע��ȡ����...
	 */
	ftime(&t2);  // ��õ�ǰʱ��
	t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);  // ����ʱ���
	// t = (t2.time - t1.)
        // t = (t2.millitm - t1.)
        t = (t2.)
	printf("��ʱ%ld����\n", t);
}
