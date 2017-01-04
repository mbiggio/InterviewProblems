#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 
given an array with a series of stock prices over days,
determine the maximum profit that can be made by 
buying and selling a stock 
*/
int sell_and_buy(vector<int> &v) {
  if (v.size() == 0) return 0;
  int profit = 0;
  int cur_min = v[0];
  for (int i = 1; i < v.size(); i++) {
    if (v[i]-cur_min > profit) {
      profit = v[i]-cur_min;
    }
    cur_min = (v[i]<cur_min)?v[i]:cur_min;
  }
  return profit;
}

int main() {
  vector<int> v(10);

  /* test 1 */
  v = {0,1,2,3,4,5,6,7,8,9};
  cout << "max profit: " << sell_and_buy(v) << endl;
  /* test 2 */
  v = {9,8,7,6,5,4,3,2,1,0};
  cout << "max profit: " << sell_and_buy(v) << endl;

  return 0;
}
