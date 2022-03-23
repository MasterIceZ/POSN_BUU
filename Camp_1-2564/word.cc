#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

char a[33][33], s[22];
int len, n, m;

inline bool walk(int k, int i, int j){
	int cnt = 0;
	while(cnt < len){
//		cout << (char) a[i + di[j] * cnt][j + dj[j] * cnt] << " " << (char) s[1 + cnt] << "\n";
		int ii = i + di[k] * cnt;
		int jj = j + dj[k] * cnt;
		if(ii < 1 || jj < 1 || ii > n || jj > m || a[ii][jj] != s[1 + cnt]){
			return false;
		}
		cnt++;
	}
	return true;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			a[i][j] = tolower(a[i][j]);
		}
	}
	cin >> q;
	while(q--){
		cin >> (s + 1);
		bool ok = false;
		::len = strlen(s + 1);
		for(int i=1; i<=len; ++i){
			s[i] = tolower(s[i]);
		}
		for(int i=1; i<=n && !ok; ++i){
			for(int j=1; j<=m && !ok; ++j){
//				cout << "X : " << i << " " << j << "\n";
				if(a[i][j] == s[1]){
					for(int state=0; state<8 && !ok; ++state){
						ok = walk(state, i, j);
						if(ok){
							cout << i - 1 << " " << j - 1 << "\n";
						}
					}
				}
			}
		}
		if(!ok){
			cout << "-1\n";
		}
	}
	return 0;
}
