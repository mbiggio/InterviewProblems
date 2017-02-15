#include <vector>
#include <functional>
#include <unordered_map>
#include <iostream>
using namespace std;

/*
Return true if we can partition an array in two subsets, each having sum=tot_sum/2 (leetcode)
*/

class Solution {
public:

   struct key{
      int size;
      int target;
      key(): size(0), target(0) {};      
      key(int size, int target): size(size), target(target) {};
      bool operator==(const key &other) const {
         return (size==other.size && target==other.target);
      }
   };
   struct hash_key{
      size_t operator()(const key &x) const{
         return std::hash<int>()(x.size) ^ std::hash<int>()(x.target);
      }
   };   
   
   bool canPartition(vector<int>& nums) {
      int n=nums.size();
      int sum=0;
      for (auto i:nums) sum+=i;
      if (sum%2) return false;
      unordered_map<key,int,hash_key> mem;
      return canPartition_target(mem,nums,n,sum/2);
   }

   bool canPartition_target(unordered_map<key,int,hash_key> &mem,
                            vector<int>& nums,
                            int size,
                            int target) {
      key k(size,target);
      if (mem.find(key(size,target)) == mem.end()) {
         if (size==0 && target==0) mem[k]=1;
         else if (size==0 || target==0) mem[k]=0;
         else {
            if (canPartition_target(mem,nums,size-1,target)) {
               mem[k]=1;
            } else if (target-nums[size-1]>=0 && canPartition_target(mem,nums,size-1,target-nums[size-1])) {
               mem[k]=1;
            } else {
               mem[k]=0;
            }
         }
      }
      return (mem[k]==1);
   }
};

int main() {
  Solution sol;
  return 0;
}
