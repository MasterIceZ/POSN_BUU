#include<bits/stdc++.h>
using namespace std;

set<int>s;
int a[10][10];
int n = 5;

const int di[] = {-1,0,0,1}, dj[] = {0,-1,1,0};

void rec(int i, int j, int state, int num){
	num += a[i][j];
	if(state == 5){
		s.insert(num);
		return;
	}
	for(int k=0; k<4; ++k){
		int ii = i + di[k], jj = j + dj[k];
		if(ii<0 || jj<0 || ii>=n ||jj>=n){
			continue;
		}
		num *= 10;
		rec(ii, jj, state+1, num);
		num /= 10;
	}
}

void solution(){
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin >> a[i][j];
		}
	}
	for(int i=0; i<5; ++i){
		for(int j=0; j<5; ++j){
			rec(i, j, 0, 0);
		}
	}
//	for(auto x = s.begin(); x != s.end(); ++x){
//		cout << *x << " " ;
//	}
//	cout << endl;
	cout << s.size();
}

int32_t main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		solution();
		cout << endl;
		s.clear();
	}
	
	return 0;
}
