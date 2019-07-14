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
		printf("内存空间分配失败\n");
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
	for (int i=0;i<list->length;i++)
		printf("%d ",list->pBase[i]);
	printf("\n");
}


//查找到值返回索引值，查找失败返回-1
int BinarySearch(List list,ElementType x){
	int low=0,
		high=list->count-1,
		mid;
	while (low<=high)
	{
		mid = (low+high)/2;
		if(list->pBase[mid] == x) return mid;       //x和中值相等
		else if(list->pBase[mid] < x) low = mid+1; //x在中值的右边
		else high = mid-1;						  //x在中值的左边
		
	}
	return -1;
	
}
//递归版
int BinarySearchRecursion(List list,ElementType x,int low, int high){
	int mid = (low+high)/2;
	//printf("%d ",mid);
	if(low > high){
		return -1;
	}
	if(list->pBase[mid] < x){
		return BinarySearchRecursion(list,x,mid+1,high); //x在中值的右边
	}else if(list->pBase[mid] > x){
		return BinarySearchRecursion(list,x,low,mid-1);	//x在中值的左边
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