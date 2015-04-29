/***********************************************************************
 * Module:  SingleList.h
 * Author:  Thinkpad
 * Modified: 2015-04-22 09:07:30
 * Purpose: Declaration of the class SingleList
 * Comment: 单向链表
 ***********************************************************************/

#if !defined(__SqList_SingleList_h)
#define __SqList_SingleList_h

class SingleNode;

#include "SingleNode.h"

class SingleList
{
public:
   /* 获取元素 */
   int GetElem(int i, ELemType *e);
   /* 插入元素 */
   int InsertElem(int i, ELemType e);
   /* 删除元素 */
   int DelElem(int i, ELemType *e);
   /* 获取数组长度*/
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