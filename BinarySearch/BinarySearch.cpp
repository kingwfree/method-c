#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct ListData{
	ElementType *pBase;
	int length;
	int count;
}L,*List;

void InitList(List list,int len){
	int i;
	list->pBase = (ElementType *)malloc(len*sizeof(ElementType));
	if(list == NULL){
		printf("�ڴ�ռ����ʧ��\n");
		exit(-1);
	}
	list->length=len;
	list->count=0;
	for (i=0;i<list->length;i++)
	{
		list->pBase[i]=0;
	}
}
bool isFull(List list){
	bool flag = list->count == list->length?true:false;
	return flag;
}
//����ֵ
bool PushList(List list,int value){
	if(isFull(list)){
		printf("��������!\n");
		return false;
	}else{
		list->pBase[list->count] = value;
		list->count++;
		return true;
	}
}
void Print(List list){
	for (int i=0;i<list->length;i++)
		printf("%d ",list->pBase[i]);
	printf("\n");
}


//���ҵ�ֵ��������ֵ������ʧ�ܷ���-1
int BinarySearch(List list,ElementType x){
	int low=0,
		high=list->count-1,
		mid;
	while (low<=high)
	{
		mid = (low+high)/2;
		if(list->pBase[mid] == x) return mid;       //x����ֵ���
		else if(list->pBase[mid] < x) low = mid+1; //x����ֵ���ұ�
		else high = mid-1;						  //x����ֵ�����
		
	}
	return -1;
	
}
//�ݹ��
int BinarySearchRecursion(List list,ElementType x,int low, int high){
	int mid = (low+high)/2;
	//printf("%d ",mid);
	if(low > high){
		return -1;
	}
	if(list->pBase[mid] < x){
		return BinarySearchRecursion(list,x,mid+1,high); //x����ֵ���ұ�
	}else if(list->pBase[mid] > x){
		return BinarySearchRecursion(list,x,low,mid-1);	//x����ֵ�����
	}
	return mid;
}

void ExchangeInsert(List list,int pos,ElementType x){
	int tmp,i;
	if(pos != -1 && pos != list->count-1){
		tmp = list->pBase[pos];
		list->pBase[pos] = list->pBase[pos+1];
		list->pBase[pos+1] = tmp;
	}
	if(pos == -1){
		for (i=list->count-1;list->pBase[i]>x;i--)
		{
			list->pBase[i+1] = list->pBase[i];
		}
		//printf("%d ",i);
		list->pBase[++i] = x;
		list->count++;
	}
}


void main(void){
	L list;
	InitList(&list,6);
	PushList(&list,1);
	PushList(&list,2);
	PushList(&list,3);
	PushList(&list,4);
	PushList(&list,5);
	int low=0,
		high=list.count;
	//int mid = BinarySearchRecursion(&list,7,low,high);
	int mid = BinarySearch(&list,2);
	//printf("%d ",mid);
	//printf("%d %d ",low,high);
	ExchangeInsert(&list,mid,2);
	Print(&list);

}