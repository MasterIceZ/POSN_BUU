#include <stdio.h>
int main(){
	int q = 20;
	while(q--){
		int sum, row;
		scanf("%d %d", &sum, &row);
		int c = (sum - 2 * row) / 2;
		if(c < 0 || c > row){
			printf("0\n");
		}
		else{
			printf("%d\n", (sum - 4 * c) / 2 + 1);
		}
	}
	return 0;
}
