#include <bits/stdc++.h>
using namespace std;


//  Optimal - declaring four ints(left=0, right=n-1, top=0 & bottom = m-1). traversing in spiral way while(top<=bottom && left <= right)
//            1. left -> right then top++, for(i=left -> <= right) top++
//            2. top -> bottom then right--, for(i = top -> <=bottom) right--
//            3. if(top<=bottom) then right -> left then bottom--, for(i = right -> left, i--) bottom --
//            4. if(left <= right) bottom -> top then left++, for(i=bottom -> <= top, i--) left++
//              TC -> O(n*m), SC - > O(n*m)


    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m-1;
        int top = 0, bottom = n-1;
        vector<int> ans;

        while(top <= bottom && left <= right  ){
            for(int i=left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top; i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            
            if(top <= bottom){
                for(int i = right; i>= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i = bottom; i>= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }

    // GFG - Dont store matrix, just traverse and find element at given spiral index, if yes then return element at that index.
    int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        int left=0, right = m-1;
        int top = 0, bottom = n-1;
        int ans = -1, j =1;
        
        while(top <= bottom && left <= right){
            for(int i=left; i<= right; i++){
                if( j == k){
                    ans = a[top][i];
                }
                j++;
            }
            top++;
            for(int i = top; i<= bottom; i++){
                if(j==k){
                    ans= a[i][right];
                }
                j++;
            }
            right--;
            if(top <= bottom){
                for(int i= right; i>= left; i--)  {
                    if(j==k){
                        ans = a[bottom][i];
                        
                    }
                    j++;
                }
                bottom--;
            }
            if(left<=right){
                for(int i = bottom; i>= top; i--){
                    if(j==k){
                        ans  = a[i][left];
                    }
                    j++;
                }
                left++;
            }
        }
        return ans;
    }
