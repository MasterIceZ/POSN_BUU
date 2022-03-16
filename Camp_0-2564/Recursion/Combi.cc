#include <bits/stdc++.h>
using namespace std;

int n, r, k;
int a[12], cnt;
bitset<12> visited;

void rec(int state, int last){
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
	for(int i=last; i<=n; ++i){
		if(!visited[i]){
			visited[i] = true;
			a[state] = i;
			rec(state + 1, i);
			visited[i] = false;
		}
	}
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> r >> k;
	rec(0, 1);
	return 0;
}
