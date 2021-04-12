#include<stdio.h>
#include<math.h>
#include<string.h>

int gcd (int a,int b){
	if(a%b==0)
	return b;
	return gcd(b,a%b);
}

int main ()
{
    int a, b, c, prop=0;
    scanf("%d %d %d",&a,&b,&c);
    int x=gcd(a,b);
    if(c%x==0) printf("Yes");
    else		printf("No");
    return 0;
}
