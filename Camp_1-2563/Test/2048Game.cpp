#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int n, m;

vector<int>v[22];

void solve(){
	cin >> n;	
	string s;
	cin >> s;
	if(s=="right" || s=="left"){
		for(int i=1; i<=n; ++i){
			vector<int>tmp;
			for(int j=1; j<=n; ++j){
				int x;
				cin >> x;
				if(x){
					tmp.push_back(x);
				}
			}
			if(s == "left"){
				reverse(tmp.begin(), tmp.end());
			}
			while(!tmp.empty()){
				int now = tmp.back();
				tmp.pop_back();
				v[i].push_back(now);
				if(tmp.empty()){
					break;
				}
				if(tmp.back() == now){
					v[i].back() *= 2;
					tmp.pop_back();
				}
			}
			while(v[i].size() < n){
				v[i].push_back(0);
			}
			if(s == "right"){
				reverse(v[i].begin(), v[i].end());
			}
		}
	}
	else{
		for(int j=1; j<=n; ++j){
			vector<int>tmp;
			for(int i=0; i<=n; ++i){
				int x;
				cin >> x;
				if(x){
					tmp.push_back(x);
				}
			}	
			if(s == "up"){
				reverse(tmp.begin(), tmp.end());
			}
			int ptr = 1;
			while(!tmp.empty()){
				int now = tmp.back();
				tmp.pop_back();
				v[ptr++].push_back(now);
				if(tmp.empty()){
					break;
				}
				if(tmp.back() == now){
					v[ptr-1].back() *= 2;
					tmp.pop_back();
				}
			}
			while(ptr<=n){
				v[ptr++].push_back(0);
			}
			if(s == "down"){
				reverse(v[ptr].begin(), v[ptr].end());
			}
		}
	}

	for(int i=1; i<=n; ++i){
		for(auto a: v[i]){
			cout << a << " ";
		}
		cout << endl;
	}
	return ;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
//	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}

	return 0;
}
