#include <vector>
#include <unordered_map>
#include <functional>
#include <iostream>
#include <list>
using namespace std;

/*
Dynamic programming algorithm to find the longest common subsequence (lcs)
of two arrays of chars.
The present solution uses memoization and has worst-case complexity O(mn),
where n is the length of v1 and m is the length of v2.
Space complexity is O(mn).
*/

struct pair_hash {
   size_t operator () (const pair<int,int> &p) const {
        auto h1 = hash<int>{}(p.first);
        auto h2 = hash<int>{}(p.second);
        return h1^h2;  
    }
};

list<char> lcs;
unordered_map<pair<int,int>,int,pair_hash> m;
vector<char> v1;
vector<char> v2;

int lcs_length(int i, int j) {
   if (i == -1 || j == -1) return 0;
   auto p = make_pair(i,j);
   if (m.find(p) == m.end()) {
      if (v1[i] == v2[j]) m[p] = lcs_length(i-1,j-1) + 1;
      else m[p] = max(lcs_length(i,j-1),lcs_length(i-1,j));
   }
   return m[p];
}

void reconstruct() {
   int i = v1.size()-1;
   int j = v2.size()-1;
   while (i >= 0 && j >= 0) {
      if (v1[i] == v2[j]) {
         lcs.push_front(v1[i--]);
         j--;
      }
      else if (lcs_length(i,j-1) > lcs_length(i-1,j)) j--;         
      else i--;
   }
}

void dump_list(list<char> &l) {
   for (auto c:l) cout << c << " ";
   cout << endl;
}

int main() {
   v1 = {'A','B','C','B','D','A','B'};
   v2 = {'B','D','C','A','B','A'};
   cout << lcs_length(v1.size()-1,v2.size()-1) << endl;
   reconstruct();
   dump_list(lcs);
   return 0;
}
