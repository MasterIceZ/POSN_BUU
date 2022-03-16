#include <bits/stdc++.h>
using namespace std;

const int MxN = 1000010;
int a[MxN], nxt[MxN], from[MxN];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	memset(nxt, -1, sizeof nxt);
	memset(from, -1, sizeof from);
	for(int i=2, u, v; i<=n; ++i){
		cin >> u >> v;
		int it = u;
		while(1){
			if(nxt[it] != -1){
				it = nxt[it];
			}
			else{
				nxt[it] = v;
				from[v] = it;
				break;
			}
		}
	}
	stack<int> answer;
	for(int i=1; i<=n; ++i){
		if(nxt[i] == -1){
			int it = i;
			while(1){
				answer.push(it);
				if(from[it] == -1){
					break;
				}
				it = from[it];
			}
			break;
		}
	}
	while(!answer.empty()){
		cout << a[answer.top()] << " ";
		answer.pop();
	}
	cout << "\n";
	return 0;
}
