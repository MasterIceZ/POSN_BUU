#include<bits/stdc++.h>
using namespace std;
char b[100];
int main () {
	int a,k;
	scanf("%d %d",&a,&k);
	sprintf(b,"%.0lf",a/pow(10,k));
	printf("%.0lf\n",atoi(b)*pow(10,k));
	return 0;
}
