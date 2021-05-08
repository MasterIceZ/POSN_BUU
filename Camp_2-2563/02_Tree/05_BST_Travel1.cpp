/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: BST Travel 1
 * ALGO		: Depth First Search + Breadth First Search
 * DATE		: 6 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;
int a[1 << 23];

void pr(int i){
	if(!a[i]){
		return ;
	}
	cout << a[i] << " ";
	pr(2*i);
	pr(2*i+1);
}

void po(int i){
	if(!a[i]){
		return ;
	}
	po(i*2);
	po(i*2+1);
	cout << a[i] << " ";
}

void in(int i){
	if(!a[i]){
		return ;
	}	
	in(2*i);
	cout << a[i] << " ";
	in(2*i+1);
}

void bfs(int i){
	for(int i=1; i< 1<<23; ++i){
		if(a[i]){
			cout << a[i] << " ";
		}
	}
}

void solve(){
	string s;
	cin >> s;
	int n;
	cin >> n;
	for(int i=0, x; i<n; ++i){
		cin >> x;
		int ptr = 1;
		while(a[ptr] != 0){
			if(x < a[ptr]){
				ptr = 2 * ptr;
			}
			else{
				ptr = 2 * ptr + 1;
			}
		}
		a[ptr] = x;
	}
	if(s == "PRE"){
		pr(1);
	}
	else if(s == "POS"){
		po(1);
	}
	else if(s == "INF"){
		in(1);
	}
	else{
		bfs(1);
	}
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
