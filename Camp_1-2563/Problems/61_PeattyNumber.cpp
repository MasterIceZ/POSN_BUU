#include<bits/stdc++.h>
using namespace std;

#define int long long

int pp(int n, int p){
	return p==0?1:n*pp(n,p-1);
}

void seven(string s){
	int pt = 0, tmp = 0;
	vector<int>v;
	for(int i=s.size()-1; i>=0; --i){
		tmp *= pp(10, pt);
		int now = s[i] - '0';
		pt++;
		tmp += now;
		if(pt == 3){
			v.push_back(tmp);
			tmp = 0;
			pt = 0;
		}
	}
	v.push_back(tmp);
	for(auto x : v){
		cout << x << " ";
	}
	cout << endl;
	vector<int> w;
	for(int i=0; i<v.size(); ++i){
		string s = to_string(v[i]);
		int a = 0;
		if(s.size() == 2){
			a = s[0] - '0';
		}
		if(s.size() == 3){
			a = (s[1] -'0')*10;
			a += (s[0] - '0');
		}
		else{
			a = (s[3] - '0') * 100;
			a += (s[1] - '0') * 10;
			a += (s[0] - '0');
		}
		cout << a << " ";
		w.push_back(a);

	}
}

void solve(){
	string s;
	cin >> s;
	
	seven(s);

	return ;
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
