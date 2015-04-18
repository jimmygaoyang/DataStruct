#include "LinearList.h"

//初始化表
//[in] L 被初始化的线性表的结构体指针
//[re] 1--成功 0--失败

int InitList_Prc(LinearList_T * L)
{
	//构造一个空线性表L
	L->elem = (ELemType *)malloc(LIST_INIT_SIZE * sizeof(ELemType));
	if (!L->elem) return FAILURE;//分配失败
	L->length = 0;				//当前长度
	L->listSize = LIST_INIT_SIZE;//初始分配的存储容量
	return SUCCESS;
}


// 插入元素到表
// [in] L 被初始化的线性表的结构体指针
// [in] i 插入的位置
// [in] e 插入的元素
// [re] 1--成功 0--失败
int ListInsert_Prc(LinearList_T *L, int i, ELemType e)
{
	ELemType * newBase = NULL;
	ELemType *q, *p;
	if (i < 1 || i > L->length+1) return FAILURE; // i值不合法
	if(L->length >= L->listSize)				  //当前存储空间已满，增加分配
	{
		newBase = (ELemType *)realloc(L->elem,
			(L->listSize+LISTINCREMENT) * sizeof(ELemType));
		if (!newBase) return FAILURE;
		L->elem = newBase; 
		L->listSize += LISTINCREMENT;
	}
	q = &(L->elem[i-1]);
	for (p=&(L->elem[L->length-1]); p>=q; --p) *(p+1) = *p;//元素逐个后移
	
	*q = e;			//插入e
	++L->length;	//表长增1
	return FAILURE;
}


// 析构表
void DestroyList_Prc(LinearList_T * L)
{
	if (!L->elem) free(L->elem);
	L->length = 0;

}