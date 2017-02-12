#include <iostream>
#include <vector>
using namespace std;

/*
Wildcard matching with special characters '?' and '*'
*/

class Solution {
public:
    vector<vector<int>> mem;
    bool isMatch(string s, string p) {
        mem = vector<vector<int>>(s.size()+1,vector<int>(p.size()+1,-1));
        return match(s,s.size(),p,p.size());
    }
    
    bool match(string &s, int m, string &p, int n) {
        if (mem[m][n] == -1) {
            if (m==0 && n==0) mem[m][n] = 1;
            else if (n==0) mem[m][n] = 0;
            else if (m==0) mem[m][n] = (p[n-1]=='*' && match(s,m,p,n-1))?(1):(0);
            else {
                mem[m][n]=0;
                if (p[n-1]=='?' || s[m-1]==p[n-1] ) mem[m][n] = (match(s,m-1,p,n-1))?(1):(0);
                else if (p[n-1]=='*') mem[m][n] = (match(s,m-1,p,n) || match(s,m,p,n-1))?(1):(0);
            }
        }
        return (mem[m][n]==1);
    }
};

int main() {
   Solution sol;
   cout << sol.isMatch("aa","*") << endl;
   return 0;
}
