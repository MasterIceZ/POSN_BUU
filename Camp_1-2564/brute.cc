#include <bits/stdc++.h>
using namespace std;

set<vector<int>> st;

void rec(vector<int> v){
	if(v.size() == 3){
		if(v[0] > 0 && v[1] > 0 && v[2] > 0 && v[0] + v[1] + v[2] == 20){
			st.insert(v);
		}
		return ;
	}
	v.push_back(0);
	for(int i=1; i<=20; ++i){
		v[v.size() - 1] = i;
		rec(v);
	}
}

int main(){
	rec({});
	cout << st.size() << "\n";
//	for(auto x: st){
//		cout << x[0] << " " << x[1] << " " << x[2] << "\n";
//	}
	return 0;
}
