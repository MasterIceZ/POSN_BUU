#include<stdio.h>
#include<string.h>

char key[500];
char id[500];
char ans[500];
int point,len,i;

int main (){
	FILE *fp ;
	fp = fopen("D: \\file \\answers.txt","r");
	FILE *fp2 ;
	fp = fopen("D: \\file \\score.txt","w");
	fscanf(fp,"%s",key);

	while(!feof(fp))
	{	
		point = 0;
		fscanf(fp,"%s",id);
		fprintf(fp2,"%s",id);
		fscanf(fp,"%s",ans);
		len = strlen(ans);
		i=0;
		while(i<len)
		{
			if(ans[i]==key[i])
				point++;
			i++;
		}
		fprintf(fp2,"%d\n",point);
	}

	fclose (fp);
	return 0;		
}
