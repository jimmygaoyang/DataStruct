#include "BiTree.h"
#include "Stack.h"
#include <stdio.h>

//������
// [in] T ������ָ��
int CreatBiTree_Pro(BiTree *T)
{
	char ch;
	printf("Enter next\n");
	scanf("%c", &ch);
	if (ch == ' ') 
		*T = NULL;
	else
	{
		if (!(*T = (BiTNode *)malloc(sizeof(BiTNode))))
			return FAILURE;
		(*T)->elem.memChar = ch;
		CreatBiTree_Pro(&((*T)->lchild));
		CreatBiTree_Pro(&((*T)->rchild));
	}

	return SUCCESS;
}


// �������������
// [in] T ������ָ��
// [in] Visit ���ʽڵ�ĺ���ָ��
// [re] 1--�ɹ� 0--ʧ��
int PreOrderTraverse_Prc(struct BiTreeObj* TObj,BiTree T)
{
	if (T)
	{
		if (TObj->Visit(T->elem))
			if (PreOrderTraverse_Prc(TObj, T->lchild))
				if (PreOrderTraverse_Prc(TObj, T->rchild))
					return SUCCESS;
		return FAILURE;			
	}
	else 
	return SUCCESS;
}

// �������������
// [in] T ������ָ��
// [in] Visit ���ʽڵ�ĺ���ָ��
// [re] 1--�ɹ� 0--ʧ��
int InOrderTraverse_Prc(struct BiTreeObj* TObj,BiTree T)
{
	SqStack StackTest;
	BiTree p;
	InitStack(&StackTest);
	Push(&StackTest, T);
	while (!StackEmpty(&StackTest))
	{
		while(GetTop(&StackTest,&p) && p) Push(&StackTest,p->lchild);	
		Pop(&StackTest,&p);
		if (!StackEmpty(&StackTest))
		{
			Pop(&StackTest,&p); 
			if (!TObj->Visit(p->elem)) return FAILURE;
			Push(&StackTest,p->rchild);
		}
	}
	return SUCCESS;
}

// �������������
// [in] T ������ָ��
// [in] Visit ���ʽڵ�ĺ���ָ��
// [re] 1--�ɹ� 0--ʧ��
int InOrderTraverse_Prc2(struct BiTreeObj* TObj,BiTree T)
{
	SqStack StackTest;
	BiTree p = T;
	InitStack(&StackTest);
	
	while (p || !StackEmpty(&StackTest))
	{
		if(p){ Push(&StackTest, p); p = p->lchild}
		else
		{
			Pop(&StackTest,&p); 
			if (!TObj->Visit(p->elem)) return FAILURE;
			p = p->rchild;
		}
	}
	return SUCCESS;
}

// �������������
// [in] T ������ָ��
// [in] Visit ���ʽڵ�ĺ���ָ��
// [re] 1--�ɹ� 0--ʧ��
int PostOrderTraverse_Prc(struct BiTreeObj* TObj,BiTree T)
{
	return SUCCESS;
}

// �������������
// [in] T ������ָ��
// [in] Visit ���ʽڵ�ĺ���ָ��
// [re] 1--�ɹ� 0--ʧ��
int LevelOrderTraverse_Prc(struct BiTreeObj* TObj,BiTree T)
{
	return SUCCESS;
}

//�������ķ��ʺ���
int PrintElement(ELemType e)
{
	printf("%c ", e.memChar);
	return SUCCESS;
}
// ������
// [in] T ������ָ��
void DestroyBiTree_Prc(BiTree T)
{

}