#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
char a[1010][88];
bool visited[1010][88];

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

void walk(int i, int j){
//	cerr << "X " << i << " " << j << "\n";
	cnt++;
	for(int k=0; k<4; ++k){
		int ii = di[k] + i; // next_i
		int jj = dj[k] + j; // next_j 
		if(ii < 1 || jj < 1 || ii > n || jj > m){
			continue;
		}
		if(a[ii][jj] != '*' || visited[ii][jj]){
			continue;
		}
//		visited[ii][jj] = true;
		walk(ii, jj);
	}
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> m >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	int res = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == '*'){
				cnt = 0;
				visited[i][j] = true;
				walk(i, j);
				res = max(cnt, res);
			}
		}
	}
	cout << res << "\n";
	return 0;
}
