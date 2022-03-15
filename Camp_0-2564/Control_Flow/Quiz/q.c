#include <stdio.h>
#include <math.h>
#include <string.h>

char st[105];
int n, s, e, w;

int main(){
	int k, len;
	scanf(" %s %d", st, &k);
	len = strlen(st);
	for(int i=0; i<len; ++i){
		if(st[i] == 'N'){
			n++;
		}
		else if(st[i] == 'E'){
			e++;
		}
		else if(st[i] == 'W'){
			w++;
		}
		else{
			s++;
		}
	}
	if(n > s){
		n = n ^ s;
		s = n ^ s;
		n = n ^ s;
	}
	if(w > e){
		w = w ^ e;
		e = w ^ e;
		w = w ^ e;
	}
	while(k--){
		if(n){
			n--;
		}
		else if(w){
			w--;
		}
		else if(s){
			s--;
		}
		else{
			e--;
		}
	}
	printf("%d", (s + e - n - w) * 2);
	return 0;
}
