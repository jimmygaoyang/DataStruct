/***********************************************************************
 * Module:  SqList.h
 * Author:  Thinkpad
 * Modified: 2015-04-18 11:14:35
 * Purpose: Declaration of the class SqList
 * Comment: ���Ա���
 ***********************************************************************/

#if !defined(__SqList_SqList_h)
#define __SqList_SqList_h

#include "ELemType.h"

/*���Ա�*/
#define  LIST_INIT_SIZE 10	/*���Ա�洢�ռ�ĳ�ʼ������*/
#define  LISTINCREMENT 10	/*���Ա�洢�ռ�ķ�������*/

class SqList
{
public:
   /* ��ʼ���� */
   int InitList(void);
   /* ������ */
   int DestroyList(void);
   /* ����Ԫ�ص��� */
   int ListInsert(int i, ELemType e);
   /* ��ȡԪ�� */
   int GetElem(int i,ELemType &e);
   /*ɾ��Ԫ��*/
   int DelElem(int i);
   /*��ȡ���Ա���*/
   int GetLength();



   SqList();
   ~SqList();

protected:
private:
   /* �洢�ռ����ַ */
   ELemType *elem;
   /* ��ǰ���� */
   int length;
   /* ��ǰ���������(��sizeof(ELemType)Ϊ��λ) */
   int listSize;


};

#endif