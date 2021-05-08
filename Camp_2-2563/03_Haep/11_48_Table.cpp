/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: 48_Table
 * DATE		: 6 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;


pair<int, int> a[333][5555];

struct A{
	int x, y, val, idx;
	bool operator < (const A& o) const{
		return val > o.val;
	}
};

priority_queue<A>pq;

void solve(){
	int r, c, m;
	cin >> r >> c >> m;
	for(int i=1; i<=c; ++i){
		for(int j=1; j<=r; ++j){
			pq.push({i, j, 0, 0});
		}
	}
	for(int i=1, opr; i<=m; ++i){
		cin >> opr;
		if(opr == 1){
			int x, y, v;
			cin >> x >> y >> v;
			a[x][y] = {v, i};
			pq.push({x, y, v, i});
		}
		else if(opr == 2){
			int x, v;
			cin >> x >> v;
			a[x][0] = {v, i};
			pq.push({x, 0, v, i});
		}
		else if(opr == 3){
			int x, y;
			cin >> x >> y;
			if(a[x][0].second > a[x][y].second){
				cout << a[x][0].first << endl;
			}
			else{
				cout << a[x][y].first << endl;
			}
		}
		else{
			while(!pq.empty()){
				auto now = pq.top();
				if(now.y == 0){
					if(a[now.x][0].second > now.idx){
						pq.pop();
						continue;
					}
					bool ch = false;
					for(int j=1; j<=c; ++j){
						if(now.idx > a[now.x][j].second){
							ch = true;
							break;
						}
					}
					if(!ch){
						pq.pop();
						continue;
					}
					cout << now.val << endl;
					break;
				}
				else{
					if(a[now.x][now.y].second > now.idx || a[now.x][0].second > now.idx){
						pq.pop();
						continue;
					}
					cout << now.val << endl;
					break;
				}
			}
		}
	}
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
