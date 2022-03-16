#include <bits/stdc++.h>
using namespace std;

char a[55], b[55], c[55];
int x;

inline int calc(char s[]){
	int res = 0, len = strlen(s);
	for(int i=0; i<len; ++i){
		res *= x;
		if(isdigit(s[i])){
			res += s[i] - '0';
		}
		else{
			res += s[i] - 'A' + 10;
		}
	}
	return res;
}

int main(){
	scanf("%d %s %s", &x, a, b);
	int num_a = calc(a);
	int num_b = calc(b);
	int sum = num_a + num_b;
	printf("%d\n", sum);
	int it = 0;
	while(sum){
		int cur = sum % x;
		if(cur >= 10){
			c[it] = cur - 10 + 'A';
		}
		else{
			c[it] = cur + '0';
		}
		sum /= x, it++;
	}
	for(--it; it >= 0; --it){
		printf("%c", c[it]);
	}
	printf("\n");
	return 0;
}
