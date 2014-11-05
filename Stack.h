#ifndef STACK_H
#define STACK_H

#ifdef __cplusplus
extern "C"
{
#endif
#include "GlobalDef.h"
#include "BiTree.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10

typedef BiTree SElemType;

typedef struct{
	SElemType * base;
	SElemType * top;
	int stacksize;
}SqStack;

//创建栈
// [in] S 要创建的栈指针
int InitStack(SqStack *S);

//返回栈顶元素
// [in]  S 栈指针
// [out] e 返回元素的指针
int GetTop(SqStack * S, SElemType * e);

//压入元素
// [in]  S 栈指针
// [in]  e 压入的元素
int Push(SqStack * S, SElemType e);

//弹出元素
// [in]  S 栈指针
// [in]  e 弹出元素指针
int Pop(SqStack * S, SElemType * e);


//检测栈是否为空
// [in]  S 栈指针
// [re]  1--空栈 0--非空栈
int StackEmpty(SqStack * S);



#ifdef __cplusplus
}
#endif

#endif
