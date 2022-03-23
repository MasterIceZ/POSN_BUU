#include <stdio.h>
#include <math.h>

int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		double hs, ks, rs, hb, kb, rb;
		scanf("%lf %lf %lf %lf %lf %lf", &hs, &ks, &rs, &hb, &kb, &rb);
		double dist = sqrt((hs - hb) * (hs - hb) + (ks - kb) * (ks - kb));
		// swap b <-> s
		double swp;
	
		if(rb > rs){
			// h
			swp = hs;
			hs = hb;
			hb = swp;
			// k
			swp = ks;
			ks = kb;
			kb = swp;
			// r
			swp = rs;
			rs = rb;
			rb = swp;
		}
	
		if(rs > dist){
			if(rb + dist == rs){
				printf("One");
			}
			else if(dist + rb < rs){
				printf("None");
			}
			else{
				printf("More");
			}
		}
		else{
			if(rs + rb == dist){
				printf("One");
			}
			else if(dist > rs + rb){
				printf("None");
			}
			else{
				printf("More");
			}
		}
		printf("\n");
	}
	return 0;
}
