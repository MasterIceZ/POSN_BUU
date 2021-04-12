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
	int a;
	cin >> a;
	for(int i=1;i<=a;++i){
		printf("%d ", i);
	}
	printf("\n");
	int it = a;
	while(it>0){
		printf("%d ",it);
		it--;
	}
	printf("\n");
	it=1;
	do{
		if(it%2==0){
			printf("%d ",it);
		}
		it++;
	}while(it <= a);
	printf("\n");
	for(int i=a;i>0;--i){
		if(i%2==0){
			printf("%d ", i);
		}
	}
	printf("\n");
	it = 1;
	while(it<=a){
		if(it%2==1){
			printf("%d ",it);
		}
		it++;
	}
	printf("\n");
	it = a;
	do{
		if(it%2==1){
			printf("%d ", it);
		}
		it--;
	}while(it>=1);
	
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
