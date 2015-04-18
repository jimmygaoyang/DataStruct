/***********************************************************************
 * Module:  SqList.h
 * Author:  Thinkpad
 * Modified: 2015-04-18 11:14:35
 * Purpose: Declaration of the class SqList
 * Comment: 线性表类
 ***********************************************************************/

#if !defined(__SqList_SqList_h)
#define __SqList_SqList_h

#include "ELemType.h"

/*线性表*/
#define  LIST_INIT_SIZE 10	/*线性表存储空间的初始分配量*/
#define  LISTINCREMENT 10	/*线性表存储空间的分配增量*/

class SqList
{
public:
   /* 初始化表 */
   int InitList(void);
   /* 析构表 */
   int DestroyList(void);
   /* 插入元素到表 */
   int ListInsert(int i, ELemType e);
   /* 获取元素 */
   int GetElem(int i,ELemType &e);
   /*删除元素*/
   int DelElem(int i);
   /*获取线性表长度*/
   int GetLength();



   SqList();
   ~SqList();

protected:
private:
   /* 存储空间基地址 */
   ELemType *elem;
   /* 当前长度 */
   int length;
   /* 当前分配的容量(以sizeof(ELemType)为单位) */
   int listSize;


};

#endif