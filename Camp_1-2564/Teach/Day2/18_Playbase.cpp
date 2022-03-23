#include<stdio.h>
#include<ctype.h>
#include<string.h>

char a[300], b[300];
char ans[300];
int base;
int convert(char s[]) {
	int n = strlen(s);
	int num=0;
	for(int i=0; i<n; i++) {
		num *= base;
		if(isdigit(s[i])) num += s[i]-'0';
		else num += s[i]-'A'+10;
	}
	return num;
}
int main() {
	scanf("%d %s %s", &base, a, b);
	int numA=convert(a), numB=convert(b);
	int sum = numA + numB;
	printf("%d\n", sum);
	int i;
	for(i=0; sum!=0; i++) {
		int now = sum%base;
		if(now>=10) ans[i] = now-10+'A';
		else ans[i] = now+'0';
		sum/=base;
	}
	for(i--; i>=0; i--) {
		printf("%c", ans[i]);
	}
	return 0;
}
