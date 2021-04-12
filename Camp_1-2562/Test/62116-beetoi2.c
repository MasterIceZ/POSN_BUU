#include<stdio.h>
#include<math.h>
#include<string.h>
char year[1000];
int main ()
{
    int w = 1, q = 1, s=0,all;
    gets(year);
    int len = strlen(year);
    for(int i=0; i<=len-2; i++)
    {
        all = 0;
        if(year[i]=='-')
        {
            break;
        }
        else if (year[i]==' ')
        {
            continue;
        }
        for(int j=0; j<=len-2; j+=2)
        {

            if(year[i]=='1')
            {
                w=2;
                s=1;
            }
            else if(year[i]=='2')
            {
                w=4;
                s=2;
            }
            else if(year[i]=='3')
            {
                w=7;
                s=4;
            }
            else if(year[i]=='4')
            {
                w=12;
                s=7;
            }
            else if(year[i]=='5')
            {
                w=20;
                s=12;
            }
            else if(year[i]=='6')
            {
                w=33;
                s=20;
            }
            else if(year[i]=='7')
            {
                w=54;
                s=33;
            }
            else if(year[i]=='8')
            {
                w=88;
                s=54;
            }
            else if(year[i]=='9')
            {
                w=143;
                s=88;
            }


        }
        all = w+q+s;
        printf("%d %d\n",w,all);

    }


    return 0;
}
