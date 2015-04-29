/***********************************************************************
 * Module:  SingleList.cpp
 * Author:  Thinkpad
 * Modified: 2015-04-22 09:07:30
 * Purpose: Implementation of the class SingleList
 * Comment: ��������
 ***********************************************************************/
#include "SingleList.h"

////////////////////////////////////////////////////////////////////////
// Name:       SingleList::GetElem(int i, ELemType e)
// Purpose:    Implementation of SingleList::GetElem()
// Comment:    ��ȡԪ��
// Parameters:
// - i [in]	    ��ȡԪ�ص�λ��
// - e [in/out] Ԫ�ش����ָ��
// Return:     int
////////////////////////////////////////////////////////////////////////

int SingleList::GetElem(int i, ELemType* e)
{
   // TODO : implement
	int j;
	SingleNode *p;
	p = pHead->pNext;
	j=1;
	while (p && j < i)
	{
		p = p->pNext;
		++j;
	}
	if (!p || j>i)
	{
		return FAILURE;
	}
	*e = p->data;
	return SUCCESS;
}

////////////////////////////////////////////////////////////////////////
// Name:       SingleList::InsertElem(int i, ELemType e)
// Purpose:    Implementation of SingleList::InsertElem()
// Comment:    ����Ԫ��
// Parameters:
// - i [in]	    ����Ԫ�ص�λ��
// - e [in]	    �����Ԫ��
// Return:     int
////////////////////////////////////////////////////////////////////////

int SingleList::InsertElem(int i, ELemType e)
{
   // TODO : implement
	int j;
	SingleNode *p,*s;
	p = pHead;
	j = 1;
	while (p && j < i)
	{
		p = p->pNext;
		j++;
	}

	if (!p ||j > i)
	{
		return FAILURE;
	}
	s = new SingleNode;
	s->data = e;
	s->pNext = p->pNext;
	p->pNext = s;

	length++;
	return SUCCESS;
}

////////////////////////////////////////////////////////////////////////
// Name:       SingleList::DelElem(int i, ELemType e)
// Purpose:    Implementation of SingleList::DelElem()
// Comment:    ɾ��Ԫ��
// Parameters:
// - i [in]	    ɾ��Ԫ�ص�λ��
// - e [in/out] ɾ��Ԫ�صķ���ֵ
// Return:     int
////////////////////////////////////////////////////////////////////////

int SingleList::DelElem(int i, ELemType *e)
{
   // TODO : implement
	int j;
	SingleNode *p,*q;
	p = pHead;
	j=1;
	while (p->pNext && j < i)
	{
		p=p->pNext;
		j++;
	}
	if (!(p->pNext) || j > i)
	{
		return FAILURE;
	}
	
	q = p->pNext;
	p->pNext =q->pNext;
	*e = q->data;
	delete q;
	length--;
	return SUCCESS;
}

////////////////////////////////////////////////////////////////////////
// Name:       SingleList::GetLength()
// Purpose:    Implementation of SingleList::GetLength()
// Return:     Length of the List
////////////////////////////////////////////////////////////////////////
int SingleList::GetLength()
{
	return length;
}


////////////////////////////////////////////////////////////////////////
// Name:       SingleList::SingleList()
// Purpose:    Implementation of SingleList::SingleList()
// Return:     
////////////////////////////////////////////////////////////////////////

SingleList::SingleList()
{
	length = 0;
	pHead = new SingleNode;
	pTail = new SingleNode;
}

////////////////////////////////////////////////////////////////////////
// Name:       SingleList::~SingleList()
// Purpose:    Implementation of SingleList::~SingleList()
// Return:     
////////////////////////////////////////////////////////////////////////

SingleList::~SingleList()
{
   // TODO : implement
	delete pHead;
	delete pTail;
	length = 0;
}