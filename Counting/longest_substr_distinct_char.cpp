#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

/*
Find the longest substring containing k distinct characters
*/

pair<int,int> longest_substr(const string &s, int k) {

   int n = s.size();
   unordered_map<char,int> map;
   int start_idx = 0, end_idx = 0;

   /* find the first substring with k distinct chars or return null */
   while (end_idx < n && map.size() < k) {
      map[s[end_idx++]]++;
   }
   if (end_idx == n) return make_pair(-1,-1);   
   pair<int,int> max = make_pair(start_idx,end_idx-1);

   /* find possibly longer substrings */   
   for (; end_idx < n; end_idx++) {
      map[s[end_idx]]++;
      while (map.size() > k) {
         map[s[start_idx]]--;
         if (map[s[start_idx]] == 0) {
            map.erase(s[start_idx]);
         }
         start_idx++;
      }
      if (max.second - max.first < end_idx - start_idx) {
         max = make_pair(start_idx,end_idx);
      }
   }
   return max;
}

int main() {
   string s;
   pair<int,int> max;

   /* test 1 */
   s = "aaaabbbb";
   max = longest_substr(s,2);
   cout << "(" << max.first << "," << max.second << ")" << endl;

   /* test 2 */
   s = "asdfrtttff";
   max = longest_substr(s,3);   
   cout << "(" << max.first << "," << max.second << ")" << endl;

   /* test 3 */
   s = "asdfrtttffssssss";
   max = longest_substr(s,3);   
   cout << "(" << max.first << "," << max.second << ")" << endl;

   /* test 4 */
   s = "";
   max = longest_substr(s,3);   
   cout << "(" << max.first << "," << max.second << ")" << endl;      
   
   return 0;
}
