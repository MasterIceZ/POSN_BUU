/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Destroy Bottle
 * ALGO		: Greedy
 * DATE		: 11 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using ll = long long;

struct A{
    ll nu, att;
    bool operator<(const A&o) const{
        return nu<o.nu;
    }
};
A a[100100];
ll b[100100],c[100100],mark[100100],ch[100100];
int32_t main () {
    ios::sync_with_stdio(0);cin.tie(0);
    ll n, m, cnt, ans, idx, i, num, j;
    cin>>n>>m;
    cnt=n;
    for (i=1;i<=n;i++) {
        cin>>a[i].nu;
        a[i].att=i;
    }
    sort(a+1,a+n+1);
    for (i=1;i<=n;i++) {
        b[i]=a[i].nu, c[i]=a[i].att;
    }
    for (j=1;j<=m;j++) {
        cin>>num;
        ans=0;
        for (i=cnt;i>=1;i--) {
            if (b[i]<=num) {
                cnt=i;break;
            }
            if (mark[c[i]]&&mark[c[i]]!=j) continue;
            if (mark[c[i]]!=j) ans++,mark[c[i]]=j;
            if (c[i]+1<=n&&!mark[c[i]+1]) ans++, mark[c[i]+1]=j;
            if (c[i]-1>=1&&!mark[c[i]-1]) ans++, mark[c[i]-1]=j;
        }
        cout<<ans<<endl;
    }
    return 0 ;
}
