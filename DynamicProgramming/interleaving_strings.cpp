#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
Check if a string s3 is an interleaving of strings s1 and s2
*/

class Solution {
public:

   vector<vector<int>> m;

   bool isInterleave(string s1, string s2, string s3) {
      if (s1.size() + s2.size() != s3.size()) return false;
      if (s1.size() == 0) return s2 == s3;
      if (s2.size() == 0) return s1 == s3;
      m = vector<vector<int>>(s1.size()+1,vector<int>(s2.size()+1,-1));
      return interleave(s1,0,s2,0,s3,0);
   }
    
   bool interleave(string &s1, int i1, string &s2, int i2, string &s3, int i3) {

      if (m[i1][i2] == -1) {
         int n1 = s1.size();
         int n2 = s2.size();
         int n3 = s3.size();
         if (i1 == n1 && i2 == n2) m[i1][i2] = 1;
         else if (i1 < n1 && s1[i1] == s3[i3] && interleave(s1,i1+1,s2,i2,s3,i3+1)) m[i1][i2] = 1;
         else if (i2 < n2 && s2[i2] == s3[i3] && interleave(s1,i1,s2,i2+1,s3,i3+1)) m[i1][i2] = 1;
         else m[i1][i2] = 0;
      }
      return (m[i1][i2] == 1);
   }
};

int main() {
   Solution s;
   string s1,s2,s3;
   cin >> s1 >> s2 >> s3;
   cout << s.isInterleave(s1,s2,s3) << endl;
   return 0;
}
