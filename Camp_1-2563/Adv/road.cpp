#include<iostream>
#include<queue>
using namespace std;
const int INF = 1e9+7;
int n,m;
int dp1[110],dp2[110];
int np1[110],np2[110];
int main (){
	int x,sum;
	scanf("%d %d",&n,&m);	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&x);
			np1[i]+=x;
			np2[j]+=x;
			sum+=x;
		}
	}
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&x);
			dp1[i]+=x;
			dp2[j]+=x;
		}
	}
	int now;
	priority_queue<int>ans;
	for(int i=1;i<=n;++i){
		now=0;
		for(int j=1;j<=n;++j){
			if(i==j){
				continue;
			}
			if(j-1==i or j+1==i){
				now+=dp1[j]+np1[j];
			}
			else{
				now+=np1[j];
			}
		}
		ans.push(now);
	}
	for(int i=1;i<=m;++i){
		now=0;
		for(int j=1;j<=m;++j){
			if(i==j){
				continue;
			}
			if(j-1==i or j+1==i){
				now+=dp2[j]+np2[j];
			}
			else{
				now+=np2[j];
			}
		}
		ans.push(now);
	}
	printf("%d",ans.top());
	return 0;
}
