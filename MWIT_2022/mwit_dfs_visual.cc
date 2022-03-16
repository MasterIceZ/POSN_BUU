/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * DATE		: 15 Mar 2022
 * */

#include <stdio.h>
#include <string.h>

int l[10010], r[10010], a[10010];
char opr[10];

void post(int x, int last = -1){
	printf("dfs(%d)\n", a[x]);
	if(l[x] != -1){
		post(l[x], a[x]);
	}
	if(r[x] != -1){
		post(r[x], a[x]);
	}
	printf("print(%d)\n", a[x]);
	if(last != -1){
		printf("Backtrack to %d\n", last);
	}
}

void in(int x, int last = -1){
	printf("dfs(%d)\n", a[x]);
	if(l[x] != -1){
		in(l[x], a[x]);
	}
	printf("print(%d)\n", a[x]);
	if(r[x] != -1){
		in(r[x], a[x]);
	}
	if(last != -1){
		printf("Backtrack to %d\n", last);
	}
}

void pre(int x, int last = -1){
	printf("dfs(%d)\n", a[x]);
	printf("print(%d)\n", a[x]);
	if(l[x] != -1){
		pre(l[x], a[x]);
	}
	if(r[x] != -1){
		pre(r[x], a[x]);
	}
	if(last != -1){
		printf("Backtrack to %d\n", last);
	}
}

int main(){
	memset(l, -1, sizeof l);
	memset(r, -1, sizeof r);
	int n, x, ptr = 1;
	printf("Welcome to Binary Search Tree Visualizer\n");
	printf("Insert Binary Search Tree\n");
	printf("Enter Number of Nodes : ");
	scanf("%d", &n);
	printf("Enter Node : ");
	scanf("%d", &x);
	a[ptr] = x;
	for(int i=2, it = 1; i<=n; ++i, it = 1){
		printf("Enter Node : ");
		scanf("%d", &x);
		while(1){
			if(x < a[it]){
				if(l[it] == -1){
					l[it] = ++ptr;
					a[ptr] = x;
					break;
				}
				else{
					it = l[it];
				}
			}
			else{
				if(r[it] == -1){
					r[it] = ++ptr;
					a[ptr] = x;
					break;
				}
				else{
					it = r[it];
				}
			}
		}
	}
	printf("[Pr]eorder // [In]order // [Po]storder : ");
	scanf(" %s", opr);
	printf("Output : \n");
	if(opr[1] == 'r'){
		pre(1);
	}
	else if(opr[1] == 'n'){
		in(1);
	}
	else{
		post(1);
	}
	return 0;
}
