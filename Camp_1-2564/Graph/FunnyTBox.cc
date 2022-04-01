#include <bits/stdc++.h>
using namespace std;

const int MxN = 33;

struct Box{
	pair<int, int> ul, dr;
	Box(int a, int b, int c, int d){
		ul = make_pair(a, b);
		dr = make_pair(c, d);
	}
	Box operator + (pair<int, int> dx) const {
		return Box(ul.first + dx.first, ul.second + dx.second, ul.first + dx.first + 1, ul.second + dx.second + 1);
	}
};

const pair<int, int> dx[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
int n, m;
char a[MxN][MxN];
bool visited[MxN][MxN];

inline bool check(int x, int rx){
	return (1 <= x && x <= rx);
}

inline bool valid(int x_1, int y_1, int x_2, int y_2){
	bool ok = (check(x_1, n) && check(x_2, n) && check(y_1, m) && check(y_2, m));
	if(!ok){
		return false;
	}
	for(int i=x_1; i<=x_2; ++i){
		for(int j=y_1; j<=y_2; ++j){
			ok &= (a[i][j] == '.');
		}
	}
	return ok;
}

inline bool valid(Box x){
	return valid(x.ul.first, x.ul.second, x.dr.first, x.dr.second);
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	queue<Box> q;
	for(int j=1; j<m; ++j){
		if(valid(1, j, 2, j + 1)){
			visited[1][j] = true;
			q.emplace(1, j, 2, j + 1);
		}
	}
	bool printed = false;
	while(!q.empty()){
		Box now = q.front();
		q.pop();
		if(now.dr.first == n){
			printed = true;
			cout << "yes";
			break;
		}
		for(int k=0; k<4; ++k){
			Box nxt = now + dx[k];
			if(!valid(nxt) || visited[nxt.ul.first][nxt.ul.second]){
				continue;
			}
			visited[nxt.ul.first][nxt.ul.second] = true;
			q.emplace(nxt);
		}
	}
	if(!printed){
		cout << "no";
	}
	cout << "\n";
	return 0;
}
