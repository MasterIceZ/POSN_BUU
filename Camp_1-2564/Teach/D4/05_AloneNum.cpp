#include <bits/stdc++.h>
using namespace std;

vector<int> v;
map<int, int> mp;

int main(){
	int q, n, x, ch;
	scanf("%d", &q);
	while(q--){
		ch = 1;
		scanf("%d", &n);
		for(int i=1; i<=n; ++i){
			scanf("%d", &a[i]);
			mp[a[i]]++;
		}
		for(int i=1; i<=n; ++i){
			if(mp[a[i]] == 1){
				printf("%d", a[i]);
				ch = 0;
			}
		}
		if(ch){
			printf("No Alone Num");
		}
		mp.clear();
//		ch = 1;
//		scanf("%d", &n);
//		for(int i=0; i<n; i++){
//			scanf("%d", &x);
//			v.push_back(x);
//			mp[x]++;
//		}
//		for(int i=0; i<n; i++){
//			if(mp[v[i]]==1){
//				printf("%d ",v[i]);
//				ch = 0;
//			}
//		}
//		if(ch){
//			printf("No Alone Num");
//		}
//		v.clear();
//		mp.clear();
	}
	return 0;
}
