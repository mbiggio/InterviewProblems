#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
We are given an array B[1..n] of integers greater than or equal to 1.
We must return an array A of integers such that:
   1 <= A[i] <= B[i]
   sum_{i=2}^{n} |A[i] - A[i-1]| is maximized
 */

int sherlock_and_cost(const vector<int> &A) {

  int n = A.size();  

  /* Initialize cache */
  vector<vector<int>> m(n,vector<int>(2));

  /* Iteratively compute optimal solution */
  for (int i=1; i<n; i++) {
    m[i][0] = max(m[i-1][0], m[i-1][1] + A[i-1] - 1);
    m[i][1] = max(m[i-1][0] + A[i] - 1, m[i-1][1] + abs(A[i]-A[i-1]) );
  }

  /* return best of two final values */
  return max(m[n-1][0],m[n-1][1]);
}


int main() {
  int T;
  int size;
  vector<int> A;

  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> size;
    for (int j=0; j<size; j++) {
      int el;
      cin >> el;
      A.push_back(el);
    }
    cout << sherlock_and_cost(A) << endl;
    A.clear();
  }

  return 0;
}
