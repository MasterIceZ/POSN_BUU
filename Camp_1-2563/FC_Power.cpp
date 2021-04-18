/*
 * AUTHOR	: YuKi Onna~
 * SCHOOL	: RYW
 * LANG		: C++
 * TASK		: toi2_seqment
 * EDITOR	: neo-vim
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MxN = 1e8;

void solution(){
	int m;
	cin >> m;
	for(int i=2; i*i<=m; ++i){
		int ans = 0;
		int n = m;
		if(n%i!=0){
			continue;
		}
		while(n!=1){
			int rt = sqrt(n);
			if(rt*rt == n && rt%i!=0){
				break;
			}
			else if(n%i==0){
				n/=i;
				++ans;
			}
			else{
				break;
			}
		}
		if(n == 1){
			cout << ans << endl;
			return ;
		}
	}	
	cout << "NO" << endl;
	return ;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int i=1; i<=t; ++i){
//		cout << "Case #" << i << ": ";
		solution();
	}
	return 0;
}
