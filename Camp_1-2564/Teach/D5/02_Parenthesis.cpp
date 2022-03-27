#include<bits/stdc++.h>
using namespace std;

char a[250];
stack<char> st;
int main() {
	int q;
	scanf("%d", &q);
	while(q--) {
		scanf(" %s", a);
		int n = strlen(a), ch=0;
		for(int i=0; i<n; i++) {
			if(a[i] == '[' || a[i] == '(')
				st.push(a[i]);
			else if(st.empty()) {
			   	ch=1;
				break;
			}
			else if(a[i] == ']' && st.top()=='[')
			  	st.pop();
			else if(a[i] == ')' && st.top()=='(')
				st.pop();
			else {
				ch=1;
				break;
			}
		}
		if(st.empty() && ch==0) printf("Yes\n");
		else printf("No\n");
		while(!st.empty()) st.pop();
	}
	return 0;
}
