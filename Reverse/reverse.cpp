#include <stdio.h>

//逆置数组
/*
	arr 要逆置的数组的首地址
	逆置的范围[f,t];（包括起始索引和结束索引）
	f   起始索引
	t	结束索引
*/
void Reverse(int* arr,int f,int t){
	int i,tmp;
	for (i=0;i<(t-f+1)/2;i++)
	{
		tmp = arr[f+i];
		arr[f+i] = arr[t-i];
		arr[t-i] = tmp;
	}
}
//打印数组
void Print(int* arr){
	int i;
	for (i=0;i<6;i++)
	{
		printf("%d ",arr[i]);
	}
}
void main(void){
	int arr[6] = {1,2,3,4,5,6};
	Reverse(arr,0,3);
	Print(arr);
}