#include <stdio.h>
#include <string.h>

const int MxN = 200020;
char a[2 * MxN], b[2 * MxN], c[2 * MxN];
char swp[2 * MxN];

int isMinus(char a[]){
	if(a[0] != '-'){
		return 0;
	}
	strcpy(swp, a);
	strcpy(a, &swp[1]);
	return 1;
}

int main(){
	scanf(" %s %s", a, b);
	int isMinus_A = isMinus(a);
	int isMinus_B = isMinus(b);
	if(a[0] == '0' || b[0] == '0'){
		printf("0");
		return 0;
	}
	int lena = strlen(a), lenb = strlen(b);
	memset(c, 0, sizeof c);
	for(int i=lena-1; i>=0; --i){
		for(int j=lenb-1; j>=0; --j){
			int t = (a[i] - '0') * (b[j] - '0') + c[i + j + 1];
			c[i + j + 1] = t % 10;
			c[i + j] += t / 10;
		}
	}
	int ch = 0;
	if(isMinus_A ^ isMinus_B){
		printf("-");
	}
	for(int i=0; i<lena+lenb; ++i){
		while(!ch){
			if(c[i]){
				ch = 1;
				break;
			}
			i++;
		}
		printf("%d", c[i]);
	}
	printf("\n");
	return 0;
}
