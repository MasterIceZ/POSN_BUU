#include<bits/stdc++.h>
using namespace std;

#define int long long

int nax, a;
vector<int> v;

void to_bin(int n){
	int remain;
	while(n!=0){
		remain = n%2;
		n/=2;
		v.push_back(remain);
	}	
	while(v.size() < a){
		v.push_back(0);
	}
	reverse(v.begin(), v.end());
}

vector<int>tmp;

void rec(int state){
	if(state == a){
		return ;
	}
	else{
		if(state == 0){
			tmp.push_back(v[0]);
		}
		else{
			tmp.push_back((v[state]+v[state-1])%2);
		}
		rec(state+1);
	}
	return ;
}

void solve(){
	cin >> a;
	nax = (1 << a) - 1;
	for(int i=0; i<=nax; ++i){
		to_bin(i);
		rec(0);
		for(auto k : tmp){
			cout << k;
		}
		cout << endl;
		v.clear();
		tmp.clear();
	}
	return ;
}

int32_t main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int q;
	cin >> q;
	while(q--){
		solve();
	}

	return 0;
}
