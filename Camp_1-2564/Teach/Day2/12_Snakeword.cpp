#include<stdio.h>
#include<string.h>
#include<ctype.h>

int r,c, len;
char a[30][30], b[105];
int mark[30][30], ans[105][2], found=0;

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};
void play(int i, int j, int st) {
	ans[st][0] = i, ans[st][1] = j;
	if(st == len) {
		found = 1;
		for(int i=1; i<=len; i++)
			printf("%d %d\n", ans[i][0], ans[i][1]);
		return;
	}
	for(int k=0; k<4; k++) {
		int ii = i + di[k], jj = j + dj[k];
		if(ii>r || jj>c || ii<1 || jj<1) continue;
		if(mark[ii][jj]) continue;
		if(a[ii][jj] != b[st+1]) continue;
		mark[ii][jj] = 1;
		play(ii, jj, st+1);
		mark[ii][jj] = 0;
	}
}
int main() {
	scanf("%d %d", &r, &c);
	for(int i=1; i<=r; i++) {
		for(int j=1; j<=c; j++) {
			scanf(" %c", &a[i][j]);
			a[i][j] = tolower(a[i][j]);
		}
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		scanf(" %s", b+1);
		len = strlen(b+1);
		for(int i=1; i<=len; i++) {
			b[i] = tolower(b[i]);
		}
		found = 0;
		for(int i=1; i<=r && found==0; i++) {
			for(int j=1; j<=c && found==0; j++) {
				if(a[i][j]!=b[1]) continue;
				mark[i][j]=1;
				play(i, j, 1);
				mark[i][j]=0;
			}
		}
		if(!found) printf("No Matching Word\n");
	}
	return 0;
}
