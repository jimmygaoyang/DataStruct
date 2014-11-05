#ifndef BITREE_H
#define BITREE_H

#ifdef __cplusplus
extern "C"
{
#endif
#include "GlobalDef.h"


/*�������ڵ�*/
typedef struct BiTNode{
	ELemType elem;		//�洢�ռ����ַ
	struct BiTNode * lchild; //��child
	struct BiTNode * rchild; //��child
}BiTNode, *BiTree;

//������
struct BiTreeObj{
	BiTree Tree;//������ʵ��ָ��
	int (*CreatBiTree)(BiTree *);//������
	int (*PreOrderTraverse)(struct BiTreeObj*,BiTree); //�������
	int (*InOrderTraverse)(struct BiTreeObj*,BiTree);  //�������
	int (*PostOrderTraverse)(struct BiTreeObj*,BiTree);//�������
	int (*LevelOrderTraverse)(struct BiTreeObj*,BiTree);//�������
	int (*Visit)(ELemType);//���ʺ���
	void (*DestroyBiTree)(BiTree);//����������
};

typedef struct BiTreeObj BiTree_T;

//�������ķ��ʺ���
int PrintElement(ELemType e);

//������
// [in] T ������ָ��
int CreatBiTree_Pro(BiTree *T);

// �������������
// [in] T ������ָ��
// [in] Visit ���ʽڵ�ĺ���ָ��
// [re] 1--�ɹ� 0--ʧ��
int PreOrderTraverse_Prc(struct BiTreeObj* TObj,BiTree T);

// �������������
// [in] T ������ָ��
// [in] Visit ���ʽڵ�ĺ���ָ��
// [re] 1--�ɹ� 0--ʧ��
int InOrderTraverse_Prc(struct BiTreeObj* TObj,BiTree T);

// �������������
// [in] T ������ָ��
// [in] Visit ���ʽڵ�ĺ���ָ��
// [re] 1--�ɹ� 0--ʧ��
int PostOrderTraverse_Prc(struct BiTreeObj* TObj,BiTree T);

// �������������
// [in] T ������ָ��
// [in] Visit ���ʽڵ�ĺ���ָ��
// [re] 1--�ɹ� 0--ʧ��
int LevelOrderTraverse_Prc(struct BiTreeObj* TObj,BiTree T);

// ������
// [in] T ������ָ��
void DestroyBiTree_Prc(BiTree T);


//��ʼ�꣨���湹�캯����
#define BITREE_DEFAULT    { NULL,\
    CreatBiTree_Pro,\
	PreOrderTraverse_Prc,\
	InOrderTraverse_Prc,\
	PostOrderTraverse_Prc,\
	LevelOrderTraverse_Prc,\
	PrintElement,\
	DestroyBiTree_Prc} 

#ifdef __cplusplus
}
#endif

#endif




