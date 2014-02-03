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
 // 一个简陋的时间测试函数,原创@高一凡
 
#include <stdio.h>
#include <sys/timeb.h>


void main()
{
	timeb t1;
	timeb t2;
	long t;

	ftime(&t1);  // 求得当前时间
	/*
		在这中间添加你需要测试的代码
		然后将注释取消掉...
	 */
	ftime(&t2);  // 求得当前时间
	t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);  // 计算时间差
	// t = (t2.time - t1.)
        // t = (t2.millitm - t1.)
        t = (t2.)
	printf("用时%ld毫秒\n", t);
}
