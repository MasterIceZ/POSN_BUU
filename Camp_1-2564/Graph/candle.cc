#include <bits/stdc++.h>
using namespace std;

using ll = long long;

typedef struct{
	int i, j;
} cell_t;

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};
const int MxN = 2020;

char a[MxN][MxN];
queue<cell_t> q;

void play(int i, int j){

}

signed main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			scanf(" %c", &a[i][j]);
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == '1'){
				cnt++;
				play(i, j);
			}
		}
	}
	return 0;
}
