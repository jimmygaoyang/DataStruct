#include "SqList.h"
#include <iostream>
#include <stdlib.h>
#include "SingleList.h"
using namespace std;
int main()
{
	SqList lst1;
	ELemType e;
	cout<<"插入100个"<<endl;
	for (int i = 1; i<100; i++)
	{
		e.mem = i;
		e.memChar = 'p';
		lst1.ListInsert(i,e);
	}
	cout<<"获取100个"<<endl;
	for (int i = 1; i<100; i++)
	{
		lst1.GetElem(i,e);
		cout << e.mem << e.memChar<<endl;
	}
	cout<<"删除前50个后"<<endl;
	for (int i = 1; i<50; i++)
	{
		lst1.DelElem(1);
	}
	for (int i=1;i<lst1.GetLength();i++)
	{
		lst1.GetElem(i,e);
		cout << e.mem << e.memChar<<endl;
	}


	SingleList singleL;
	e.mem = 1;
	e.memChar='u';
	singleL.InsertElem(1,e);
	e.mem = 2;
	e.memChar = 'v';
	singleL.InsertElem(2,e);
	e.mem = 3;
	e.memChar = 'o';
	singleL.InsertElem(3,e);
	for (int i=1; i<=singleL.GetLength();i++)
	{
		singleL.GetElem(i,&e);
		cout << e.mem << e.memChar<<endl;
	}

	singleL.DelElem(2,&e);

	for (int i=1; i<=singleL.GetLength();i++)
	{
		singleL.GetElem(i,&e);
		cout << e.mem << e.memChar<<endl;
	}

	system("pause");
}