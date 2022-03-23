#include<stdio.h>

int n,m;
double mn = 2e9;

int mark[5][5];
double a[5][5];

int di[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dj[] = {0, 0, 1, -1, 1, -1, 1, -1};

void SET(int i, int j) {
	mark[i][j] = 1;
	for(int k=0; k<8; k++) {
		int ii = i+di[k], jj = j+dj[k];
		if(ii>n-1 || j>m-1 || ii<0 || jj<0) continue;
		a[ii][jj] += a[i][j]/10;
	}
}
void BACKTRACK(int i, int j) {
	mark[i][j] = 0;
	for(int k=0; k<8; k++) {
		int ii = i+di[k], jj = j+dj[k];
		if(ii>n-1 || j>m-1 || ii<0 || jj<0) continue;
		a[ii][jj] -= a[i][j]/10;
	}
}
void play(int st, double now) {
	if(st==n*m) {
		if(now < mn)
			mn = now;
		return;
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(mark[i][j]) continue;
			SET(i, j);
			play(st+1, now+a[i][j]);
			BACKTRACK(i, j);
		}
	}

}
int main() {
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%lf", &a[i][j]);
		}
	}
	play(0, 0);
	printf("%.2lf\n", mn);
	return 0;
}

