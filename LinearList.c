#include "LinearList.h"

//��ʼ����
//[in] L ����ʼ�������Ա�Ľṹ��ָ��
//[re] 1--�ɹ� 0--ʧ��

int InitList_Prc(LinearList_T * L)
{
	//����һ�������Ա�L
	L->elem = (ELemType *)malloc(LIST_INIT_SIZE * sizeof(ELemType));
	if (!L->elem) return FAILURE;//����ʧ��
	L->length = 0;				//��ǰ����
	L->listSize = LIST_INIT_SIZE;//��ʼ����Ĵ洢����
	return SUCCESS;
}


// ����Ԫ�ص���
// [in] L ����ʼ�������Ա�Ľṹ��ָ��
// [in] i �����λ��
// [in] e �����Ԫ��
// [re] 1--�ɹ� 0--ʧ��
int ListInsert_Prc(LinearList_T *L, int i, ELemType e)
{
	ELemType * newBase = NULL;
	ELemType *q, *p;
	if (i < 1 || i > L->length+1) return FAILURE; // iֵ���Ϸ�
	if(L->length >= L->listSize)				  //��ǰ�洢�ռ����������ӷ���
	{
		newBase = (ELemType *)realloc(L->elem,
			(L->listSize+LISTINCREMENT) * sizeof(ELemType));
		if (!newBase) return FAILURE;
		L->elem = newBase; 
		L->listSize += LISTINCREMENT;
	}
	q = &(L->elem[i-1]);
	for (p=&(L->elem[L->length-1]); p>=q; --p) *(p+1) = *p;//Ԫ���������
	
	*q = e;			//����e
	++L->length;	//����1
	return FAILURE;
}


// ������
void DestroyList_Prc(LinearList_T * L)
{
	if (!L->elem) free(L->elem);
	L->length = 0;

}