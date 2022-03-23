#include<stdio.h>
#include<string.h> // strlen
#include<math.h> // pow
#include<stdlib.h> // atol

char a[6];
int main() {
	int q=5;
	while(q--) {
		scanf(" %s", a);
		int len = strlen(a);
		int num = atoi(a), num2=0;
		for(int i=0; i<len; i++) {
			num2 += pow(a[i]-'0', i+1);
		}
		if(num == num2) printf("Y");
		else printf("N");
	}
	return 0;
}
