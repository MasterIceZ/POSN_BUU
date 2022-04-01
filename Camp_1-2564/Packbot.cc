#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;

stack<int> st;
stack<char> opr;

inline void calc(){
	int r = st.top();
	st.pop();
	int l = st.top();
	st.pop();
	int oprx = (opr.top() - '0') + 1;
	opr.pop();
	int sum = l + r;
	st.push(sum * (100 + (1 << oprx)) / 100);
}

inline int prio(char x){
	return isdigit(x) ? x - '0': -1;
}

void solve(){
	string s;
	cin >> s;
	n = s.size();
	for(auto x: s){
		if(isalpha(x)){
			st.push(20);
		}
		else if(x == '['){
			opr.push(x);
		}
		else if(x == ']'){
			while(!opr.empty() && opr.top() != '['){
				calc();
			}
			opr.pop();
		}
		else{
			while(!opr.empty() && prio(opr.top()) >= prio(x)){
				calc();
			}
			opr.push(x);
		}
	}
	while(!opr.empty()){
		calc();
	}
	cout << st.top();
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}	
	return 0;
}
