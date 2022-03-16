#include <bits/stdc++.h>
using namespace std;

int n, r, k;
int a[14], cnt;
bitset<14> visited;

void rec(int state){
	if(state == r){
		cnt++;
		if(cnt == k){
			for(int i=0; i<state; ++i){
				cout << a[i] << " " ;
			}
			exit(0);
		}
		return ;
	}
	for(int i=1; i<=n; ++i){
		if(!visited[i]){
			visited[i] = true;
			a[state] = i;
			rec(state + 1);
			visited[i] = false;
		}
	}
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> r >> k;
	rec(0);
	return 0;
}
