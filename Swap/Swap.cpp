#include <stdio.h>

typedef int ElementType;

void Swap(ElementType* a,ElementType* b){
	ElementType t;
	t=*a;
	*a=*b;
	*b=t;
}

void main(){
	ElementType a=1;
	ElementType b=2;
	Swap(&a,&b);
	printf("%d %d ",a,b);
}