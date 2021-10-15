#include<bits/stdc++.h>
using namespace std;

using ll = long long;
char s[111];

int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		stack<ll> st;
		scanf(" %s", s);
		int len = strlen(s);
		for(int i=0; i<len; ++i){
			int now = s[i];
			if(now == '('){
				st.push(-1);
			}
			else if(now == ')'){
				ll sum = 0;
				while(!st.empty() && st.top() != -1){
					sum += st.top();
					st.pop();
				}
				st.pop();
				st.push(sum);
			}
			else if(isdigit(now)){
				ll n = now - '0';
				ll tmp = st.top();
				st.pop();
				st.push(n * tmp);
			}
			else{
				if(now == 'H'){
					st.push(1);
				}
				else if(now == 'O'){
					st.push(16);
				}
				else{
					st.push(12);
				}
			}
		}
		ll res = 0;
		while(!st.empty()){
			res += st.top();
			st.pop();
		}
		printf("%lld\n", res);
	}
	return 0;
}
