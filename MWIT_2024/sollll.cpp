#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 101;
const int MOD = 5454541;
int a[N], b[N];
int dp[2][N][N];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int ans = n;
    for (int i = 2;i <= n;i++) { // choose i 
        memset(dp, 0, sizeof dp);
        dp[0][0][0] = 1;
        for (int j = 1;j <= n;j++) {
            int now = j & 1, prev = 1 - now;
            b[j] = a[j] % i;
            for (int k = 0;k <= i;k++) {
                for (int l = 0;l < i;l++) {
                    dp[now][k][l] = dp[prev][k][l];
                    if (k) dp[now][k][l] = (dp[now][k][l] + dp[prev][k - 1][(l - b[j] + i) % i]) % MOD;
                }
            }
        }
        //cout << dp[n & 1][i][0] << ' ';
        ans = (ans + dp[n & 1][i][0]) % MOD;
    }
    cout << ans;
    return 0;
}
