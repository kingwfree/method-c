#include <stdio.h>
#include "malloc.h"
#include <stdlib.h>

typedef int ElementType;

typedef struct LNode{
	ElementType *pBase;
	int length;
	int count;
}L,*List;

void InitList(List list,int len){
	list->pBase = (ElementType *)malloc(len*sizeof(ElementType));
	if(list == NULL){
		printf("内存空间分配失败\n");
		exit(-1);
	}
	list->length=len;
	list->count=0;
}
bool isFull(List list){
	bool flag = list->count == list->length?true:false;
	return flag;
}
//插入值
bool PushList(List list,int value){
	if(isFull(list)){
		printf("数组已满!\n");
		return false;
	}else{
		list->pBase[list->count] = value;
		list->count++;
		return true;
	}
}
void Print(List list){
	for (int i=0;i<list->count;i++)
		printf("%d ",list->pBase[i]);
	printf("\n");
}
//合并两个递增数组生成新的递增数组 归并思想
void MergeSort(List list1,List list2,List arr){
	int i,j;
	for (i=0,j=0;i<list1->count&&j<list2->count;arr->count++)
	{
		arr->pBase[arr->count] = list1->pBase[i] > list2->pBase[j] ? list2->pBase[j++] : list1->pBase[i++];
	}
	while(i<list1->count) arr->pBase[arr->count++] = list1->pBase[i++];
	while(j<list2->count) arr->pBase[arr->count++] = list2->pBase[j++];
}

int B_Search(List list1,List list2){
	int start1=0,
		end1=list1->count-1,
		start2=0,
		end2=list2->count-1,
		m1,
		m2;
	while (start1 != end1 || start2 !=end2)
	{
		m1=(start1+end1)/2;
		m2=(start2+end2)/2;
		if(list1->pBase[m1] == list2->pBase[m2])
			return list1->pBase[m1];
		else if (list1->pBase[m1] < list2->pBase[m2])
		{
			start1 = (start1+end1)%2 == 0 ? m1:m1+1;
			end2 = m2;

		}else{
			end1 = m1;
			start2 = (start1+end1)%2 == 0 ? m2:m2+1;
			//start2 = (start2+end2)%2 == 0 ? m2:m2+1;
		}
	}
	return list1->pBase[start1] < list2->pBase[start2] ? list1->pBase[start1] : list2->pBase[start2];
}

void main(){
	L arr1;
	L arr2;
	L arr;
	InitList(&arr1,5);
	PushList(&arr1,1);
	PushList(&arr1,2);
	PushList(&arr1,3);
	PushList(&arr1,4);
	InitList(&arr2,8);
	PushList(&arr2,5);
	PushList(&arr2,6);
	PushList(&arr2,7);
	PushList(&arr2,8);
	PushList(&arr2,9);
	PushList(&arr1,10);
	InitList(&arr,arr1.count+arr2.count);
	//MergeSort(&arr1,&arr2,&arr);
	int m = B_Search(&arr1,&arr2);
	printf("%d ",m);
	//Print(&arr1);
	//Print(&arr2);
	//Print(&arr);

}