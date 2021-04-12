#include <stdio.h>
#include <math.h>

int main(){
    double X1,Y1,X2,Y2,X3,Y3,K,a,b,c,s;
    scanf("%lf %lf %lf %lf %lf %lf %lf",&X1,&Y1,&X2,&Y2,&X3,&Y3,&K);
    a = sqrt( pow(X1-X2,2)+pow(Y1-Y2,2));
    b = sqrt( pow(X2-X3,2)+pow(Y2-Y3,2));
    c = sqrt( pow(X1-X3,2)+pow(Y1-Y3,2));
    s = (a+b+c)/2;
    printf("%.2lf",sqrt(s*(s-a)*(s-b)*(s-c)));
    printf("\n%.2lf",K*(a+b+c)+M_PI*K*K);
    return 0;
}
