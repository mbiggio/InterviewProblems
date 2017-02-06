#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
K people want to buy N flower, where cost of flower i is c_{i}
If a customer has already purchsed x flowers, then he has to pay (1+x)*c_{i}
to purchase flower i.
Find the total minimum cost to purchase all N flowers.
*/

bool wayToSort(int i, int j) { return i > j; }

int greedy_florist(const vector<int> &c, int N, int K) {
  int cost = 0;
  int factor = 0;

  for (int i=0; i<N; i++) {
    if (i%K == 0) factor++;
    cost += factor*c[i];
  }

  return cost;
  
}


int main(void){

   int N, K;
   cin >> N >> K;
   vector<int> c(N);
   for(int i = 0; i < N; i++){
      cin >> c[i];
   }
   sort(c.begin(),c.end(),wayToSort);   
   cout << greedy_florist(c,N,K) << endl;
   
   return 0;
}
