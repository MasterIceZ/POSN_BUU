#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	string s;
	cin >> s;

	bool mark = false;
	int pt = 1, sum = 0;
	for(int i = s.size()-1; i>=s.size()%3; i-=3){
		int tmp = 0;
		for(int j=i-2; j<=i; ++j){
			tmp *= 10;
			tmp += s[i]-'0';
		}	
		sum += tmp*pt;
		pt*=-1;
	}
	int tmp = 0;
	for(int i=0; i<s.size()%3; ++i){
		tmp *= 10;
		tmp += s[i] - '0';
	}
	sum += tmp*pt;
	if(sum %7 == 0){
		cout << "7 * " << sum/7 << endl;
		mark = true;
	}

	pt = 1, sum = 0;
	for(int i=s.size()-1; i>=0; --i){
		sum += pt*(s[i] - '0');
		pt*=-1;
	}
	if(sum%11==0){
		cout << "11 * " << sum/11 << endl;
		mark = true;
	}

	if(!mark){
		cout << s << endl;
	}
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
