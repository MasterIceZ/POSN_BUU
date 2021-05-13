/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Jump Land
 * ALGO		: Disjoined Set Union
 * DATE		: 12 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using LL = long long;

const int N = 710;
struct A{
	int u,v;
	double w;
	bool operator < (const A&o) const{
		return w<o.w;
	}
};
int h[N*N],sp[N*N];
int p[N*N],cnt[N*N];
vector<A > t;
int n,ans = 1;
int id(int i,int j){
	return (i*n) + j;
}
int fr(int u){
	return ((u == p[u])?u:fr(p[u]));
}
void merge(int u,int v){
	if(sp[u] != sp[v]){
		double now = (double )(h[v]-h[u])/(sp[u]-sp[v]);
		if(now<0)	return ;
		t.push_back({u,v,now});
	}else if(h[u] == h[v]){
		int ru = fr(u),rv = fr(v);
		if(ru == rv)	return ;
		ans = max(ans,cnt[ru]+cnt[rv]);
		if(cnt[ru]>=cnt[rv])	cnt[ru]+=cnt[rv],p[rv] = ru;
		else					cnt[rv]+=cnt[ru],p[ru] = rv;
	}
}
vector<A > temp;
void reset(){
	reverse(all(temp));
	for(auto x:temp){
		cnt[x.u]-=cnt[x.v];
		p[x.v] = x.v;
	}
	temp.clear();
}
void solve(){
	cin >> n;
	for(int i=0; i<n*n; ++i){	
		cin >> h[i];
	}
	for(int i=0; i<n*n; ++i){	
		cin >> sp[i];
	}
	iota(p,p+(n*n),0);
	fill(cnt,cnt+(n*n),1);
	t.push_back({0,0,-1});
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(i+1<n){
				merge(id(i,j),id(i+1,j));
			}
			if(j+1<n){
				merge(id(i,j),id(i,j+1));
			}
		}
	}
	sort(all(t));
	for(int i=1;i<t.size();i++){
		if(t[i].w!=t[i-1].w){	
			reset();
		}
		int ru = fr(t[i].u),rv = fr(t[i].v);
		if(ru == rv){
			continue;
		}
		ans = max(ans,cnt[ru]+cnt[rv]);
		if(cnt[ru]>=cnt[rv]){
			cnt[ru]+=cnt[rv];
			p[rv] = ru;
			temp.push_back({ru,rv,0});
		}
		else{	
			cnt[rv]+=cnt[ru];
			p[ru] = rv;
			temp.push_back({rv,ru,0});
		}
	}
	cout << ans << '\n';
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
