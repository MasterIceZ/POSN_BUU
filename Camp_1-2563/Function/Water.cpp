#include<bits/stdc++.h>
using namespace std;

int n, t, cnt;
int a[11], tmp[22];
int ans[100100][111];

void rec(int state, int sum){
	if(state == t + 1){
		return ;
	}
	if(sum == 0){
		ans[cnt][0] = state;
		for(int i=0; i<state; ++i){
			ans[cnt][i+1] = tmp[i];
		}
		cnt++;
		return ;
	}
	for(int i=1; i<=6; ++i){
		if(sum-a[i] < 0){
			continue;
		}
		tmp[state] = a[i];
		rec(state+1, sum-a[i]);
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> t;
	for(int i=1; i<=6; ++i){
		cin >> a[i];
	}
	rec(0, n);
	cout << cnt << "\nE\n";
	for(int i=0; i<cnt; ++i){
		for(int j=0; j<=ans[i][0]; ++j){
			cout << ans[i][j] << " " ;
		}
		cout << "\nE" << endl;
	}
	return 0;
}
