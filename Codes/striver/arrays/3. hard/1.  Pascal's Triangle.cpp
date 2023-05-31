#include <bits/stdc++.h>
using namespace std;

//  Three types of questions could be asked on this pascal's triangle
// 1. Given an Row and Column no, return element at that place
// 2. Print any nth row of pascal triangle
// 3. Given n print the entire triangle.

// Bruteforce - 1. using a formula nCr ie (n! / r! * (n-r)!). create a fun which takes two ints, n and r ir row and col. 
//              running a loop till r and getting ans in res variable. res = res * (n-i); res = res/(i+1); 
//              TC -> O(r), SC -> O(1)

// Better - 2. declaring a ll ans=1 and pushing that in vector<int>ansRow. now, running a for loop (i=1 -> n), then
//              ans = ans * (n-i); ans = ans/(i); and push ans in ansRow or just print ans accoring to the question.
//              if just asked to print row - TC ->O(n) , SC - > O(1)
//              if asked to return a arr - TC->O(n), SC->O(n)
//              

//  Optimal - 3. Brute - Using nested for loops, first loop for(row=0 -> row< n) and inside declare a temp vector. the inner
//              for loop for(col=1 -> <row). inside inner loop code calculates the binomial coefficient for the given position in the
//              row using the nCrBrute() function (temp.push_back(nCrBrute(row-1, col-1));) and after this loop, using another
//              loop to store temp elements in ans and returning it.
//              TC -> O(n*n*r) -> ~_ O(n3), SC - > O(n)


//              3. Optimal - Using a function. 2nd Q's fun and in main fun using a for loop (i=1 -> <= n) and pushing it in
//              vector<vector<int>> ans by ans.push_back(generateRows(i)); and returning ans.
//              TC -> O(n2), SC - > O(n2)




// 1. get element from given row and column.
int nCrBrute(int n, int r){
    long long ans;

    for(int i=0; i<r;i++){
        ans = ans * (n-i);
        ans = ans / (i+1);
    }
    return ans;
}

//  2. Print any nth row of pascal triangle
    vector<ll> nthRowOfPascalTriangle(int n) {
        long long ans=1;
        vector<ll> ansRow;
        ansRow.push_back(1);
        
        for(int i=1;i<n; i++){
            ans = ans * (n-i);
            ans = ans/(i);
            ansRow.push_back(ans);
            // cout << ans << " ";
        }
        return ansRow;
    }


//  3. Print pascal's triangel from given n 
    vector<vector<int>> generateBrute(int n){
        vector<int> ansRow;

        for(int rows = 0; rows < n; rows++){
            vector<int> temp;
            for(int col=1; col<rows; col++){
                temp.push_back(nCrBrute(row-1, col-1));
            }
            for(int i = 0; i < temp.size(); i++)
            {
                ansRow.push_back(temp[i]);
            }
            
        }
        return ansRow;
    }



    vector<int> generateRows(int row){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);

        for(int col = 1; col < row; col++){
            ans = ans * (row-col);
            ans = ans/(col);
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++){
            ans.push_back(generateRows(i));
        }
        return ans;
    }



