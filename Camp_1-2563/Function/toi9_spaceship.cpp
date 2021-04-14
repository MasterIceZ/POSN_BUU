#include<bits/stdc++.h>
using namespace std;

struct space{
	int x, y, z, a, b, c;
} ship[22];
bool visited[22];
int k, sx, sy, sz, n, ans;

int pp(int x){
	return x*x;
}

void rec(int c, int m, int kk, int cc, int x, int y, int z){
	for(int i=0; i<n; ++i){
		if(visited[i]){
			continue;
		}
		visited[i] = true;
		int cost = c+pp(x-ship[i].x)+pp(y-ship[i].y)+pp(z-ship[i].z);
		if(m+ship[i].a >=k && kk+ship[i].b >= k && cc+ship[i].c >= k){
			ans = min(ans, cost);
		}
		else{
			rec(cost, m+ship[i].a, kk+ship[i].b, cc+ship[i].c, ship[i].x, ship[i].y, ship[i].z);
		}
		visited[i] = false;
	}
}	

int main (){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ans = 1e9+2;
	cin >> k >> sx >> sy >> sz >> n;
	for(int i=0; i<n; ++i){
		cin >> ship[i].x >> ship[i].y >> ship[i].z >> ship[i].a >> ship[i].b>> ship[i].c;
	}
	rec(0, 0, 0, 0, sx, sy, sz);
	cout << ans;

	return 0;
}
