#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 10000000

/*
Dynamic programming solution to the
bitonic euclidean travelling salesman problem
*/

double dist(pair<double,double> &p1, pair<double,double> &p2) {
   return sqrt((p1.first-p2.first)*(p1.first-p2.first) +
               (p1.second-p2.second)*(p1.second-p2.second));
}

double cost(vector<pair<double,double>> &p) {
   int n = p.size();
   if (n == 1) return 0;
   vector<double> c(n);
   c[0] = 0;
   c[1] = 2*dist(p[0],p[1]);
   for (int i = 2; i < n; i++) {
      c[i] = MAX;
      double cum_dist = 0;
      for (int j = i-1; j >= 1; j--) {
         cum_dist += dist(p[j],p[j+1]);
         double tmp = c[j] - dist(p[j-1],p[j]) + cum_dist + dist(p[j-1],p[i]);
         c[i] = (c[i]>tmp)?tmp:c[i];
      }
   }
   return c[n-1];
}

int main() {
   vector<pair<double,double>> v = {make_pair(0,6),
                                    make_pair(1,0),
                                    make_pair(2,3),
                                    make_pair(5,4),
                                    make_pair(6,1),
                                    make_pair(7,5),
                                    make_pair(8,2)};
   cout << cost(v) << endl;
   return 0;
}
