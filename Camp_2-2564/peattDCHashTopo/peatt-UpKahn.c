/*
    TASK: Up Kahn
    LANG: C++
    AUTHOR: PeaTT~
*/
#include <bits/stdc++.h>
using namespace std;
int deg[100100];
vector<int> g[100100],ans;
priority_queue<int,vector<int>,greater<int>> heap;
int main(){
	int q,n,k,i,u,v,idx;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&n,&k);
		for(i=1;i<=k;i++){
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			deg[v]++;
		}
		for(i=1;i<=n;i++) if(!deg[i]) heap.push(i);
		while(!heap.empty()){
			idx = heap.top(); heap.pop();
			ans.push_back(idx);
			for(auto x:g[idx]){
				deg[x]--;
				if(!deg[x]) heap.push(x);
			}
		}
		if(ans.size()==n){
			printf("Yes ");
			for(i=0;i<ans.size();i++) printf("%d ",ans[i]);
			printf("\n");
		}
		else printf("No\n");
		ans.clear();
		for(i=1;i<=n;i++) g[i].clear();
		memset(deg,0,sizeof deg);
	}
    return 0;
}
