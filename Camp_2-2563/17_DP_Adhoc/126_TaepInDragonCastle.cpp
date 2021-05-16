/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Taep in Dragon Castle
 * ALGO		: Dynamic Programming Adhoc
 * DATE		: 16 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

int dp[30][30],a[30][30];
int main(){
    int q,r,c,k,p,i,j,sum;
    cin >> q;
    while(q--){
        cin >> r >> c >> k >> p;
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                a[i][j]=1;
        while(--k){
            for(i=1;i<=r;i++)
                for(j=1;j<=c;j++)
                    dp[i][j]=(a[i][j]+a[i][j-1]+a[i-1][j]+a[i][j+1]+a[i+1][j])%p;
            for(i=1;i<=r;i++)
                for(j=1;j<=c;j++)
                    a[i][j]=dp[i][j];
        }
        for(i=1,sum=0;i<=r;i++)
            for(j=1;j<=c;j++)
                sum+=a[i][j],sum%=p;
        cout << sum << "\n";
        memset(a,0,sizeof a);
        memset(dp,0,sizeof dp);
    }
    return 0;
}
