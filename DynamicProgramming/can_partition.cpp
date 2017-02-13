#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
    for (auto i:nums) sum+=i;
    if (sum%2) return false;
    vector<vector<int>> mem(n+1,vector<int>(sum/2+1,-1));
    return canPartition_target(mem,nums,n,sum/2);
  }

  bool canPartition_target(vector<vector<int>> &mem, 
                           vector<int>& nums, 
                           int size, 
                           int target) {
    if (mem[size][target] == -1) {
      if (size==0 && target==0) mem[size][target]=1;
      else if (size==0 || target==0) mem[size][target]=0;
      else {
	if (canPartition_target(mem,nums,size-1,target)) {
	  mem[size][target]=1;
        } else if (target-nums[size-1]>=0 && canPartition_target(mem,nums,size-1,target-nums[size-1])) {
	  mem[size][target]=1; 
	} else {
	  mem[size][target]=0;
	}
      }
    }
    return (mem[size][target]==1);
  }

};

int main() {
  Solution sol;
  return 0;
}
