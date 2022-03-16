#include <bits/stdc++.h>
using namespace std;

int a[5], visited[33][33][33];
bool answer[33];

inline bool check(int b[]){
	for(int i=0; i<3; ++i){
		if(a[i] < b[i] || b[i] < 0){
			return false;
		}
	}
	return true;
}

void rec(int b[]){
	if(!check(b)){
		return ;
	}
	if(b[0] == 0){
		answer[b[2]] = true;
	}
	if(visited[b[0]][b[1]][b[2]]){
		return ;
	}
	visited[b[0]][b[1]][b[2]] = true;
	int c[4] = {};
	// i -> j
	for(int i=0; i<3; ++i){
		for(int j=0; j<3; ++j){
			if(i == j){
				continue;
			}
			c[i] = 0;
			c[j] = b[i] + b[j];
			c[3 - i - j] = b[3 - i - j];
			rec(c);
			c[i] = b[i] - (a[j] - b[j]);
			c[j] = a[j];
			rec(c);
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> a[0] >> a[1] >> a[2];
	int tmp[] = {0, 0, a[2]};
	rec(tmp);
	for(int i=0; i<=a[2]; ++i){
		if(answer[i]){
			cout << i << " ";
		}
	}
	return 0;
}
