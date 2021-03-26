/*
    TASK  :
    AUTHOR: Hydrolyzed~
    GITHUB: MasterIceZ
    LANG  : C
    SCHOOL: RYW
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int a[33][33];
const int di[] = {-1,0,0,1}, dj[] = {0,-1,1,0};

int max(int h, int k){
	return h>k?h:k;
}

int min(int h,int k){
	return h<k?h:k;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		memset(a, 0, sizeof a);
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i=0;i<n;++i){
			for(int j=0; j<m;++j){
				scanf("%d", &a[i][j]);
			}
		}
		int nax = -1;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(abs(a[i][j]-a[i+1][j]) <= 10){
					nax = max(nax, a[i][j]+a[i+1][j]);
				}
				if(abs(a[i][j]-a[i][j+1]) <= 10){
					nax = max(nax, a[i][j]+a[i][j+1]);
				}
			}
		}
		int ch = 0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(a[i][j] + a[i+1][j] == nax){
					printf("%d %d\n", i+1, j+1);
					ch = 1;
				}
				else if(a[i][j] + a[i][j+1] == nax){
					printf("%d %d\n", i+1, j+1);
					ch = 1;
				}
				if(ch == 1){
					break;
				}
			}
			if(ch == 1){
				break;
			}
		}
	}	
	printf("\n");
	return 0;
}
