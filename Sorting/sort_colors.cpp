#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    void dump_vector(vector<int> &nums) {
        for(auto i:nums) cout << i << " ";
        cout << endl;
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        
        for (int k=0; k<n; k++) {
            cout << "Iteration " << k << endl;
            cout << "i,j,k = " << i << j << k << endl;
            dump_vector(nums);
            if (nums[k]==0) {
                swap(nums,j,k);
                swap(nums,i,j);                
                i++;
                j++;
            }
            else if (nums[k]==1) {
                swap(nums,j,k);
                j++;
            }
        }
    }
};

int main() {
   Solution sol;
   vector<int> v = {0,0,1,0,1,1};
   sol.sortColors(v);
   return 0;
}
