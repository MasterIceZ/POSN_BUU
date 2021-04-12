/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * LANG		: C++
 * TASK		: 
 * EDITOR	: VsCode
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solution(){
	int g, k;
	cin >> g >> k;
	int player=1,  cnt = 0;
	while(g-player*100 > 0){
		g -= 10;
		player += k;
		player--, cnt++;
	}
	cout << cnt;
	return ;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int i=1; i<=t; ++i){
//		cout << "Case #" << i << ": ";
		solution();
		cout << endl;
	}
	return 0;
}
