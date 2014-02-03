/*
* Copyright TES@NPU
* All rights reserved.
*
* FileName: c1.h
* 
* Version: 1.0
* Finished @ Sep. 21st 2011
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

using namespace std;

// Codes for the result of functions
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
// #define OVERFLOW -2 for there was the definition in file "math.h" so it could be omitted

typedef int Status;  // Status是函数类型， 其值是函数结果状态代码，如OK等
typedef int Boolean;  // Boolean是布尔类型，其值是TRUE或FALSE


// Comments




