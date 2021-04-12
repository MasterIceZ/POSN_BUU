#include<stdio.h>
#include<string.h>

char a[510];
char *ptr;
int main (){
	int i,q,ch,ch2,len;
	gets(a);
	sscanf(a,"%d",&q);
	while(q--)
	{
		gets(a);
		if(a[strlen(a)-1]=='\r') 
			a[strlen(a)-1]='\0';
		ptr = strtok(a," ");
		ch = 1;
		while(ptr!= NULL)
		{
			len = strlen(ptr);
			if(len%4==0){
				for(i=0,ch2=1;i<len;i+=4){
					if(strncmp("meow",&ptr[i],4)){
						ch2=0; 
						break;
					}
				}
				if(ch2){
					printf("YES\n"); ch= 0; break;
				}
			}
			ptr = strtok(NULL," ");	
			
		}
		if(ch)
				printf("NO\n");
	}

	
	
}
