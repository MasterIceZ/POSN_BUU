#include <stdio.h>
#include <ctype.h>
#include <string.h>

int n, m, ok, len;
char a[33][33], s[120];
int visited[33][33], mem[120][2];

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

void walk(int i, int j, int state){
	mem[state][0] = i;
	mem[state][1] = j;
	state += 1;
	if(state == len){
		for(int i=0; i<state; ++i){
			printf("%d %d\n", mem[i][0], mem[i][1]);
		}
		ok = 1;
		return ;
	}
	for(int k=0; k<4; ++k){
		int ii = di[k] + i;
		int jj = dj[k] + j;
		if(ii < 1 || jj < 1 || ii > n || jj > m){
			continue;
		}
		if(a[ii][jj] != s[state] || visited[ii][jj]){
			continue;
		}
		visited[ii][jj] = 1;
		walk(ii, jj, state);
		visited[ii][jj] = 0;
	}
}

void solve(){
	scanf(" %s", s);
	memset(visited, 0, sizeof visited);
	ok = 0;
	::len = strlen(s);
	for(int i=0; i<len; ++i){
		s[i] = toupper(s[i]);
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == s[0]){
				visited[i][j] = 1;
				walk(i, j, 0);
				visited[i][j] = 0;
			}
		}
	}
	if(!ok){
		printf("No Matching Word\n");
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			scanf(" %c", &a[i][j]);
			a[i][j] = toupper(a[i][j]);
		}
	}
	int q;
	scanf("%d", &q);
	while(q--){
		solve();
	}
	return 0;
}
