#include <stdio.h>

typedef int ElementType;

typedef struct ListData{
	ElementType data[6];
	int length;
}L,*List;
//�������˳����ȥ��
bool DeleteSame(List L){
	if(L->length == 0)return false;
	int i,j;
	//�������� ����Ԫ��֮�������Ƚ�
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