#include "coins.h"
#include <vector>

std::vector<int> coin_flips(std::vector<int> b, int c) {
  int sum_xor = 0;
  for(int i=0; i<64; ++i) {
    if(b[i] == 0) {
      continue;
    }
    sum_xor ^= i;
  }
  int flipping_pos = sum_xor ^ c;
  return { flipping_pos };
}

int find_coin(std::vector<int> b) {
  int sum_xor = 0;
  for(int i=0; i<64; ++i) {
    if(b[i] == 0) {
      continue;
    }
    sum_xor ^= i;
  }
  return sum_xor;
}
