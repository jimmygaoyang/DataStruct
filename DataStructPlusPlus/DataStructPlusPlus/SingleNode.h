/***********************************************************************
 * Module:  SingleNode.h
 * Author:  Thinkpad
 * Modified: 2015-04-22 09:09:53
 * Purpose: Declaration of the class SingleNode
 * Comment: ��������ڵ�
 ***********************************************************************/

#if !defined(__SqList_SingleNode_h)
#define __SqList_SingleNode_h

#include "ELemType.h"

class SingleNode
{
public:
   SingleNode();
   ~SingleNode();

   /* ����Ԫ�� */
   ELemType data;
   /* ��һ���ڵ��ָ�� */
   SingleNode *pNext;

protected:
private:

};

#endif