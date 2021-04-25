#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int n, m;

void solve(){
	int x, y, z;
	cin >> x >> y >> z;
	vector<int>v;
	while(x--){
		v.push_back(1);
		v.push_back(-1);
	}
	while(y--){
		v.push_back(2);
		v.push_back(-2);
	}
	while(z--){
		v.push_back(3);
		v.push_back(-3);
	}
	int cnt = 0;
	do{
		stack<int>st;
		cnt++;
		for(auto x:v){
			if(x>0){
				st.push(x);
			}
			else{
				if(!st.empty() && st.top() == -x){
					st.pop();
				}
				else{
					cnt--;
					break;
				}
			}
		}
	}while(next_permutation(v.begin(), v.end()));
	cout << cnt;
	return ;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}

	return 0;
}
