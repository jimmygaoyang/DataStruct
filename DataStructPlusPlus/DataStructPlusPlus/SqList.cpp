/***********************************************************************
 * Module:  SqList.cpp
 * Author:  Thinkpad
 * Modified: 2015-04-18 11:14:35
 * Purpose: Implementation of the class SqList
 * Comment: 线性表类
 ***********************************************************************/
#include <stdio.h>
#include <string.h>
#include "SqList.h"

////////////////////////////////////////////////////////////////////////
// Name:       SqList::InitList()
// Purpose:    Implementation of SqList::InitList()
// Comment:    初始化表
// Return:     int
////////////////////////////////////////////////////////////////////////
SqList::SqList()
{
	elem = new ELemType[LIST_INIT_SIZE];
	length = 0;
	listSize = LIST_INIT_SIZE;
}
SqList::~SqList()
{
	delete [] elem ;
	length = 0;
	listSize = 0;
}

int SqList::InitList(void)
{
	//构造一个空线性表L
	return SUCCESS;

}

////////////////////////////////////////////////////////////////////////
// Name:       SqList::DestroyList()
// Purpose:    Implementation of SqList::DestroyList()
// Comment:    析构表
// Return:     int
////////////////////////////////////////////////////////////////////////

int SqList::DestroyList(void)
{
   // TODO : implement
	return SUCCESS;
}

////////////////////////////////////////////////////////////////////////
// Name:       SqList::ListInsert(int i, ELemType e)
// Purpose:    Implementation of SqList::ListInsert()
// Comment:    插入元素到表
// Parameters:
// - i
// - e
// Return:     int SUC
////////////////////////////////////////////////////////////////////////

int SqList::ListInsert(int i, ELemType e)
{
   // TODO : implement
	ELemType * newBase = NULL;
	ELemType *q, *p;
	if (i < 1 || i > length+1) return FAILURE;  // i值不合法
	if(length >= listSize)				  //当前存储空间已满，增加分配
	{
		newBase = new ELemType[listSize+LISTINCREMENT];
		if (!newBase) return FAILURE;
		memcpy((void *)newBase,(void *)elem,length*sizeof(ELemType));
		delete [] elem;
		elem = newBase ; 
		listSize += LISTINCREMENT;
	}
	q = &(elem[i-1]);
	for (p=&(elem[length-1]); p>=q; --p) *(p+1) = *p;//元素逐个后移

	*q = e;			//插入e
	++length;	//表长增1
	return SUCCESS;
}


////////////////////////////////////////////////////////////////////////
// Name:       GetElem
// Comment:    获取元素 
// Parameters:
// - i
// - e
// Return:     int
////////////////////////////////////////////////////////////////////////
int SqList::GetElem(int i,ELemType &e)
{
	if(length == 0 || i<1 || i>length)
		return FAILURE;
	e = elem[i-1];
	return SUCCESS;	
}

////////////////////////////////////////////////////////////////////////
// Name:       DelElem
// Comment:    删除元素 
// Parameters:
// - i
// Return:     int
////////////////////////////////////////////////////////////////////////
int SqList::DelElem(int i)
{
	ELemType *p;
	if (i < 1 || i > length) 
		return FAILURE;  // i值不合法
	
	for(p=&(elem[i-1]); p<&(elem[length-1]); p++)
	{
		*p = *(p+1);//元素逐个前移		
	}
	length--;
		
	return SUCCESS;
}
////////////////////////////////////////////////////////////////////////
// Name:       GetLength
// Comment:    获取线性表长度 
// Parameters:
// Return:     int
////////////////////////////////////////////////////////////////////////
   int SqList::GetLength()
   {
	    return length;
   }
