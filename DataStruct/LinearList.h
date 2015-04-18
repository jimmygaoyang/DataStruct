#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

#ifdef __cplusplus
extern "C"
{
#endif


#include "GlobalDef.h"


/*���Ա�*/
#define  LIST_INIT_SIZE 100	/*���Ա�洢�ռ�ĳ�ʼ������*/
#define  LISTINCREMENT 10	/*���Ա�洢�ռ�ķ�������*/


/*���Ա���*/
struct SqList{
	ELemType * elem;		//�洢�ռ����ַ
	int length;				//��ǰ����
	int listSize;			//��ǰ���������(��sizeof(ELemType)Ϊ��λ)
	int (*InitList)(struct SqList *);
	void (*DestroyList)(struct SqList *);//�������ഴ��ʱmalloc�����ڴ�
	int (*ListInsert)(struct SqList *, int, ELemType);
};

typedef struct SqList LinearList_T;



// ��ʼ����
// [in] L ����ʼ�������Ա�Ľṹ��ָ��
// [re] 1--�ɹ� 0--ʧ��
int InitList_Prc(LinearList_T *L);

// ����Ԫ�ص���
// [in] L ����ʼ�������Ա�Ľṹ��ָ��
// [in] i �����λ��
// [in] e �����Ԫ��
// [re] 1--�ɹ� 0--ʧ��
int ListInsert_Prc(LinearList_T *L, int i, ELemType e);

// ������
void DestroyList_Prc(LinearList_T *L);


//��ʼ�꣨���湹�캯����
#define LINEAR_LIST_DEFAULT    { NULL,\
	0,\
	0,\
    InitList_Prc,\
	DestroyList_Prc,\
	ListInsert_Prc} 

#ifdef __cplusplus
}
#endif

#endif




