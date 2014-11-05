#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

#ifdef __cplusplus
extern "C"
{
#endif


#include "GlobalDef.h"


/*线性表*/
#define  LIST_INIT_SIZE 100	/*线性表存储空间的初始分配量*/
#define  LISTINCREMENT 10	/*线性表存储空间的分配增量*/


/*线性表类*/
struct SqList{
	ELemType * elem;		//存储空间基地址
	int length;				//当前长度
	int listSize;			//当前分配的容量(以sizeof(ELemType)为单位)
	int (*InitList)(struct SqList *);
	void (*DestroyList)(struct SqList *);//析构表类创建时malloc出的内存
	int (*ListInsert)(struct SqList *, int, ELemType);
};

typedef struct SqList LinearList_T;



// 初始化表
// [in] L 被初始化的线性表的结构体指针
// [re] 1--成功 0--失败
int InitList_Prc(LinearList_T *L);

// 插入元素到表
// [in] L 被初始化的线性表的结构体指针
// [in] i 插入的位置
// [in] e 插入的元素
// [re] 1--成功 0--失败
int ListInsert_Prc(LinearList_T *L, int i, ELemType e);

// 析构表
void DestroyList_Prc(LinearList_T *L);


//初始宏（代替构造函数）
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




