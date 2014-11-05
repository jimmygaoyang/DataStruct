#include "Stack.h"

//创建栈
// [in] S 要创建的栈指针
int InitStack(SqStack *S)
{
	//构造一个空栈
	S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!S->base) return FAILURE;
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return SUCCESS;
}

//返回栈顶元素
// [in]  S 栈指针
// [out] e 返回元素的指针
int GetTop(SqStack * S, SElemType * e)
{
	if (S->top == S->base) return FAILURE;
	*e = *(S->top -1);
	return SUCCESS;
}

//压入元素
// [in]  S 栈指针
// [in]  e 压入的元素
int Push(SqStack * S, SElemType e)
{
	//插入元素
	if (S->top - S->base >= S->stacksize)
	{
		S->base = (SElemType *)realloc(S->base, 
			(S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if(!S->base) return FAILURE;
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	* S->top++ = e;
	return SUCCESS;
}


//弹出元素
// [in]  S 栈指针
// [in]  e 弹出元素指针
int Pop(SqStack * S, SElemType * e)
{
	if (S->top == S->base) return FAILURE;
	*e = * --S->top;
	return SUCCESS;
}


//检测栈是否为空
// [in]  S 栈指针
// [re]  1--空栈 0--非空栈
int StackEmpty(SqStack * S)
{
	if (S->top == S->base) return SUCCESS;
	return FAILURE;
}
