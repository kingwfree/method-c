#include <stdio.h>

void InsertSort(int arr[],int len){
	int i,j,tmp;
	for (i=1;i<len;i++)
	{
		tmp = arr[i];
		for (j=i;j>0 && arr[j-1]>tmp;j--)
		{
			arr[j] = arr[j-1];
		}
		arr[j] = tmp;
	}
}
void Print(int arr[],int len){
	int i;
	for (i=0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}
}
void main(){
	int arr[6] = {5,6,2,3,1,4};
	InsertSort(arr,6);
	Print(arr,6);
}