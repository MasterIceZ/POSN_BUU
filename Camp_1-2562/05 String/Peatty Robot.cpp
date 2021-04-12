#include<stdio.h>
#include<string.h>
int main(){
	char a[120];
	gets(a);
	int len = strlen(a),i;
	int x = 0,y = 0;
	for(i=0;i<len;i++){
		if(a[i]=='N')
			y++;
		else if(a[i]=='S')
			y--;
		else if(a[i]=='E')
			x++;
		else if(a[i]=='W')
			x--;
		else if(a[i]=='Z'){
			x = 0 ;
			y = 0 ;
		}
	}
	printf("%d %d",x,y);
	return 0;
}
