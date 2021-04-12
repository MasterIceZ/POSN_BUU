#include<stdio.h>

int main (){
	int a[8]={1,3,5,4,7,9,10,2},*pa;
	pa = &a[0];
	
	printf("%d",*a);
	printf("%d\n",*pa++);
	printf("%d\n",*++pa);
	printf("%d\n",(*a)+2);
	printf("%d\n",(*pa)++);
	printf("%d\n",++*pa);
	printf("%d\n",(*pa+2));
	printf("%d\n",pa[3]);
	*pa +=a[5];printf("%d\n",*pa);
	pa[1] = *pa+3;printf("%d\n",pa[1]); 
	
}
