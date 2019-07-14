#include <stdio.h>

int Majority(int arr[],int len){
	int c=arr[0],i,count=0;
	for (i=0;i<len;i++)
	{
		if (c == arr[i])
		{
			count++;
		}else{
			count--;
			if(count == 0){
				c = arr[i];
				count = 1;
			}
		}
	}
	if (count > 0)
	{
		count = 0;
		for (i=0;i<len;i++)
		{
			if(c == arr[i]){
				count++;
			}
		}
	}
	if (count > len/2)
	{
		return c;
	}else{
		return -1;
	}
	
}
void main(){
	int arr[7] = {1,1,2,1,2,2,3};
	int main = Majority(arr,7);
	printf("%d ",main);
}