#include <iostream>
#include <vector>
using namespace std;

/*
Longest increasing (consecutive) subsequence of an array
*/

pair<int,int> lis(const vector<int> &v) {
   int n = v.size();
   pair<int,int> lis = make_pair(0,0);
   pair<int,int> cis = make_pair(0,0);
   for (int i=1; i<n; i++) {
      if (v[i] <= v[i-1])
         cis.first = i;
      cis.second = i;
      if (cis.second-cis.first > lis.second-lis.first) {
         lis.first = cis.first;
         lis.second = cis.second;
      }
   }
   return lis;   
}

void print_pair(const pair<int,int> &p) {
   cout << "(" << p.first << "," << p.second << ")" << endl;
}

int main() {
   vector<int> v = {1, 3, 2, 3, 4, 8, 7, 9};
   print_pair(lis(v));
   return 0;
}
