#include<stdio.h>

char a[1010][90];
int cnt=0,n,m;

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};
void play(int i, int j) {
	if(i>n-1 || j>m-1 || i<0 || j<0) return;
	if(a[i][j] != '*') return;
	a[i][j] = '.';
	++cnt;
	for(int k=0; k<4; k++)
		play(i+di[k], j+dj[k]);
}
int main() {
	int mx=0;
	scanf("%d %d", &m, &n);
	for(int i=0; i<n; i++)
		for(int j=1; j<m; ++j)
			scanf(" %c", &a[i][j]);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(a[i][j]!='*') continue;
			cnt=0;
			play(i, j);
			if(cnt>mx) mx=cnt;
		}
	}
	printf("%d\n", mx);
	return 0;
}
