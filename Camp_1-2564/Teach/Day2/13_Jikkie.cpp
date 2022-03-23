#include<stdio.h>

int MX[5], ans[30], mk[30][30][30];

void play(int NOW[]) {
	for(int i=0; i<3; i++) {
		if(NOW[i]<0 || NOW[i]>MX[i]) return;
	}
	if(mk[ NOW[0] ][ NOW[1] ][ NOW[2] ]) return;
	mk[ NOW[0] ][ NOW[1] ][ NOW[2] ] = 1;
	if(NOW[0]==0)
		ans[NOW[2]] = 1;
	int NEXT[3];
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(i==j) continue;
			// i -> j

			int OTHER = 3-i-j;
			// CASE : EMPTY
			NEXT[j] = NOW[i] + NOW[j];
			NEXT[i] = 0;
			NEXT[OTHER] = NOW[OTHER]; 
			play(NEXT);

			//CASE : FULL
			NEXT[j] = MX[j];
			NEXT[i] = NOW[i] - (MX[j]-NOW[j]);
			NEXT[OTHER] = NOW[OTHER];
			play(NEXT);

		}
	}
}
int main() {
	for(int i=0; i<3; i++)
		scanf("%d", &MX[i]);
	int ST[3] = {0, 0, MX[2]};
	play(ST);
	for(int i=0; i<=MX[2]; i++)
		if(ans[i]) printf("%d ", i);
	printf("\n");
	return 0;
}
