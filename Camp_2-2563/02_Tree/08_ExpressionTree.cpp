/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Expression Tree
 * ALGO		: Depth First Search + Expression Tree
 * DATE		: 6 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;

char s[333], a[333];
stack<int>st;
int l[333], r[333];

void in(int i){
	if(l[i]){
		cout << "(";
		in(l[i]);
	}
	cout << a[i];
	if(r[i]){
		in(r[i]);
		cout << ")";
	}
}

void pre(int i){
	cout << a[i];
	if(l[i]){
		pre(l[i]);
	}
	if(r[i]){
		pre(r[i]);
	}
}

void solve(){
	gets(s);
	int len = strlen(s);
	int ptr = 0;
	for(int i=0; i<len; ++i){
		if(isalpha(s[i])){
			a[++ptr] = s[i];
			st.push(ptr);
		}
		else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
			a[++ptr] = s[i];
			r[ptr] = st.top();
			st.pop();
			l[ptr] = st.top();
			st.pop();
			st.push(ptr);
		}
	}
	in(ptr);
	cout << endl;
	pre(ptr);
	cout << endl;
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
