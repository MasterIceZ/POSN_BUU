/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Magnet
 * ALGO		: Sweepline
 * DATE		: 17 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;
void init();
int n, m;

int a[200100], b[200100];

void solve(){
	int n, m, q, i, r, s, cnt=0, j;
    cin>>n>>m>>q;
    while(m--) {
        cin>>r>>s;
        a[cnt++]=r,a[cnt++]=r+s;
    }
    sort(a,a+cnt);
    for(i=0,r=0;i<cnt;i=j) {
        for(j=i+1;j<cnt && a[i]==a[j];j++);
        if((j-i)%2==1) {
            b[r++]=a[i];
        }
    }
    while(q--) {
        cin>>s;
        if(s<b[0]) cout<<b[0]-1<<endl;
        else if(s>=b[r-1]) cout<<n-b[r-1]+1<<endl;
        else {
            i=upper_bound(b,b+r,s)-b;
            cout<<b[i]-b[i-1]<<endl;
      	}
	}	
	return ;
}

int32_t main(){
	init();
	int t=1;
//	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
void init(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	return ;
}
