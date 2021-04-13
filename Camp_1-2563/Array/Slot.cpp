#include<bits/stdc++.h>
using namespace std;

struct ice{
	int u,w,x,y,z;
};

int v[22][22];

vector<ice>a;

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n ;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=5;++j){
			cin >> v[i][j];
		}
	}
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k){
				for(int l=1;l<=n;++l){
					for(int x=1;x<=n;++x){
						if(v[i][1] == v[j][2] && v[j][2] == v[k][3] && v[k][3] == v[l][4] && v[l][4] == v[x][5]){
							a.push_back({i,j,k,l,x});
						}
					}
				}	
			}
		}
	}

	cout << a.size() << "\n";
	for(auto m : a){
		cout << m.u << " " << m.w << " " << m.x << " " << m.y << " " << m.z << "\n";
	}

	return 0;
}
