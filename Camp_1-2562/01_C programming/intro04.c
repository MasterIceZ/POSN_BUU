#include<stdio.h>
	/*
		TASK: intro01
		AUTHOR: Ice
		SCHOOL: RYW
		LANG: C
	*/
int main () {
	double d,vr,vt,vf,t,delv,dis;
	scanf("%lf %lf %lf %lf",&d,&vr,&vt,&vf);
	delv = vt-vr;
	t = d/delv;
	dis = vf*t;
	printf("%.2lf",dis);
}
