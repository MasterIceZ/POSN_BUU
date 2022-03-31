#include <bits/stdc++.h>
using namespace std;

int dp[1000100], a[1000100];
int main(){
    int n, r, c;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        dp[i]+=dp[i-1];
        if(a[i] > a[i-1]){
            dp[i]+=(a[i]-a[i-1]);
        }
    }
    int q;
    scanf("%d", &q);
    while(q--){
        scanf("%d %d", &r, &c);
        printf("%d\n", dp[c]-dp[r]);
    }

    return 0;
}
