#include "InsertSort.h"

//对数据进行插入排序
void InsertSort(int *input,int len)
{
	int j=0;
	int i=0;
	int key=0;
	for(j=1;j<len;j++)
	{
		key = input[j];
		i = j-1;
		while(i>=0 && input[i]>key)
		{	
			input[i+1] = input[i];
			i--;
		}
		input[i+1] = key;
	}
}