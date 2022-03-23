#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<string> v(m);
	for(auto &x: v){
		cin >> x;
	}
	if(m == 1){
		cout << v[0];
		return 0;
	}
	int cnt;
	for(int i=0; i<m - 1; ++i){
		cnt = 0;
		for(int j=0; j<n; ++j){
			if(v[i][j] != v[i + 1][j]){
				cnt++;
			}
			if(cnt > 2){
				cout << v[i] << "\n";
				return 0;
			}
		}
	}
	cout << v[m - 1];
	return 0;
}
