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

//����ջ
// [in] S Ҫ������ջָ��
int InitStack(SqStack *S);

//����ջ��Ԫ��
// [in]  S ջָ��
// [out] e ����Ԫ�ص�ָ��
int GetTop(SqStack * S, SElemType * e);

//ѹ��Ԫ��
// [in]  S ջָ��
// [in]  e ѹ���Ԫ��
int Push(SqStack * S, SElemType e);

//����Ԫ��
// [in]  S ջָ��
// [in]  e ����Ԫ��ָ��
int Pop(SqStack * S, SElemType * e);


//���ջ�Ƿ�Ϊ��
// [in]  S ջָ��
// [re]  1--��ջ 0--�ǿ�ջ
int StackEmpty(SqStack * S);



#ifdef __cplusplus
}
#endif

#endif
