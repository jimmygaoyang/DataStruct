#include "BiTree.h"
#include "Stack.h"
#include <stdio.h>

//创建树
// [in] T 二叉树指针
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


// 先序遍历二叉树
// [in] T 二叉树指针
// [in] Visit 访问节点的函数指针
// [re] 1--成功 0--失败
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

// 中序遍历二叉树
// [in] T 二叉树指针
// [in] Visit 访问节点的函数指针
// [re] 1--成功 0--失败
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

// 中序遍历二叉树
// [in] T 二叉树指针
// [in] Visit 访问节点的函数指针
// [re] 1--成功 0--失败
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

// 后序遍历二叉树
// [in] T 二叉树指针
// [in] Visit 访问节点的函数指针
// [re] 1--成功 0--失败
int PostOrderTraverse_Prc(struct BiTreeObj* TObj,BiTree T)
{
	return SUCCESS;
}

// 层序遍历二叉树
// [in] T 二叉树指针
// [in] Visit 访问节点的函数指针
// [re] 1--成功 0--失败
int LevelOrderTraverse_Prc(struct BiTreeObj* TObj,BiTree T)
{
	return SUCCESS;
}

//二叉树的访问函数
int PrintElement(ELemType e)
{
	printf("%c ", e.memChar);
	return SUCCESS;
}
// 析构树
// [in] T 二叉树指针
void DestroyBiTree_Prc(BiTree T)
{

}