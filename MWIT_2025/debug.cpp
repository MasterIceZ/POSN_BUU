#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K,i,j=0,k=0,l,ck=0,sum=0,pp=0;
  string nb;
  cin >> N >> K >> nb;
	
    
  stack<pair<char,int>> s;
   
   while (pp != K){
      if (ck==0){
          for(i=0;i<K+sum;i++){
            while(i >= nb.size()) cout << "Hello\n";
              if (!s.empty()){
                  s.push({nb[i],i});
				  continue;
              }
              while (i + 1 >= nb.size() || s.empty()) {
                cout << "Hey\n";
              }
              if (nb[i+1]>nb[i]){
				  
                  s.pop();
                  pp += 1;
                  s.push({nb[i+1],i+1});
				  continue;
              }
              if (pp == K){
                  for (j = s.top().second + 1;j<N;j++){
                    while(j >= nb.size()) cout << "XXX\n";
                      s.push({nb[j],j});
                  }
                  break;
              }
          }
          if (pp == K)
            break;
      }
    }

    while(1) {
      cout << "Y\n";
    }



	//   while(!s.empty()) {
	// 	  cout << "Hello World\n";
	//   }
       
  //     ck += 1;
  //     sum += 1;
  //     j = int(s.top().second)-'0'+1;
       
  //     for ( ;j<K+sum;j++){
  //           if (nb[j+1]>nb[j]){
  //             s.pop();
  //             pop += 1;
  //             s.push({nb[j+1],j+1});
  //           }
  //           if (pop == K){
  //             for (j = s.top().second + 1;j<N;j++){
  //                 s.push({nb[j],j});
  //             }
  //             break;
  //           }
  //     }
  //  }
   
  //   stack<char> temp;   
  //   while(!s.empty()){
  //       temp.push(s.top().first);
  //       s.pop();
  //   }
  //   while (!temp.empty()){
  //       cout << temp.top();
  //       temp.pop();
  //   }
}
