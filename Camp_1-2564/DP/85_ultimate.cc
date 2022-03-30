#include <bits/stdc++.h>
using namespace std;

const int MxN = 1010;
char a[MxN][MxN];
int dp[MxN][MxN];

signed main(){
	int n, m, maxx = 0;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			scanf(" %c", &a[i][j]);
			if(a[i][j] == '#'){
				continue;
			}
			dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
			maxx = max(maxx, dp[i][j]);
		}
	}
	printf("%d\n", maxx);
	return 0;
}
