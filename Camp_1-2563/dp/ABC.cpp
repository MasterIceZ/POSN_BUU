#include<bits/stdc++.h>
using namespace std;

#define int long long

char s[1000100];
int dp1[1000100], dp2[1000100];
int32_t main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	scanf("%lld", &q);
	while(q--){
		scanf(" %s", s+1);
		int len = strlen(s+1);
		for(int i=1; i<=len; ++i){
			dp1[i] = dp1[i-1], dp2[i] = dp2[i-1];
			if(s[i] == 'A'){
				dp1[i]++;
			}
			if(s[i] == 'C'){
				dp2[i]++;
			}
		}
		int ans = 0;
		for(int i=1; i<=len; ++i){
			if(s[i] == 'B'){
				ans += (dp1[i-1] * (dp2[len] - dp2[i]));
			}
		}
		printf("%lld", ans);
	}


	return 0;
}
