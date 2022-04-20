/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_MagicHat
 * ALGO		: Data Structure
 * DATE		: 17 Apr 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Hat{
	int w, v, d, i;
	bool operator < (const Hat& o) const{
		return w > o.w;
	}
};

struct Timer{
	int w, v, d, i;
	bool operator < (const Timer& o) const{
		return d > o.d;
	}
};

priority_queue<Hat> hat;
priority_queue<Timer> timer;
bool used[200200];

void solve(){
	int opr, opr2, n, m, w, v, d, x;
	cin >> n >> m;
	for(int i=0; i<n+m; ++i){
		cin >> opr;
		if(opr == 1){
			cin >> opr2;
			if(opr2 == 1){
				cin >> w >> v;
				hat.push({w, v, 200200, i});
			}
			else if(opr2 == 2){
				cin >> w >> v >> d;
				hat.push({w, v, d, i});
			}
			else{
				cin >> w >> v >> d >> x;
				hat.push({w, v, d, i});
				timer.push({x, v, d, i});
			}
		}
		else{
			while(!timer.empty() && timer.top().d <= i){
				hat.push({timer.top().w, timer.top().v, 200200, timer.top().i});
				timer.pop();
			}
			bool printed = false;
			while(!hat.empty()){
				if(hat.top().d <= i || used[hat.top().i]){
					hat.pop();
					continue;
				}
				used[hat.top().i] = true;
				cout << hat.top().v << "\n";
				hat.pop();
				printed = true;
				break;
			}
			if(!printed){
				cout << 0 << "\n";
			}
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
