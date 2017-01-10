#include <list>
#include <vector>
#include <iostream>
using namespace std;

typedef enum {
  STOP = 0,
  NUL,
  UP,
  DOWN,
  RIGHT,
  LEFT
} dir;


void dump_input(vector<vector<int>> &A, vector<int> &S) {
  cout << endl;
  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < A[0].size(); j++) {
      cout << A[i][j] << "  ";
    }
    cout << endl;
  }
  cout << endl;
  for (int i = 0; i < S.size(); i++) {
    cout << S[i] << "  ";
  }
  cout << endl << endl;
}

void dump_output(list<pair<int,int>> &l) {
  for (auto i:l) {
    cout << "(" << i.first << "," << i.second << ") ";
  }
  cout << endl;
}


bool check_neigh(vector<vector<vector<dir>>> &M,
                 int i,
                 int row,
                 int col) {

  int rows = M[0].size();
  int cols = M[0][0].size();
  if (i == 0) M[i][row][col] = STOP;
  else if (row > 0      && M[i-1][row-1][col  ] != NUL) M[i][row][col] = UP;
  else if (row < rows-1 && M[i-1][row+1][col  ] != NUL) M[i][row][col] = DOWN;
  else if (col > 0      && M[i-1][row  ][col-1] != NUL) M[i][row][col] = LEFT;
  else if (col < cols-1 && M[i-1][row  ][col+1] != NUL) M[i][row][col] = RIGHT;
  else M[i][row][col] = NUL;
}

list<pair<int,int>> seq_in_matrix(vector<vector<int>> &A, vector<int> &S) {
  int rows = A.size();
  int cols = A[0].size();
  int n = S.size();
  list <pair<int,int>> l;
  
  /* initialize the 3D matrix used for memoization */
  vector<vector<vector<dir>>> M(n);
  for (int i = 0; i < n; i++) {
    M[i] = vector<vector<dir>>(rows);
    for (int j = 0; j < rows; j++) {
      M[i][j] = vector<dir>(cols);
    }
  }

  /* pseudo-recursion  */
  for (int i = 0; i < n; i++)  {
    bool true_found = false;       
    for (int row = 0; l.empty() && row < rows; row++)  {
      for (int col = 0; l.empty() && col < cols; col++)  {
        if (A[row][col] == S[i]) {
          check_neigh(M,i,row,col);
          true_found = true_found || (M[i][row][col] != NUL);   
          if (i == n-1 && M[i][row][col] != NUL) l.push_front(make_pair(row,col));         
        } else {
          M[i][row][col] = NUL;
        }
      }
    }
    if (!true_found) return l;
  }

  /* path reconstruction */
  int i = n-1;
  int row = l.front().first;
  int col = l.front().second;
  dir d = M[i][row][col];
  while (d != STOP) {
    /* determine new indices i,row,col*/
    i--;
    switch(d) {
    case UP:
      row--;
      break;
    case DOWN:
      row++;
      break;
    case LEFT:
      col--;
      break;
    case RIGHT:
      col++;
      break;
    }
    /* push (row,col) pair in front of the list */
    l.push_front(make_pair(row,col));
    /* determine nest direction to move */
    d = M[i][row][col];
  }
  return l; 
}


int main() {

  int n,rows,cols;
  cin >> n >> rows >> cols;  
  vector<vector<int>>A(rows,vector<int>(cols));
  vector<int> S(n);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }

  dump_input(A,S);  
  list<pair<int,int>> l = seq_in_matrix(A,S);
  if (l.empty()) {
    cout << "NIL" << endl;
  } else {
    dump_output(l);
  }
  return 0;
}
