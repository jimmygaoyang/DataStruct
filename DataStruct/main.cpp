#include "LinearList.h"
#include "BiTree.h"
#include "Stack.h"

int main()
{
	//���Ա�Ĳ�������
	int res;
	LinearList_T ListTest = LINEAR_LIST_DEFAULT;
	res = ListTest.InitList(&ListTest);

	ELemType elem;
	for (int i=1; i<=10; i++)
	{
		elem.mem1 = i;
		ListTest.ListInsert(&ListTest, i, elem);
	}
	elem.mem1=11;
	ListTest.ListInsert(&ListTest, 1, elem);
	ListTest.DestroyList(&ListTest);

	//ջ����
// 	SqStack StackTest;
// 	res = InitStack(&StackTest);
// 	
// 	for (SElemType e=1; e<=10; e++)
// 		Push(&StackTest, e);
// 	SElemType elemt;
// 	for (i=1; i<=10; i++)
// 		Pop(&StackTest, &elemt);

	//����������
	BiTree_T BiTreeTest = BITREE_DEFAULT;
	BiTreeTest.CreatBiTree(&(BiTreeTest.Tree));
	//�������
	PreOrderTraverse_Prc(&BiTreeTest,BiTreeTest.Tree);


	InOrderTraverse_Prc(&BiTreeTest,BiTreeTest.Tree);
	return 1;
}
