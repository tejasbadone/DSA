#include <bits/stdc++.h>
using namespace std;

// Bruteforce - Use nested for loop, one starts with 0 and second starts with i+1.
//              T.C. -> O(n*n), S.C. -> O(1)


// Better - Using Hashing, use map as hash table <int, int> to store array element and its index here the key will be arr[i] and value is its index.
//          get the remaining ie rem = target - arr[i] and check if the rem is present in the hashmap. if it does return its value(rem is acting as key for map)
//          else store arr[i] in the map and i++.

//          OPTIMAL IF RETURNING ITS INDEXES

//          TC -> unordered map -> O(n*n)), 
//          SC-> O(n)


// Optimal -   start left=n and right=n-1. sort arr. while(left<right) get the sum of left and right and if the sum==target, return 'YES'. 
//             else if sum<target left++
//             else right--;
//              T.C. -> O(n) + nlogn , S.C. -> O(1) (if considering the array's distortion/modification the O(n)) 



    vector<int> twoSumBrute(vector<int> &arr, int n, int target)
    {
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((arr[i] + arr[j]) == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    // OR return "YES"
                }
            }
        }
        return ans;
    }


    // Optimal if you want to return its indexes
    vector<int> twoSumBetter(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mpp;
        for(int i=0; i<n; i++){
            int a = nums[i];
            int rem = target - a;
            if(mpp.find(rem) != mpp.end()){
                return {mpp[rem], i};
            }
            mpp[a] = i;

        }
        return {}; // or return {-1,-1}
    }

    // Optimal for returning YES or NO only!
    String twoSumOptimal(vector<int> &arr, int n, int target)
    {
        int left=0, right=n-1;
        sort(arr.begin(), arr.end());
        while(left<right){
        
            int sum = arr[left] + arr[right];
            if(sum == target){
                return "YES"
            }
            else if(sum < target){
                left++;
            }
            else{
                right--;
            }
        
        }
        return "NO";

    }

    vector<int> twoSumYourSol(vector<int> &arr, int n, int target)
    {
        int i=0;
        int j=1;
        while(i< n-1 && j < n){
            if((nums[i] + nums[j]) == target){
                return {i,j};
            }
            if(j==n-1){
                i++;
                j=i;
            }
            j++;
        }
        return {-1,-1};
    }



int main(){
    int n;
    cin >> n;
    vector <int> arr;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

   twoSumBetter(arr, n, 9);

    // for(int i = 0; i < n; i++)
    // {
        
    //     cout << arr[i];
    // }

    return 0;
}