#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Given a string S and a string T, count the number of distinct subsequences of T in S (Leetcode).
*/

class Solution {
public:
    int numDistinct(string &s, string &t) {
        
        /* s is the "big" string 
           t is the "little string "*/
        
        int n = s.size();
        int m = t.size();
        
        if (n<m) return 0;
        vector<vector<int>> mem(n+1,vector<int>(m+1,0));
        
        /* Initialization */
        for (int i=0; i<n+1; i++) mem[i][0] = 1;
        for (int i=1; i<m+1; i++) mem[0][i] = 0;
        
        /* bottom-up solution */
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (s[i-1] == t[j-1]) mem[i][j] += mem[i-1][j-1];
                mem[i][j] += mem[i-1][j];
            }
        }
        
        return mem[n][m];

    }
};

int main() {
   Solution sol;
   string s = "rabbbit";
   string t = "rabbit";
   cout << sol.numDistinct(s,t) << endl;
   return 0;
}
