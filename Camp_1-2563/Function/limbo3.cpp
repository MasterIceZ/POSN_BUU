#include<bits/stdc++.h>
using namespace std;

int n, m;
char a[111][1111];
int cnt;

const int di[] = {-1,0,0,1}, dj[] = {0,-1,1,0};

void rec(int i, int j){
	if(a[i][j] == '.'){
		return ;
	}
	a[i][j] = '.';
	for(int k=0; k<4; ++k){
		int ii = i + di[k], jj = j + dj[k];
		rec((ii+n)%n, (jj+m)%m);
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
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(a[i][j] == '*'){
				rec(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
