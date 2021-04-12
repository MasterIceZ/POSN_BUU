#include<stdio.h>
#include<math.h>
#include<string.h>
int one=0,two=0,three=0,four=0,five=0,six=0,seven=0,eight=0,nine=0,zero=0;
int main ()
{
    int a;
    int i,j;
    long long frac = 1;
    scanf("%d",&a);
    i = 1;
    j = a;
    while(j>i)
    {
        frac *=j;
        j--;
    }
    if(a==0)
        printf("1\n");
    else
    printf("%lld\n",frac);
    if(a==0)
    {
        one=1;
    }
    else if(a==1)
    {
        one=1;
    }
    else if(a==2)
    {
        two=1;
    }
    else if(a==3)
    {
        six=1;
    }
    else if(a==4)
    {
        four=1;
        two=1;
    }
    else if(a==5)
    {
        one=1;
        two=1;
        zero=1;
    }
    else if(a==6)
    {
        seven=1;
        two=1;
        zero=1;
    }
    else if(a==7)
    {
        zero=2;
        five=1;
        four=1;
    }
    else if(a==8)
    {
        zero=2;
        four=1;
        three=1;
        two=1;
    }
    else if(a==9)
    {
        two=1;
        three=1;
        six=1;
        eight=2;
        zero=1;
    }
    else if(a==10)
    {
        zero = 2;
        two = 1;
        three = 1;
        six = 1;
        eight = 2;
    }
    else if(a==11)
    {
        three=1;
        nine=2;
        six=6;
        eight=1;
        zero=2;
    }
    else if(a==12)
    {
        four=1;
        seven=1;
        one=1;
        six=1;
        zero=4;
    }
    else if(a==13)
    {
        six=1;
        two=3;
        zero=4;
        eight=1;
        seven=1;
    }
    else if(a==14)
    {
        eight=2;
        seven=2;
        one=2;
        two=2;
        zero=2;
        nine=1;
    }
    else if(a==15)
    {
        eight=1;
        seven=2;
        one=1;
        zero=3;
        three=3;
        six=2;
        four=1;
    }
    else if(a==16)
    {
        eight=4;
        seven=1;
        one=2;
        two=3;
        zero=4;
        nine=2;
    }
    else if(a==17)
    {
        eight=2;
        seven=1;
        zero=4;
        nine=1;
        three=1;
        five=2;
        six=2;
        four=1;
    }
    printf("0 : %d\n",zero);
    printf("1 : %d\n",one);
    printf("2 : %d\n",two);
    printf("3 : %d\n",three);
    printf("4 : %d\n",four);
    printf("5 : %d\n",five);
    printf("6 : %d\n",six);
    printf("7 : %d\n",seven);
    printf("8 : %d\n",eight);
    printf("9 : %d\n",nine);

    return 0;
}
