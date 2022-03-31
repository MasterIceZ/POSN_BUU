#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, num, i, mx = -2e9;
    int sum = 0, st, en, s=1;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d", &num);
        sum+=num;
        if(sum > mx){
            mx = sum, en = i, st = s;
        }
        if(sum<0){
            sum = 0, s = i+1;
        }
    }
    printf("%d %d\n%d", st, en, mx);
    return 0;
}
