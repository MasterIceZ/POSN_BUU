/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * LANG		: C++
 * TASK		: 
 * EDITOR	: VsCode
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solution(){
		int q;
	scanf("%d",&q);
	while(q--){
		double x1,x2,y1,y2,r1,r2;
		scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);
		double dist = sqrt(pow(x1-x2, 2) + pow(y1-y2,2));
		if(dist > r1+r2){
			printf("None");
		}	
		else if(x1 == x2 && y1 == y2 && r1 == r2){
			printf("More");
		}
		else if(dist < r1 && dist+r2 == r1){
			printf("One");
		}
		else if(dist < r2 && dist+r1 == r2){
			printf("One");
		}
		else if(dist < r1 && dist+r2 < r1){
			printf("None");
		}
		else if(dist < r2 && dist+r1 < r2){
			printf("None");
		}
		else if(dist < r1+r2){
			printf("More");
		}
		else if(dist == r1+r2 || dist+r1 == r2 || dist+r2 == r1){
			printf("One");
		}
		else{
			printf("None");
		}
		printf("\n");
	}

	return ;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
//	cin >> t;
	for(int i=1; i<=t; ++i){
//		cout << "Case #" << i << ": ";
		solution();
//		cout << endl;
	}
	return 0;
}
