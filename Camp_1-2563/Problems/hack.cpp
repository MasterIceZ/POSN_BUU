#include<bits/stdc++.h>
using namespace std;
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	set<string>s;
	for(int i=0; i<n; ++i){
		string a;
		cin >> a;
		s.insert(a);
	}
	while(m--){
		string a;
		cin >> a;
		cout << (s.count(a)?"Accepted":"Rejected");
		cout << endl;
	}

	return 0;
}
