/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: AP_Bush
 * ALGO		: Binary Search
 * DATE		: 12 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using LL = long long;
long long a[1010];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        long long n,k;
        cin >> n >> k;
        for(int i=0;i<n;i++)
            cin >> a[i];
        sort(a,a+n);
        long long r=0,l=1e9;
        while(r<l){
            long long mid =(r+l)/2;
            long long cnt = (mid+1)*(mid+1)*(n);

            for(int i=1;i<n;i++){
                if(a[i]==a[i-1]){
                    cnt -= (mid+1)*(mid+1);
                    continue;
                }
                long long dis = a[i]-a[i-1]-1;
                if(dis%2==1){
                    dis/=2;
                    if(dis<mid){
                        dis = mid-dis;
                        cnt -= dis*dis;
                    }
                }
                else{
                    dis/=2;
                    if(dis<mid){
                        dis = mid-dis;
                        cnt -= dis*(dis+1);
                    }
                }

            }
            if(cnt<k)   r = mid+1;
            else        l = mid;
        }
        cout << l << endl;
    }
}
