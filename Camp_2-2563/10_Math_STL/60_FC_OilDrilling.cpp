/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: FC_Oil Drilling
 * ALGO		: Set
 * DATE		: 11 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;
set<int>s;
set<int>::iterator it1, it2;

void solve(){
	int x;
	cin >> x;
	if(s.empty()){
		cout << n;
	}
	else{
		it1 = it2 = s.lower_bound(x);
		it1--;
		if(it2 == s.begin()){
			cout << (*it2) - x;
		}
		else if(it2 == s.end()){
			cout << x - (*it1);
		}
		else{
			cout << min((*it2)-x, x-(*it1));
		}
	}
	s.insert(x);
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
	cin >> n;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
