#include <stdio.h>
#include <math.h>

int a[15][15], b[15][15];

int main(){
	// n, m, r, c
	// n * c
	//
	// m == r
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=c; ++j){
			int answer = 0;
			for(int k=1; k<=m; ++k){
				answer += a[i][k] * b[k][j];
			}
			printf("%d ", answer);
		}
		printf("\n");
	}
	return 0;
}
