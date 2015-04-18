/***********************************************************************
 * Module:  SqList.cpp
 * Author:  Thinkpad
 * Modified: 2015-04-18 11:14:35
 * Purpose: Implementation of the class SqList
 * Comment: ���Ա���
 ***********************************************************************/
#include <stdio.h>
#include <string.h>
#include "SqList.h"

////////////////////////////////////////////////////////////////////////
// Name:       SqList::InitList()
// Purpose:    Implementation of SqList::InitList()
// Comment:    ��ʼ����
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
	//����һ�������Ա�L
	return SUCCESS;

}

////////////////////////////////////////////////////////////////////////
// Name:       SqList::DestroyList()
// Purpose:    Implementation of SqList::DestroyList()
// Comment:    ������
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
// Comment:    ����Ԫ�ص���
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
	if (i < 1 || i > length+1) return FAILURE;  // iֵ���Ϸ�
	if(length >= listSize)				  //��ǰ�洢�ռ����������ӷ���
	{
		newBase = new ELemType[listSize+LISTINCREMENT];
		if (!newBase) return FAILURE;
		memcpy((void *)newBase,(void *)elem,length*sizeof(ELemType));
		delete [] elem;
		elem = newBase ; 
		listSize += LISTINCREMENT;
	}
	q = &(elem[i-1]);
	for (p=&(elem[length-1]); p>=q; --p) *(p+1) = *p;//Ԫ���������

	*q = e;			//����e
	++length;	//����1
	return SUCCESS;
}


////////////////////////////////////////////////////////////////////////
// Name:       GetElem
// Comment:    ��ȡԪ�� 
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
// Comment:    ɾ��Ԫ�� 
// Parameters:
// - i
// Return:     int
////////////////////////////////////////////////////////////////////////
int SqList::DelElem(int i)
{
	ELemType *p;
	if (i < 1 || i > length) 
		return FAILURE;  // iֵ���Ϸ�
	
	for(p=&(elem[i-1]); p<&(elem[length-1]); p++)
	{
		*p = *(p+1);//Ԫ�����ǰ��		
	}
	length--;
		
	return SUCCESS;
}
////////////////////////////////////////////////////////////////////////
// Name:       GetLength
// Comment:    ��ȡ���Ա��� 
// Parameters:
// Return:     int
////////////////////////////////////////////////////////////////////////
   int SqList::GetLength()
   {
	    return length;
   }
