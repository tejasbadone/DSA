#include <bits/stdc++.h>
using namespace std;


// Bruteforce - iterating through matrix using nested for loops and making each 0's row and column to -1(if(arr[i][j] == 0)). creating 
//             another functions to make row and columns and then iterating one last time again to make all -1 to 0.
//              TC -> O(n*m) * O(n+m) + O(n*m) -> ~_ O(n3), SC -> O(1)

//  Better - Using hashing. creating 2 hash arrays of size n & m and initializing both w/ all 0's. run a for loop and check if the element 
//           is 0, then mark that particular index as 1 in hash arrays(ie we have to make this row and col as 0's). and iterate again in
//           matrix and wherever the element is 1 in hash, mark that row and col to 0.   
//              TC -> O(2*n*m), SC - > O(n)+O(m)

// Optimal - Instead of using extra space for hashing we are using first row and first col of matrix as hash and a col0 var instead of arr[0][0]
//           using arr[0][0] will modify the ans matrix.
//           The code iterates through the matrix, and if an element is zero (arr[i][j] == 0), it marks the corresponding row (arr[i][0])
//           and column (arr[0][j]) by setting them to zero. A separate variable col0 is used to track if the first column (arr[0][0])
//           should be set to zero. Then, a second iteration is performed from i = 1 and j = 1 to make all elements zero except for the 
//           first row and the first column(so that ans matrix wont change). If either arr[0][j] or arr[i][0] is zero, it sets arr[i][j] to zero. 
//          Finally, the code checks if arr[0][0] is zero, and if so, it sets the entire first row to zero. Additionally, if col0 is zero,
//          it sets the entire first column to zero.
//             TC -> O(2*n*m), SC -> O(1)


    void makeRow(vector<vector<int>>& arr ,int i, int m){
        for(int j=0; j<m; j++){
            if(arr[i][j] != 0){
                arr[i][j] = -1;
            }
        }
    }

     void makeCol(vector<vector<int>>& arr, int j, int n){
        for(int i=0; i<n; i++){
            if(arr[i][j] != 0){
                arr[i][j] = -1;
            }
        }
    }
    
    void setZeroesBrute(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                if(arr[i][j] == 0){
                    makeRow(arr, i, m);
                    makeCol(arr, j, n);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == -1){
                    arr[i][j] = 0;
                }
            }
        }
    }


    void setZerosBetter(vector<vector<int>>& arr){
        int n = arr.size();
        int m = arr[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == 0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(row[i] == 1 || col[j] == 1){
                    arr[i][j] = 0;
                }
            }
        }
    }


    void setZeroesOptimal(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int col0=1;

        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(arr[i][j] == 0){
                    //marking i-th row
                    arr[i][0] = 0;

                    //marking j-th col
                    if(j != 0){
                        arr[0][j]= 0;
                    }else{
                        col0=0;
                    }
                }
            }
        }

        // making elements 0 except 0th row and 0th col, cause making it 0 at start will modify ans array. 
        for(int i=1; i<n; i++){
            for(int j=1; j<m;j++){
                if(arr[0][j] == 0 || arr[i][0] == 0){
                    arr[i][j] = 0;
                }
            }
        }

        // making 0th row 0
        if(arr[0][0] == 0){
            for(int j=0; j<m;j++){
                arr[0][j] = 0;
            }
        }
        // making 0th col 0
        if(col0 == 0){
            for(int i=0; i<n; i++){
                arr[i][0] =0;
            }
        }
    }

