#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
Find if a given string can be decomposed in words belonging to a given dictionary of words
*/

unordered_set<string> dict;

int words_in_sentence(const string &s, int i, unordered_map<int,int> &mem) {
   int n = s.size();
   if (i >= n) return n;   
   if (mem.find(i) == mem.end()) {
      mem[i] = -1;
      for (int j = i; j < n; j++) {
         if (dict.find(s.substr(i,j-i+1)) != dict.end() && words_in_sentence(s,j+1,mem) != -1) {
            mem[i] = j+1;
            break;
         }
      }
   }
   return mem[i];
}

vector<string> words(const string &s) {
   int n = s.size();
   unordered_map<int,int> mem;
   vector<string> v;
   if (words_in_sentence(s,0,mem) != -1) {
      int i=0;
      while (i!=n) {
         v.push_back(s.substr(i,mem[i]-i));
         i = mem[i];
      }
   }
   return v;
}

void print_vector(vector<string> &v) {
   for (auto s:v) {
      cout << s << " ";
   }
   cout << endl;
}

int main() {

   dict.insert("pippo");
   dict.insert("topolino");
   dict.insert("topo");
   dict.insert("lino");
   vector<string> v;

   v = words("topolinopippotopolino");
   print_vector(v);

   v = words("opolinopippotopolino");
   print_vector(v);

   v = words("11");
   print_vector(v);   

   return 0;
}
