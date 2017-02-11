#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
Return the length of the maximal wiggle subsequence of a vector of integers
*/

#define INC (0)
#define DEC (1)

class Solution {
public:
   int wiggleMaxLength(vector<int>& nums) {
      int n = nums.size();
      if (n==0) return 0;
      vector<vector<int>> m(2,vector<int>(n,1));
      int max_so_far = 1;
      for (int i=0; i<n; i++) {
         for (int j=0; j<i; j++) {
            if (nums[j] < nums[i]) {
               m[INC][i] = max(m[INC][i],1+m[DEC][j]);
               max_so_far = max(max_so_far,m[INC][i]);
            }
            else if (nums[j] > nums[i]) {
               m[DEC][i] = max(m[DEC][i],1+m[INC][j]);
               max_so_far = max(max_so_far,m[DEC][i]);               
            }            
         }
      }
      return max_so_far;
   }
};

int main() {
   Solution sol;
   vector<int> v = {1,17,5,10,13,15,10,5,16,8};
   cout << sol.wiggleMaxLength(v) << endl;
   return 0;
}
