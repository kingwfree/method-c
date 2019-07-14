#include <stdio.h>

typedef int ElementType;

typedef struct ListData{
	ElementType data[6];
	int length;
}L,*List;
//针对有序顺序表的去重
bool DeleteSame(List L){
	if(L->length == 0)return false;
	int i,j;
	//从左往右 相邻元素之间两两比较
	for (i=0,j=1;j<L->length;j++)
	{
		if(L->data[i] != L->data[j]){
			L->data[++i] = L->data[j];
		}
	}
	
	L->length = i+1;
	return true;
}

void Print(List list){
	int i;
	for (i=0;i<list->length;i++)
	{
		printf("%d ",list->data[i]);
	}
}

void main(void){
	L list = {{1,2,2,3,3,4},6};
	DeleteSame(&list);
	Print(&list);
}