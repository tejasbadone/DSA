#include <bits/stdc++.h>
using namespace std;


// Bruteforce - Obtain the size of the input matrix and Create a new matrix vector<vector<int>> ans(n, vector<int>(n)). 
//              Iterate through the elements of the input matrix using two nested loops, For each element at position (i, j)
//              in the input matrix, assign its value to the corresponding position (j, n-1-i) in the new matrix ans. This
//              transformation effectively rotates the element clockwise by 90 degrees. return ans.
//              TC -> O(n2), SC -> O(n2)

//  Optimal - Transpose(converting rows into cols) the matrix by swapping the elements across its main diagonal. Iterate through the
//           matrix using two nested loops for(i=0 -> n-1) and for(j=i+1 -> n).Swap the element at position (i, j) with the element
//           at position (j, i) ie swap(matrix[i][j], matrix[j][i]), swapping element dosent affect diagonal of matrix it remains same. 
//           Reverse each row of the matrix using a for loop. (reverse(matrix[i].begin(), matrix[i].end());).
//              TC -> O(n/2 * n/2) + O(n*n/2) -> O(n2), SC - > O(1)


    vector<vector<int>> rotateBrute(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));

        for(int i = 0; i<n; i++){
            for(int j=0; j<m;j++){
                ans[j][n-1-i] = matrix[i][j];
            }
        }

        for(int i = 0; i<n; i++){
            for(int j=0; j<m;j++){
                matrix[i][j] = ans[i][j];
            }
        }
        return ans;


    }

    void rotateOptimal(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }

    // GFG - Rotate array by 90 anticlockwise
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        int m = matrix[0].size();
        for(int i=0; i<n-1;i++) {
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n; j++){
                swap(matrix[i][j], matrix[n-1-i][j]);
            }
            
        }
    } 
