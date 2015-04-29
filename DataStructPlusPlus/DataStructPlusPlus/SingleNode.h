/***********************************************************************
 * Module:  SingleNode.h
 * Author:  Thinkpad
 * Modified: 2015-04-22 09:09:53
 * Purpose: Declaration of the class SingleNode
 * Comment: 单向链表节点
 ***********************************************************************/

#if !defined(__SqList_SingleNode_h)
#define __SqList_SingleNode_h

#include "ELemType.h"

class SingleNode
{
public:
   SingleNode();
   ~SingleNode();

   /* 数据元素 */
   ELemType data;
   /* 下一个节点的指针 */
   SingleNode *pNext;

protected:
private:

};

#endif