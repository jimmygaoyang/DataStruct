/***********************************************************************
 * Module:  SingleList.h
 * Author:  Thinkpad
 * Modified: 2015-04-22 09:07:30
 * Purpose: Declaration of the class SingleList
 * Comment: ��������
 ***********************************************************************/

#if !defined(__SqList_SingleList_h)
#define __SqList_SingleList_h

class SingleNode;

#include "SingleNode.h"

class SingleList
{
public:
   /* ��ȡԪ�� */
   int GetElem(int i, ELemType *e);
   /* ����Ԫ�� */
   int InsertElem(int i, ELemType e);
   /* ɾ��Ԫ�� */
   int DelElem(int i, ELemType *e);
   /* ��ȡ���鳤��*/
   int GetLength();
   SingleList();
   ~SingleList();

   SingleNode* pSingleNode;

protected:
private:
   SingleNode *pHead;
   SingleNode *pTail;
   int length;
};

#endif