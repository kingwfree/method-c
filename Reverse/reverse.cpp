#include <stdio.h>

//��������
/*
	arr Ҫ���õ�������׵�ַ
	���õķ�Χ[f,t];��������ʼ�����ͽ���������
	f   ��ʼ����
	t	��������
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
//��ӡ����
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