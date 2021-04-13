#include<bits/stdc++.h>
using namespace std;

int n, m;
char a[111][1111];
int cnt;

const int di[] = {-1,0,0,1}, dj[] = {0,-1,1,0};

void rec(int i, int j){
	a[i][j] = '.';
	cnt++;
	for(int k=0; k<4; ++k){
		int ii = i + di[k], jj = j + dj[k];
		if(ii<0 || jj<0 || ii>=n || jj>=m || a[ii][jj]=='.'){
			continue;
		}
		rec(ii, jj);
	}
}

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cin >> a[i][j];
		}
	}
	int nax = -1e9;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(a[i][j] == '*'){
				cnt = 0;
				rec(i, j);
//				cout << "DEBUG : " << cnt << endl;
				nax = max(cnt, nax);
			}
		}
	}
	cout << nax;
	return 0;
}
