#include "Stack.h"

//����ջ
// [in] S Ҫ������ջָ��
int InitStack(SqStack *S)
{
	//����һ����ջ
	S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!S->base) return FAILURE;
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return SUCCESS;
}

//����ջ��Ԫ��
// [in]  S ջָ��
// [out] e ����Ԫ�ص�ָ��
int GetTop(SqStack * S, SElemType * e)
{
	if (S->top == S->base) return FAILURE;
	*e = *(S->top -1);
	return SUCCESS;
}

//ѹ��Ԫ��
// [in]  S ջָ��
// [in]  e ѹ���Ԫ��
int Push(SqStack * S, SElemType e)
{
	//����Ԫ��
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


//����Ԫ��
// [in]  S ջָ��
// [in]  e ����Ԫ��ָ��
int Pop(SqStack * S, SElemType * e)
{
	if (S->top == S->base) return FAILURE;
	*e = * --S->top;
	return SUCCESS;
}


//���ջ�Ƿ�Ϊ��
// [in]  S ջָ��
// [re]  1--��ջ 0--�ǿ�ջ
int StackEmpty(SqStack * S)
{
	if (S->top == S->base) return SUCCESS;
	return FAILURE;
}
