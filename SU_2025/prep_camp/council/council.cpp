#include "council.h"

int giveAnswer(int N, int M, int Q) {
  int answer = 1, cnt = 1;
  for(int i=2; i<=N; ++i) {
    int x = sameVote(answer, i);
    if(x == 0) {
      cnt--;
    }
    else {
      cnt++;
    }
    if(cnt < 0) {
      cnt = 1;
      answer = i;
    }
  }
  return answer;
}