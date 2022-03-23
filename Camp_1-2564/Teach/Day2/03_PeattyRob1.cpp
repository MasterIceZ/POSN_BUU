#include<stdio.h>
#include<string.h> // strlen

char a[105];
int main() {
	scanf(" %s", a);
	int len = strlen(a);
	int x=0, y=0;
	for(int i=0; i<len; i++) {
		if(a[i] == 'N') y++;
		else if(a[i] == 'S') y--;
		else if(a[i] == 'E') x++;
		else if(a[i] == 'W') x--;
		else if(a[i] == 'Z') x=0,y=0;
	}
	printf("%d %d\n", x, y);
	return 0;
}

