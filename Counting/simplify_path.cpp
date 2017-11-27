#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void construct_output(string &str, stack<string> &s) {
   if (s.size() == 0) return;
   string tmp = s.top();
   s.pop();
   construct_output(str,s);
   str += '/';
   str += tmp;
}

class Solution {
public:
   string simplifyPath(string path) {
      int n = path.size();
      if (n<=1) return "/";
      int i = 1;
      stack<string> s;
      while(i<n) {
         string str;
         while(i<n && path[i]!='/') {
            str+=path[i];
            i++;
         }
         if (str == ".." && s.size() != 0) {
            s.pop();
         } else if (str != "." && str != "" && str != "..") {
            s.push(str);
         }
         i++;
      }

      if (s.size() == 0) return "/";
      string str;
      construct_output(str,s);
      return str;
   }
};


int main() {
   string s;
   Solution sol;
   cin >> s;
   cout << sol.simplifyPath(s) << endl;
   return 0;
}
