#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        if (cols == 0) return 0;        
        
        int max_so_far = 0;
        /* cache initialization */
        vector<vector<int>> max_square(rows,vector<int>(cols));
        for (int i=0; i<rows; i++) {
            max_square[i][0] = (matrix[i][0] == '1')?1:0;
            max_so_far = max(max_so_far,max_square[i][0]);
        }
        for (int j=0; j<cols; j++) {
            max_square[0][j] = (matrix[0][j] == '1')?1:0; 
            max_so_far = max(max_so_far,max_square[0][j]);            
        }
        
        /* bottom-up calculation of optimal solution */
        for (int i=1; i<rows; i++) {
            for (int j=1; j<cols; j++) {
                if (matrix[i][j] == '1') {
                    max_square[i][j] = 1+min(max_square[i-1][j-1],min(max_square[i-1][j],max_square[i][j-1]));
                    max_so_far = max(max_so_far,max_square[i][j]);
                }
            }
        }
        return max_so_far*max_so_far;
    }
};

int main() {
  Solution sol;
  vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                 {'1','0','1','1','1'},
                                 {'1','1','1','1','1'},
                                 {'1','0','0','1','0'}};
  cout << sol.maximalSquare(matrix) << endl;
  return 0;
}
