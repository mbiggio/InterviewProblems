#include <iostream>
#include <stdint.h>
#include <stdio.h>
using namespace std;
#define LENGTH (32)

/*
Reverse a 32-bit unsigned int
*/

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    for(int i=0; i<LENGTH/2; i++) {
      if (((n&(1<<i))>>i) != ((n&(1<<(LENGTH-i-1)))>>(LENGTH-i-1)) ) {
	n^=(1<<i)|(1<<(LENGTH-i-1));
      }
    }
    return n;
  }
};

int main() {
  uint32_t n;
  Solution sol;
  cin>>n;
  cout << n << endl;
  cout << sol.reverseBits(n) << endl;
  return 0;
}
