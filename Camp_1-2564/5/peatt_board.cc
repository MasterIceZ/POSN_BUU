#include <bits/stdc++.h>
using namespace std;

const int MxN = 1010;
int table[MxN][MxN];

int main(){
	int n, m, q;
	scanf("%d %d %d", &m, &n, &q);
	while(q--){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		table[b][a] ^= 1;
		table[d + 1][a] ^= 1;
		table[b][c + 1] ^= 1;
		table[d + 1][c + 1] ^= 1;
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			table[i][j] ^= table[i - 1][j] ^ table[i][j - 1] ^ table[i - 1][j - 1];
			printf("%d", table[i][j]);
		}
		printf("\n");
	}
	return 0;
}
