#include<bits/stdc++.h>
using namespace std;

int a[20];
bool used[20];
int n, r, k, cnt;

void rec(int state, int start){
	if(state == r){
		cnt++;
		if(cnt == k){
			for(int i=0; i<state; ++i){
				cout << a[i] << " ";
			}
			exit(0);
		}
		return ;
	}
	for(int i=start; i<=n; ++i){
		if(!used[i]){
			used[i] = true;
			a[state] = i;
			rec(state+1, i);
			used[i] = false;
		}
	}
}	

int main (){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> r >> k;
	rec(0, 1);

	return 0;
}
