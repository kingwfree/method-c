#include <stdio.h>

#define cutoff 2
typedef int ElementType;

void Swap(ElementType* a,ElementType* b){
	ElementType tmp=*a;
	*a = *b;
	*b = tmp;
}

//������ֵ��
void InsertSort(ElementType arr[],int len){
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
ElementType Median3(ElementType arr[],int left,int right){
	int center = (left+right)/2;
	if (arr[center] > arr[left])
		Swap(&arr[center],&arr[left]);
	if(arr[center] < arr[right])
		Swap(&arr[center],&arr[right]);
	if(arr[left] > arr[right])
		Swap(&arr[left],&arr[right]);
	//printf("%d %d %d ",arr[left],arr[center],arr[right]);
	Swap(&arr[center],&arr[right-1]);
	return arr[right-1];
}
void QuickSort(ElementType arr[],int left,int right){
	if (cutoff >= right-left){
		ElementType pivot=Median3(arr,left,right),
			i=left,
			j=right-1;
		//printf("%d ",pivot);
		for (;;)
		{
			while(arr[++i] < pivot);
			while (arr[--j] > pivot);
			if(i < j){
				Swap(&arr[i],&arr[j]);
			}else break;
		}
		Swap(&arr[i],&arr[right-1]);
		QuickSort(arr,left,i-1);
		QuickSort(arr,i+1,right);
	}else InsertSort(arr+left,right-left+1);
	
}

//����
void quicksort(ElementType a[],int left,int right)
{
	int i,j,t,temp;
	if(left>=right)
		return;
	temp=a[left]; //temp�д�ľ��ǻ�׼��
	i=left;
	j=right;
	while(i!=j)
	{
		//˳�����Ҫ��Ҫ�ȴ���������
		while(a[j]>=temp && i<j)
			j--;
		//�ٴ���������
		while(a[i]<=temp && i<j)
			i++;
		//�����������������е�λ��
		if(i<j)//���ڱ�i���ڱ�jû������ʱ
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	//���ս���׼����λ 

	a[left]=a[i];
	a[i]=temp;
	
	quicksort(a,left,i-1);//����������ߵģ�������һ���ݹ�Ĺ���
	quicksort(a,i+1,right);//���������ұߵģ�������һ���ݹ�Ĺ���
} 



void Print(ElementType arr[],int len){
	int i;
	for (i=0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}
}
void main(){
	ElementType arr[6]={5,6,8,4,9,3};
	//quicksort(arr,0,5);
	//Median3(arr,0,5);
	QuickSort(arr,0,5);
	Print(arr,6);
	//int a=4;
	//printf("%d ",*(arr+a));
}
