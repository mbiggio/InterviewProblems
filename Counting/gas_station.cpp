#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int n = gas.size();
       int start = 0;
       int end = 0;
       int gas_left = 0;
       int it = 0;
       while(it < n) {
          if (gas_left + gas[end] - cost[end] >= 0) {
             gas_left += gas[end] - cost[end];
             end++;
             end %= n;
          } else {
             start--;
             start = (start+n)%n;
             gas_left += gas[start] - cost[start];
          }
          it++;
       }
       if (gas_left >= 0) return start;
       else return -1;              
    }
};

int main() {
   Solution sol;
   vector<int> gas = {4,5};
   vector<int> cost = {5,4};
   cout << sol.canCompleteCircuit(gas,cost) << endl;
   return 0;
}
