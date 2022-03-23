#include<stdio.h>
#include<math.h>

const int SIZE = 15;

int n,m;
int X[SIZE], Y[SIZE], Z[SIZE];
int M[SIZE], K[SIZE], C[SIZE];
int visited[SIZE], mn = 2e9;

int distance(int dx, int dy, int dz) {
	return dx*dx + dy*dy + dz*dz;
}
void play(int now_x, int now_y, int now_z, int now_M, int now_K, int now_C, int money) {
	if(now_M >= n && now_K >= n && now_C >= n) {
		if(money < mn)
			mn = money;
		return;
	}
	for(int i=0; i<m; i++) {
		if(visited[i]) continue;
		visited[i] = 1;
		play( X[i], Y[i], Z[i], now_M + M[i], now_K + K[i], now_C + C[i], money + distance(X[i] - now_x, Y[i] - now_y, Z[i] - now_z) );
		visited[i] = 0;
	}
}
int main() {
	scanf("%d", &n);
	int st_x, st_y, st_z;
	scanf("%d %d %d", &st_x, &st_y, &st_z);

	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		scanf("%d %d %d", &X[i], &Y[i], &Z[i]);
		scanf("%d %d %d", &M[i], &K[i], &C[i]);
	}
	play(st_x, st_y, st_z, 0, 0, 0, 0);
	printf("%d\n", mn);
	return 0;
}
