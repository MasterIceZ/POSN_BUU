#include<bits/stdc++.h>
using namespace std;

struct pii{
	int x, y;
	bool operator < (const  pii& o) const{
		if(x != o.x){
			return x < o.x;
		}
		return y > o.y;
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<pii>v(n);
	for(int i=0; i<n; ++i){
		cin >> v[i].x >> v[i].y;
	}
	sort(v.begin(), v.end());
	for(auto x: v){
		cout << x.x << " " << x.y << endl;
	}
	return 0;
}
