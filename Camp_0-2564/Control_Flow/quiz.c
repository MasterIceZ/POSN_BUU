#include <stdio.h>

const int MxN = 1010;
char a[MxN][MxN];

int main(){
	int n, cnt = 1, cnt2 = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=i; ++j){
			a[i][j] = cnt2 + 'A';
			cnt2 = (cnt2 + 1) % 26;
		}
		for(int j=i+1; j<=n; ++j){
			a[i][j] = '0' + (cnt % 10);
			cnt++;
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=n; j>=1; --j){
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
