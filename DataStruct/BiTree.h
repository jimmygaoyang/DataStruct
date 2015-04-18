#ifndef BITREE_H
#define BITREE_H

#ifdef __cplusplus
extern "C"
{
#endif
#include "GlobalDef.h"


/*二叉树节点*/
typedef struct BiTNode{
	ELemType elem;		//存储空间基地址
	struct BiTNode * lchild; //左child
	struct BiTNode * rchild; //右child
}BiTNode, *BiTree;

//二叉树
struct BiTreeObj{
	BiTree Tree;//二叉树实体指针
	int (*CreatBiTree)(BiTree *);//创建树
	int (*PreOrderTraverse)(struct BiTreeObj*,BiTree); //先序遍历
	int (*InOrderTraverse)(struct BiTreeObj*,BiTree);  //中序遍历
	int (*PostOrderTraverse)(struct BiTreeObj*,BiTree);//后序遍历
	int (*LevelOrderTraverse)(struct BiTreeObj*,BiTree);//层序遍历
	int (*Visit)(ELemType);//访问函数
	void (*DestroyBiTree)(BiTree);//析构二叉树
};

typedef struct BiTreeObj BiTree_T;

//二叉树的访问函数
int PrintElement(ELemType e);

//创建树
// [in] T 二叉树指针
int CreatBiTree_Pro(BiTree *T);

// 先序遍历二叉树
// [in] T 二叉树指针
// [in] Visit 访问节点的函数指针
// [re] 1--成功 0--失败
int PreOrderTraverse_Prc(struct BiTreeObj* TObj,BiTree T);

// 中序遍历二叉树
// [in] T 二叉树指针
// [in] Visit 访问节点的函数指针
// [re] 1--成功 0--失败
int InOrderTraverse_Prc(struct BiTreeObj* TObj,BiTree T);

// 后序遍历二叉树
// [in] T 二叉树指针
// [in] Visit 访问节点的函数指针
// [re] 1--成功 0--失败
int PostOrderTraverse_Prc(struct BiTreeObj* TObj,BiTree T);

// 层序遍历二叉树
// [in] T 二叉树指针
// [in] Visit 访问节点的函数指针
// [re] 1--成功 0--失败
int LevelOrderTraverse_Prc(struct BiTreeObj* TObj,BiTree T);

// 析构树
// [in] T 二叉树指针
void DestroyBiTree_Prc(BiTree T);


//初始宏（代替构造函数）
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




