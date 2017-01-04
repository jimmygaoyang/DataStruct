#ifndef DIVMERG_H
#define DIVMERG_H

#ifdef __cplusplus
extern "C"
{
#endif
#include "GlobalDef.h"
//对数据进行归并排序
void merge_sort(int *data, int start, int end, int *result);

#ifdef __cplusplus
}
#endif

#endif
