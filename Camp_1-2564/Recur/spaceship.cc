#include <stdio.h>

int k, s_x, s_y, s_z, n, answer = 1e9 + 10;

int x[22], y[22], z[22], a[22], b[22], c[22];
int visited[22];

int power(int x){
	return x * x;
}

int min(int a, int b){
	return a < b ? a: b;
}

void rec(int cost, int h_x, int h_y, int h_z, int p_x, int p_y, int p_z){
	for(int i=1; i<=n; ++i){
		if(visited[i]){
			continue;
		}
		visited[i] = 1;
		int next_cost = cost + power(p_x - x[i]) + power(p_y - y[i]) + power(p_z - z[i]);
		if(h_x + a[i] >= k && h_y + b[i] >= k && h_z + c[i] >= k){
			answer = min(answer, next_cost);
		}
		else{
			rec(next_cost, h_x + a[i], h_y + b[i], h_z + c[i], x[i], y[i], z[i]);
		}
		visited[i] = 0;
	}
}

int main(){
	scanf("%d %d %d %d %d", &k, &s_x, &s_y, &s_z, &n); 
	for(int i=1; i<=n; ++i){
		scanf("%d %d %d %d %d %d", &x[i], &y[i], &z[i], &a[i], &b[i], &c[i]);
	}
	rec(0, 0, 0, 0, s_x, s_y, s_z);
	printf("%d\n", answer);
	return 0;
}
