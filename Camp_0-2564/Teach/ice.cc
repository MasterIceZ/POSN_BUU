#include <stdio.h>

int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		int x, k;
		scanf("%d %d", &x, &k);
		int player = 1, cnt = 0;
		while(x - 100 * player > 0){
			player--;
			cnt++;
			x -= 10;
			player += k;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
