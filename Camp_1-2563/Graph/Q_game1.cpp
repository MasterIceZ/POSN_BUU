#include<bits/stdc++.h>
using namespace std;

int a[555][555], cnt[3333];
int dist[555][555];
const int di[] = {-1, 0}, dj[] = {0, 1};

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = -1;
	queue<pair<int, int>>q;
	int r, c;
	cin >> r >> c;
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			cin >> a[i][j];
		}
	}
	q.emplace(r-1, 0);
	memset(dist, -1, sizeof dist);
	dist[r-1][0] = 0;
	while(!q.empty()){
		auto now = q.front();
		int i = now.first, j = now.second;
		q.pop();
		if(i==0 || j == c-1){
			break;
		}
		for(int k=0; k<2; ++k){
			int ii = di[k] + i, jj = dj[k] + j;
			if(ii<0 || jj<0 || ii>=r || jj>=c){
				continue;
			}
			if(a[ii][jj] == 1){
				continue;
			}
			if(dist[ii][jj] != -1){
				continue;
			}
			ans++;
			dist[ii][jj] = dist[i][j]+1;
			cnt[dist[ii][jj]]++;
			q.emplace(ii, jj);
		}
	}
	for(int i=0; i<=r*c; ++i){
		ans += cnt[i] * (cnt[i]-1);
	}
	cout << ans << endl;

	return 0;
}
