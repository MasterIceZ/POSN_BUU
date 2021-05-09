/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: 48_Table
 * ALGO		: Heap
 * DATE		: 6 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

struct A{
	int x, y, v, i;
	bool operator < (const A& o) const{
		return v > o.v;
	}
};
priority_queue<A>pq;
pair<int, int> a[333][5555];

void solve(){
	int r, c, m;
	cin >> r >> c >> m;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			pq.push({i, j, 0, 0});
		}
	}
	int opr, x, y, v;
	for(int i=1; i<=m; ++i){
		cin >> opr;
		if(opr == 1){
			cin >> x >> y >> v;
			a[x][y] = make_pair(v, i);
			pq.push({x, y, v, i});
		}
		else if(opr == 2){
			cin >> x >> v;
			a[x][0] = make_pair(v, i);
			pq.push({x, 0, v, i});
		}
		else if(opr == 3){
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
					bool mkr = false;
					if(a[now.x][0].second > now.i){
						pq.pop();
						continue;
					}
					for(int j=1; j<=r; ++j){
						if(a[now.x][j].second < now.i){
							mkr =  true;
							break;
						}
					}
					if(!mkr){
						pq.pop();
						continue;
					}
					cout << now.v << endl;
					break;
				}
				else{
					if(a[now.x][now.y].second > now.i || a[now.x][0].second > now.i){
						pq.pop();
						continue;
					}
					cout << now.v << endl;
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
