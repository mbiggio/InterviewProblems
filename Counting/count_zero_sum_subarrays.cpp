#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Let v be an array of +1s and -1s.
Count the number of distincs zero-sum consecutive sub-arrays.
*/

int count_zero_sum_subarr(const vector<int> &v) {
   int n = v.size();
   unordered_map<int,int> m;
   int sum = 0, arrays = 0;
   m[sum]++;
   for (int i=0; i<n; i++) {
      sum += v[i];
      m[sum]++;
   }
   for (auto p:m) {
      arrays += p.second*(p.second-1)/2;
   }
   return arrays;
}

int main() {

   vector<int> v;
   
   /* test 1 */
   v = {-1,1,-1,1};
   cout << count_zero_sum_subarr(v) << endl;
   v.clear();

   /* test 2 */
   v = {-1,-1,1,1};
   cout << count_zero_sum_subarr(v) << endl;
   v.clear();

   /* test 2 */
   v = {};
   cout << count_zero_sum_subarr(v) << endl;
   v.clear();     

   /* test 3 */
   v = {1,1,1,1,1};
   cout << count_zero_sum_subarr(v) << endl;
   v.clear();  
   
   return 0;
}
