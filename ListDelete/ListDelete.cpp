#include <stdio.h>

typedef struct Lis{
	int data[6];
	int length;
}L,*List;
/*
	删除指定的值
	x   指定的值
	L   要操作的对象
*/
void ListDelete(List L,int x){
	int i,k=0;
	for (i=0;i<L->length;i++)
	{
		if(L->data[i] != x){
			L->data[k] = L->data[i];
			k++;
		}
	}
	L->length = k;
}
void Print(List list){
	int i;
	for (i=0;i<list->length;i++)
	{
		printf("%d ",list->data[i]);
	}
}
void main(){
	L li={{1,3,3,4,5,6},6};
	ListDelete(&li,3);
	Print(&li);

}