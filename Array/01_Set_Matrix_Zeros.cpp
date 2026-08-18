/*
LeetCode 73 - Set Matrix Zeroes

Approach:
- Use the first row and first column of the matrix as markers.
- While traversing the matrix, if a cell contains 0:
    - Mark its row by setting matrix[i][0] = 0.
    - Mark its column by setting matrix[0][j] = 0.
- Use an additional variable (col0) to track whether the first column
  should be zeroed, since matrix[0][0] is already used for row marking.
- Traverse the matrix from bottom-right and set cells to 0 based on
  the stored row and column markers.
- Finally, update the first row and first column using their markers.

Time Complexity: O(m * n)
Space Complexity: O(1)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int col0 = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;

                    if(j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        for(int i = m - 1; i > 0; i--) {
            for(int j = n - 1; j > 0; j--) {

                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // Zero first row if marked
        if(matrix[0][0] == 0) {
            for(int j = n - 1; j >= 0; j--)
                matrix[0][j] = 0;
        }

        // Zero first column if marked
        if(col0 == 0) {
            for(int i = m - 1; i >= 0; i--)
                matrix[i][0] = 0;
        }
    }
};
